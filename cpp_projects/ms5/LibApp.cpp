/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	Jagraj Singh Benipal
Student ID: 156374217
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
//#include <ctime>
#include <cstring>
#include "Menu.h"
#include "Book.h"
#include "LibApp.h"
#include "Utils.h"
//#include "Lib.h"
using namespace std;

namespace sdds
{
    bool LibApp::confirm(const char *message)
    {
        Menu mConfirm(message);
        mConfirm << "Yes";
        return mConfirm.run() == 1;
    }

    void LibApp::load()
    {
        char pubType = '\0';
        ifstream open(m_filename);
        cout << "Loading Data" << endl;
        for (int i = 0; open; i++)
        {
            open >> pubType;
            readChar(open, '\t');
            if (open)
            {
                if (pubType == 'B')
                    m_ppa[i] = new Book;
                else if (pubType == 'P')
                    m_ppa[i] = new Publication;
                if (m_ppa[i])
                {
                    open >> *m_ppa[i];
                    m_nolp++;
                }
            }
        }
        m_llrn = m_ppa[m_nolp - 1]->getRef();
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        ofstream write(m_filename);
        for (int i = 0; i < m_nolp; i++)
        {
            if (m_ppa[i]->getRef() != 0)
            {
                write << *m_ppa[i] << endl;
            }
        }
    }

    int LibApp::search(int searchMode)
    {
        // cout << "Searching for publication" << endl;
        PublicationSelector select("Select one of the following found matches:");
        int rtnSearch = 0;
        int done = 0;
        int mChoice = 0;
        char pubType = '\0';
        char pubTitle[SDDS_PUB_FNAME_LEN + 1];
        do
        {
            mChoice = m_chooseMenu.run();
            if (mChoice == 1)
            {
                pubType = 'B';
                // done = 1;
            }
            else if (mChoice == 2)
            {
                pubType = 'P';
                // done = 1;
            }
            else if (mChoice == 0)
            {
                done = 1;
                cout << "Aborted!" << endl;
            }

            if (!done)
            {
                cout << "Publication Title: ";
                cin.getline(pubTitle, SDDS_PUB_FNAME_LEN + 1, '\n');
                if (searchMode == SEARCH_ALL)
                {
                    for (int i = 0; i < m_nolp; i++)
                    {
                        if (m_ppa[i]->type() == pubType && m_ppa[i]->getRef() != 0 && *m_ppa[i] == pubTitle)
                        {
                            select << m_ppa[i];
                        }
                    }
                }
                else if (searchMode == SEARCH_LOAN)
                {
                    for (int i = 0; i < m_nolp; i++)
                    {
                        if (m_ppa[i]->type() == pubType && m_ppa[i]->onLoan() && m_ppa[i]->getRef() != 0 && *m_ppa[i] == pubTitle)
                        {
                            select << m_ppa[i];
                        }
                    }
                }
                else if (searchMode == SEARCH_NOT_LOAN)
                {
                    for (int i = 0; i < m_nolp; i++)
                    {
                        if (m_ppa[i]->type() == pubType && !m_ppa[i]->onLoan() && m_ppa[i]->getRef() != 0 && *m_ppa[i] == pubTitle)
                        {
                            select << m_ppa[i];
                        }
                    }
                }
                if (select)
                {
                    select.sort();
                    rtnSearch = select.run();
                    if (rtnSearch != 0)
                    {
                        cout << *getPub(rtnSearch);
                    }
                    else
                    {
                        cout << "Aborted!" << endl;
                    }
                }
                else
                {
                    cout << "No matches found!" << endl;
                }
                done = 1;
            }
        } while (!done);
        cout << endl;
        return rtnSearch;
    }

    void LibApp::returnPub()
    {
        int searchResult = 0;
        int loanPeriod = 0;
        int numDayLate = 0;
        Date currDate;
        cout << "Return publication to the library" << endl;
        searchResult = search(SEARCH_LOAN);
        if (searchResult != 0)
        {
            if (confirm("Return Publication?"))
            {
                loanPeriod = currDate - getPub(searchResult)->checkoutDate();
                if (loanPeriod > SDDS_MAX_LOAN_DAYS)
                {
                    numDayLate = loanPeriod - SDDS_MAX_LOAN_DAYS;
                    cout << "Please pay $" << fixed << setprecision(2) << (double)(numDayLate * 0.5);
                    cout << " penalty for being " << numDayLate << " days late!";
                    cout << endl;
                }
                getPub(searchResult)->set(0);
                m_changed = true;
                cout << "Publication returned" << endl;
                cout << endl;
            }
            else
            {
                cout << "Aborted!" << endl;
                cout << endl;
            }
        }
    }

    void LibApp::newPublication()
    {
        // int rtnSearch = 0;
        int done = 0;
        int mChoice = 0;
        Publication *addPub{};
        // char pubType = '\0';
        // char pubTitle[SDDS_PUB_NAME_LEN + 1];
        if (m_nolp == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Adding new publication to the library" << endl;
            do
            {
                mChoice = m_chooseMenu.run();
                if (mChoice == 1)
                {
                    addPub = new Book;
                    // done = 1;
                }
                else if (mChoice == 2)
                {
                    addPub = new Publication;
                    // done = 1;
                }
                else if (mChoice == 0)
                {
                    addPub = nullptr;
                    done = 1;
                    cout << "Aborted!" << endl;
                    cout << endl;
                }
                if (!done)
                {
                    if (addPub)
                    {
                        cin >> *addPub;
                        if (cin.fail())
                        {
                            delete addPub;
                            cout << "Aborted!" << endl;
                            cout << endl;
                        }
                        else if (cin)
                        {
                            if (confirm("Add this publication to the library?"))
                            {
                                if ((*addPub))
                                {
                                    m_llrn++;
                                    m_ppa[m_nolp] = addPub;
                                    m_ppa[m_nolp]->setRef(m_llrn);
                                    m_nolp++;
                                    m_changed = true;
                                    cout << "Publication added" << endl;
                                    cout << endl;
                                }
                                else
                                {
                                    delete addPub;
                                    cout << "Failed to add publication!" << endl;
                                    cout << endl;
                                }
                            }
                        }
                        else
                        {
                            delete addPub;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Aborted!" << endl;
                            cout << endl;
                        }
                    }
                    done = 1;
                }
            } while (!done);
        }
    }

    void LibApp::removePublication()
    {
        int searchResult = 0;
        cout << "Removing publication from the library" << endl;
        searchResult = search(SEARCH_ALL);
        if (searchResult != 0)
        {
            if (confirm("Remove this publication from the library?"))
            {
                getPub(searchResult)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
                cout << endl;
            }
            else
            {
                cout << "Aborted!" << endl;
                cout << endl;
            }
        }
    }

    void LibApp::checkOutPub()
    {
        int searchResult = 0;
        int memberID = 0;
        cout << "Checkout publication from the library" << endl;
        searchResult = search(SEARCH_NOT_LOAN);
        if (searchResult != 0)
        {
            if (confirm("Check out publication?"))
            {
                cout << "Enter Membership number: ";
                memberID = readInt(10000, 99999);
                getPub(searchResult)->set(memberID);
                m_changed = true;
                cout << "Publication checked out" << endl;
                cout << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }

    LibApp::LibApp(const char *fileName)
    {
        strcpy(m_filename, fileName);
        m_nolp = 0;
        m_llrn = 0;
        m_changed = false;
        Menu m_mainMenu1("Seneca Library Application");
        m_mainMenu = m_mainMenu1;
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";
        Menu m_exitMenu1("Changes have been made to the data, what would you like to do?");
        m_exitMenu = m_exitMenu1;
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";
        Menu m_chooseMenu1("Choose the type of publication:");
        m_chooseMenu = m_chooseMenu1;
        m_chooseMenu << "Book"
                     << "Publication";
        load();
    }

    LibApp::~LibApp()
    {
        for (int i = 0; i < m_nolp; i++)
        {
            delete m_ppa[i];
            m_ppa[i] = nullptr;
        }
    }

    void LibApp::run()
    {
        int done = 0;
        int mChoice = 0;
        int eChoice = 0;
        do
        {
            mChoice = m_mainMenu.run();
            if (mChoice == 1)
            {
                newPublication();
            }
            else if (mChoice == 2)
            {
                removePublication();
            }
            else if (mChoice == 3)
            {
                checkOutPub();
            }
            else if (mChoice == 4)
            {
                returnPub();
            }
            else
            {
                if (m_changed)
                {
                    eChoice = m_exitMenu.run();
                    if (eChoice == 1)
                    {
                        save();
                        done = 1;
                    }
                    else if (eChoice == 2)
                    {
                        done = 0;
                        cout << endl;
                    }
                    else
                    {
                        if (confirm("This will discard all the changes are you sure?"))
                            done = 1;
                    }
                }
                else
                {
                    done = 1;
                }
            }
        } while (!done);
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    Publication *LibApp::getPub(int libRef) const
    {
        Publication *pickPub{};
        for (int i = 0; i < m_nolp; i++)
        {
            if (m_ppa[i]->getRef() == libRef)
            {
                pickPub = m_ppa[i];
            }
        }
        return pickPub;
    }

}