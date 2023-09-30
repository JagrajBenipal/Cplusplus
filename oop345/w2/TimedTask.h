///*
// Name: Jagraj Singh Benipal
// Seneca email: jbenipal1@myseneca.ca
// Student ID: 156374217
// Date: JAN 29, 2023
// I have done all the workshop by myself and have only copied the code provided
// by professor.
//*

#ifndef TIMEDTASK_H
#define TIMEDTASK_H
#include <iostream>
#include <chrono>
#include <string>

namespace sdds
{
    class TimedTask
    {
        unsigned int m_NumOfRecords{};
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
        std::chrono::time_point<std::chrono::steady_clock> m_endTime;
        struct Task
        {
            std::string m_taskName{};
            std::string m_unitTime{};
            std::chrono::steady_clock::duration m_duration{};
        } event[10];

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char *cString);
        std::ostream &display(std::ostream &ostr) const;
        friend std::ostream &operator<<(std::ostream &ostr, const TimedTask &object);
    };
}
#endif