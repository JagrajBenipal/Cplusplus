/*********************************************************************************
Name: Jagraj Singh Benipal
Student mail : jbenipal1@myseneca.ca
Student id: 156374217
I have done all the coding by myself and only copied
the code that my professor provided to complete my workshops and assignments.
**********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h" 
    using namespace std;
namespace sdds
{
    Numbers::Numbers()
    {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char *filename)
    {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load())
        {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else
        {
            sort();
        }
    }
    Numbers::Numbers(const Numbers &toCopy)
    {
        setEmpty();
        m_isOriginal = false;
        operator=(toCopy);
    }
    Numbers &Numbers::operator=(const Numbers &toAssign)
    {
        if (this != &toAssign)
        {
            m_numCount = toAssign.m_numCount;
            delete[] m_numbers;
            m_numbers = nullptr;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++)
            {
                m_numbers[i] = toAssign.m_numbers[i];
            }
        }
        return *this;
    }
    Numbers &Numbers::operator+=(const double &ro)
    {
        double *temp = nullptr;
        temp = new double[m_numCount + 1];
        for (int i = 0; i < m_numCount; i++)
        {
            temp[i] = m_numbers[i];
        }
        delete[] m_numbers;
        m_numbers = nullptr;
        m_numCount++;
        m_numbers = new double[m_numCount];
        for (int i = 0; i < m_numCount; i++)
        {
            m_numbers[i] = temp[i];
        }
        delete[] temp;
        temp = nullptr;
        m_numbers[m_numCount - 1] = ro;
        sort();
        return *this;
    }
    Numbers::~Numbers()
    {
        save();
        delete[] m_numbers;
        m_numbers = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
    }

    ostream &Numbers::display(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Empty list";
        }
        else
        {
            ostr << "=========================" << endl;
            if (!m_isOriginal)
            {
                ostr << "*** COPY ***" << endl;
            }
            else
            {
                ostr << m_filename << endl;
            }
            for (int i = 0; i < m_numCount; i++)
            {
                ostr << m_numbers[i];
                if (i != m_numCount - 1)
                    ostr << ", ";
            }
            ostr << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average :        " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    bool Numbers::isEmpty() const
    {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty()
    {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char *filename)
    {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    void Numbers::sort()
    {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (m_numbers[j] > m_numbers[j + 1])
                {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    void Numbers::save()
    {
        if (m_isOriginal && !isEmpty())
        {
            FILE *fp = NULL;
            fp = fopen(m_filename, "w");
            if (fp != NULL)
            {
                for (int i = 0; i < m_numCount; i++)
                {
                    fprintf(fp, "%g\n", m_numbers[i]);
                }
                fclose(fp);
            }
        }
    }

    double Numbers::average() const
    {
        double aver = 0.0;
        if (!isEmpty())
        {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const
    {
        double minVal = 0.0;
        if (!isEmpty())
        {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i])
                    minVal = m_numbers[i];
        }
        return minVal;
    }
    int Numbers::numberCount() const
    {
        ifstream read;
        read.open(m_filename);
        char c[20];
        int count = 0;
        if (read.is_open())
        {
            while (read.getline(c, 20, '\n'))
            {
                count++;
            }
            read.close();
        }
        return count;
    }
    bool Numbers::load()
    {
        int i = 0;
        int numCount = 0;
        double readNum = 0;
        FILE *fptr = nullptr;
        fptr = fopen(m_filename, "r");
        numCount = numberCount();
        m_numbers = new double[numCount];
        if (fptr != nullptr)
        {
            do
            {
                if (fscanf(fptr, "%lf", &readNum) == 1)
                {
                    if (readNum > 0)
                    {
                        m_numbers[i] = readNum;
                        i++;
                    }
                }
            } while (fgetc(fptr) != EOF);
            fclose(fptr);
        }
        return i == numCount;
    }

    double Numbers::max() const
    {
        double maxVal = 0.0;
        if (!isEmpty())
        {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i])
                    maxVal = m_numbers[i];
        }
        return maxVal;
    }

    ostream &operator<<(ostream &os, const Numbers &N)
    {
        return N.display(os);
    }

    istream &operator>>(istream &istr, Numbers &N)
    {
        double dou = 0;
        istr >> dou;
        istr.ignore();
        N += dou;
        return istr;
    }

}