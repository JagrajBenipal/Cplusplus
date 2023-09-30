/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
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
#include <iostream>
#include <cstring>
#include "Publication.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
    Publication::Publication()
    {
        setEmpty();
    }

    Publication::Publication(const Publication &toCopy)
    {
        operator=(toCopy);
    }

    Publication::~Publication()
    {
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();
    }

    void Publication::set(int member_id)
    {
        if (member_id >= 10000 && member_id <= 99999)
            m_membership = member_id;
        else if (m_membership == 0)
        {
            m_membership = member_id;
        }
    }
    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    Publication &Publication::operator=(const Publication &toAssign)
    {
        if (this != &toAssign && toAssign != nullptr)
        {
            cpStr(m_title, toAssign.m_title);
            strcpy(m_shelfId, toAssign.m_shelfId);
            m_libRef = toAssign.m_libRef;
            m_membership = toAssign.m_membership;
            m_date = toAssign.m_date;
        }
        return *this;
    }

    void Publication::resetDate()
    {
        m_date.setToToday();
    }

    void Publication::setEmpty()
    {
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();
    }

    char Publication::type() const
    {
        char rtn;
        rtn = 'P';
        return rtn;
    }

    bool Publication::onLoan() const
    {
        if (m_membership != 0)
        {
            return true;
        }
        else
            return false;
    }
    Date Publication::checkoutDate() const
    {
        return m_date;
    }
    bool Publication::operator==(const char *title) const
    {
        return strstr(m_title, title);
    }
    bool Publication::conIO(ios &io) const
    {
        return ((&io == &cin) || (&io == &cout));
    }
    std::ostream &Publication::write(std::ostream &os) const
    {
        if (conIO(os))
        {
            os << "| ";
            os << m_shelfId;
            os << " | ";
            if (strlen(m_title) > SDDS_TITLE_WIDTH)
            {
                for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
                {
                    os << m_title[i];
                }
            }
            else
            {
                os.setf(ios::left);
                os.fill('.');
                os.width(SDDS_TITLE_WIDTH);
                os << m_title;
                os.fill(' ');
            }
            os << " | ";
            if (m_membership != 0)
            {
                os << m_membership;
            }
            else
                os << " N/A ";
            os << " | ";
            os << m_date;
            os << " |";
        }
        else
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }
    std::istream &Publication::read(std::istream &istr)
    {
        setEmpty();
        int tmpLibRef = 0;
        int tmpMembership = 0;
        char tmpShlfId[SDDS_SHELF_ID_LEN + 1]{};
        char *tmptitle{};
        Date tempDate;
        if (conIO(istr))
        {
            cout << "Shelf No: ";
            istr.getline(tmpShlfId, SDDS_SHELF_ID_LEN + 1, '\n');
            if (strlen(tmpShlfId) < SDDS_SHELF_ID_LEN)
                istr.setstate(ios::failbit);
            cout << "Title: ";
            tmptitle = getInput(istr);
            cout << "Date: ";
            tempDate.read(istr);
        }
        else
        {
            istr >> tmpLibRef;
            readChar(istr, '\t');
            istr >> tmpShlfId;
            readChar(istr, '\t');
            tmptitle = getInput(istr, '\t');
            istr >> tmpMembership;
            readChar(istr, '\t');
            tempDate.read(istr);
        }
        if (!tempDate)
            istr.setstate(ios::failbit);
        if (istr)
        {
            cpStr(m_title, tmptitle);
            strcpy(m_shelfId, tmpShlfId);
            set(tmpMembership);
            setRef(tmpLibRef);
            m_date = tempDate;
        }
        delete[] tmptitle;
        return istr;
    }
    Publication::operator const char *() const
    {
        return m_title;
    }
    Publication::operator bool() const
    {
        return (m_title && m_title[0] != '\0' && m_shelfId[0] != '\0');
    }
    int Publication::getRef() const
    {
        return m_libRef;
    }
}