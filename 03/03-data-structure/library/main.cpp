// Danial Mobini 40130023
// Mohammad Sadegh Hatefi 40133073
// Hadis Kianpour 40201763

#include <iostream>
#include "Library.hpp"
#include <cereal/archives/json.hpp>
int main()
{
    try
    {
        Library my_library;
        my_library.read();
        my_library.start();
        my_library.write();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}