///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: JAN 29, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#include <iostream>
#include <chrono>
#include "TimedTask.h"

using namespace std;
namespace sdds
{
    TimedTask::TimedTask()
    {
    }
    void TimedTask::startClock()
    {
        m_startTime = std::chrono::steady_clock::now();
    }
    void TimedTask::stopClock()
    {
        m_endTime = std::chrono::steady_clock::now();
    }
    void TimedTask::addTask(const char *cString)
    {
        event[m_NumOfRecords].m_taskName = string(cString);
        event[m_NumOfRecords].m_unitTime = "nanoseconds";
        event[m_NumOfRecords].m_duration = m_endTime - m_startTime;
        m_NumOfRecords++;
    }
    std::ostream &TimedTask::display(std::ostream &ostr) const
    {
        ostr << "--------------------------\n";
        ostr << "Execution Times:\n";
        ostr << "--------------------------\n";
        for (unsigned int i = 0u; i < m_NumOfRecords; ++i)
        {
            ostr.width(21);
            ostr << left << event[i].m_taskName;
            ostr.width(13);
            ostr << right << event[i].m_duration.count() << " " << event->m_unitTime << endl;
        }
        ostr << "--------------------------\n";
        return ostr;
    }
    std::ostream &operator<<(std::ostream &ostr, const TimedTask &object)
    {
        return object.display(ostr);
    }
}