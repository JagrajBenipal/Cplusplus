/*
Name: Jagraj Singh Benipal
Seneca email: jbeipal1@myseneca.ca
Student ID: 156374217
Date: April 1, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
using namespace std;
#include "process_data.h"

namespace sdds_ws9
{

    void computeAvgFactor(const int *arr, int size, int divisor, double &avg)
    {
        avg = 0;
        for (int i = 0; i < size; i++)
        {
            avg += arr[i];
        }
        avg /= divisor;
    }

    void computeVarFactor(const int *arr, int size, int divisor, double avg, double &var)
    {
        var = 0;
        for (int i = 0; i < size; i++)
        {
            var += (arr[i] - avg) * (arr[i] - avg);
        }
        var /= divisor;
    }
    ProcessData::operator bool() const
    {
        return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
    }

    ProcessData::ProcessData(std::string filename, int n_threads)
    {
        // TODO: Open the file whose name was received as parameter and read the content
        //         into variables "total_items" and "data". Don't forget to allocate
        //         memory for "data".
        //       The file is binary and has the format described in the specs.

        std::ifstream file(filename, std::ios::binary);

        if (!file)
        {
            throw std::string("Cannot open file: " + filename);
        }
        else
        {

            file.read((char *)&total_items, sizeof(total_items));

            data = new int[total_items];

            file.read((char *)data, sizeof(int) * total_items);

            file.close();

            std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
            std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
                      << data[total_items - 3] << ", " << data[total_items - 2] << ", "
                      << data[total_items - 1] << "]\n";

            // Following statements initialize the variables added for multi-threaded computation
            num_threads = n_threads;
            averages = new double[num_threads]{};
            variances = new double[num_threads]{};
            p_indices = new int[num_threads + 1]{};
            for (int i = 0; i < num_threads + 1; i++)
                p_indices[i] = i * (total_items / num_threads);
        }
        return;
    }
    ProcessData::~ProcessData()
    {
        delete[] data;
        delete[] averages;
        delete[] variances;
        delete[] p_indices;
    }

    // TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the
    //   function logic for the computation of average and variance by running the
    //   function computeAvgFactor and computeVarFactor in multile threads.
    // The function divides the data into a number of parts, where the number of parts is
    //   equal to the number of threads. Use multi-threading to compute average-factor for
    //   each part of the data by calling the function computeAvgFactor. Add the obtained
    //   average-factors to compute total average. Use the resulting total average as the
    //   average value argument for the function computeVarFactor, to compute variance-factors
    //   for each part of the data. Use multi-threading to compute variance-factor for each
    //   part of the data. Add computed variance-factors to obtain total variance.
    // Save the data into a file with filename held by the argument fname_target.
    // Also, read the workshop instruction.

    int ProcessData::operator()(const std::string filename, double &average, double &variance)
    {
        using namespace placeholders;

        std::vector<std::thread> avg;
        std::vector<std::thread> var;

        // Bind total_items to the function computeAvgFactor as the divisor parameter.
        auto computeAverage = bind(computeAvgFactor, _1, _2, total_items, _3);

        // Create threads
        for (auto i = 0; i < num_threads; i++)
        {
            avg.push_back(thread([=]()
                                 {
				// Call computeAvgFactor(&data[p_indices[i]], total_items / num_threads, total_items, ref(averages[i]));
				computeAverage(&data[p_indices[i]], total_items / num_threads, ref(averages[i])); }));
        }

        // Join the threads.
        for (auto &i : avg)
        {
            i.join();
        }

        // Add all the average-factors into the variable to hold total average; this shold be one of the parameters of the operator() function.
        for (auto i = 0; i < num_threads; i++)
        {
            average += averages[i];
        }

        // Bind total_items and the computed average as divisor and avg, respectively, to the function ,before creating the threads.
        auto computeVariance = bind(computeVarFactor, _1, _2, total_items, average, _3);

        // Create threads
        for (auto i = 0; i < num_threads; i++)
        {
            var.push_back(thread([=]()
                                 {
				// Call computeVarFactor(&data[p_indices[i]], total_items / num_threads, total_items,76 average, ref(variance[i]));
				computeVariance(&data[p_indices[i]], total_items / num_threads, ref(variances[i])); }));
        }

        // Join the threads.
        for (auto &i : var)
        {
            i.join();
        }

        // Add the variance-factors computed by threads to compute the total variance.
        for (auto i = 0; i < num_threads; i++)
        {
            variance += variances[i];
        }

        // Open the target data file and write the data (total_items, and data) in the format of the input data file data_int.dat
        std::ofstream file(filename, std::ios::binary);

        if (!file)
        {
            throw std::string("Cannot open file: " + filename);
        }
        else
        {
            file.write((const char *)&total_items, sizeof(total_items));
            file.write((const char *)data, sizeof(int) * total_items);

            file.close();

            return total_items;
        }
    }
}
