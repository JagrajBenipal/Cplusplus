/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: April 7, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
    LineManager::LineManager(const std::string &file, const std::vector<Workstation *> &stations)
    {
        Utilities temp;
        string filestr = "";
        string firstWS = "";
        string secondWS = "";
        size_t pos = 0u;
        bool more = false;

        ifstream infile(file);

        if (infile)
        {
            while (getline(infile, filestr))
            {
                // extract first string from line
                firstWS = temp.extractToken(filestr, pos, more);
                // if there is more string in line, extract second string from line
                if (more)
                {
                    secondWS = temp.extractToken(filestr, pos, more);
                }
                else
                {
                    secondWS = "";
                }

                // loop each to find match with the first string
                for_each(stations.begin(), stations.end(), [=](Workstation *ws)
                         {
					// if first string match... 
					if (ws->getItemName() == firstWS) {
						// loop to check any station match with second string, return true.
						for_each(stations.begin(), stations.end(), [=](Workstation* otherws) {
							// if second string match, pair up as next station with first station.
							if (otherws->getItemName() == secondWS)
							{
								ws->setNextStation(otherws);
							}
						});
							// second string exist, push first WS to the workstation vector
							m_activeLine.push_back(ws);
					} });
            }

            // activeLine have all station stored, find which station is the first in line
            // Each activeLine's WS, if any of WS == WS's next station -> WS is not first.
            // if the WS not in next station -> it is the first one.
            for_each(m_activeLine.begin(), m_activeLine.end(), [=](Workstation *ws)
                     {
				bool exist = any_of(stations.begin(), stations.end(), [=](Workstation* otherws) {
					bool result = false;
					if (ws == otherws->getNextStation())
					{
						result = true;
					}
					return result;
				});
					
				if (!exist)
				{
					m_firstStation = ws;
				} });

            m_cntCustomerOrder = g_pending.size();
        }
        else
        //  If something goes wrong, this constructor reports an error.
        {
            throw "Cannot open the file.";
        }
    }

    void LineManager::reorderStations()
    {
        // put first station as work station to store
        Workstation *workstationToStore = m_firstStation;
        // temp vector for reordering
        vector<Workstation *> tempactiveLine;
        // while work station to store exist
        while (workstationToStore)
        {
            // push the work station to the temp vector
            tempactiveLine.push_back(workstationToStore);
            // find this work station's next station
            workstationToStore = workstationToStore->getNextStation();
        }
        // assign the temp vector to replace the real one
        m_activeLine = tempactiveLine;
    }

    bool LineManager::run(std::ostream &os)
    {
        static size_t count = 0u;

        count++;
        os << "Line Manager Iteration: " << count << endl;
        if (g_pending.size() > 0)
        {
            // moves the order at the front of the g_pending queue to the m_firstStation (front of m_activeline)
            *m_activeLine.front() += move(g_pending.front());
            // remove it from the queue
            g_pending.pop_front();
        }

        // for each station on the line, executes one fill operation
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *ws)
                 { ws->fill(os); });

        // for each station on the line, attempts to move an order down the line
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *ws)
                 { ws->attemptToMoveOrder(); });

        // return true if all customer orders have been filled (complete) or cannot be filled (incomplete)
        return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
    }

    void LineManager::display(std::ostream &os) const
    {
        for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation *ws)
                 { ws->display(os); });
    }

}