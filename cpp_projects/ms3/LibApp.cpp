/* Citation and Sources...
Final Project Milestone 3
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
#include <ctime>
using namespace std;
#include "Menu.h"
#include "LibApp.h"
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
        cout << "Loading Data" << endl;
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        cout << endl;
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        else
        {
            cout << endl;
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed" << endl
                 << endl;
        }
        else
        {
            cout << endl;
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
        }
    }

    LibApp::LibApp()
    {
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
        load();
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

}