// Name: Jagraj Singh Benipal
// ID: 156374217
// Email: jbenipal1@myseneca.ca
//  Date: Aug 5 2022
// Section: ZBB
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds
{
    // Find with 3 parameters
    // There are 3 parameters passing into this find function, the first one is an array of templated objects which has the same data type of the Collection type, I defined a typename T for this parameter.
    // The second parameter is an integer that represents the index to be compared. The third one is another value that act as a key to find out the desired result, I defined another typename C for it because
    // it is a different data type with the first parameter. This function will return boolean (true or false).
    // if an element in the array is matched with the key value, "True" will be returned otherwise "False" will be returned.
    template <typename T, typename C>
    bool find(T arr[], int index, C &key)
    {
        if (arr[index] == key)
            return true;
        return false;
    }

    // Find with 4 parameters
    // There are 4 parameters passing into this find function, the first one is an array of templated objects which has the same data type of the Collection type, I defined a typename T for this parameter.
    // The second parameter is an integer that represents the index to be compared. The third one is another value that act as a key to find out the desired result, I defined another typename C for it because
    // it is a different data type with the first parameter. The fourth one is another key to be search in the array. I defined another typename H for it because it is a different data type with the first two parameters.
    // This function will return integer (index number or -1).
    // if an element in the array is matched with both keyA and keyB value, the index number (i) will be returned otherwise -1 will be returned to indicate there is no matching result.
    template <typename T, typename C, typename H>
    int find(T arr[], int index, C &keyA, H &keyB)
    {
        for (int i = 0; i < index; i++)
        {
            if (arr[i] == keyA && arr[i] == keyB)
                return i;
        }
        return -1;
    }

    // Insertion operator
    // This function is used to display all the elements in an array by overloading the insertion operator.I defined only one typename T and also defined tContainer which has a Collection class with type T (Collection tempplate).
    // It is because this function takes two parameters (an reference of ostream object and a collection template). I used a FOR loop to iterate all the elements in the array and then insert each element to the ostream, and return
    // the ostream to main.
    template <typename T>
    std::ostream &operator<<(std::ostream &os, Collection<T> &tContainer)
    {
        for (int i = 0; i < tContainer.size(); i++)
        {
            os << tContainer[i] << std::endl;
        }
        return os;
    }

    // Load Collection
    // This function is used to add the new item into the collection class. I defined one typename T becuause both Collection and object should be in the same type.
    // It contains a simple code that overloaded += operator which is already defined in Collection.h, and then return the Collection to main.
    template <typename T>
    const Collection<T> &loadCollection(Collection<T> &collect, T &obj)
    {
        collect += obj;
        return collect;
    }

}
#endif // !SDDS_SEARCH_H_
