#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void write()
{

    vector<string> data = {
        // ADD(0-3)
        "000 000 000 01 01 1000011",
        "000 100 000 00 00 0000010",
        "001 000 000 00 00 1000000",
        "000 000 000 10 00 0000110",
        // BRANCH(4-7)
        "000 000 000 10 00 0000110",
        "000 000 000 00 00 1000000",
        "000 000 000 01 01 1000011",
        "000 000 110 00 00 1000000",
        // STORE(8-11)
        "000 000 000 01 01 1000011",
        "000 101 000 00 00 0001010",
        "111 000 000 00 00 1000000",
        "000 000 000 00 00 1000000",
        // EXCHANGE(12-15)
        "000 000 000 01 01 1000011",
        "001 000 000 00 00 0001110",
        "100 101 000 00 00 0001111",
        "111 000 000 00 00 1000000",
        // FETCH(64-66)
        "110 000 000 00 00 1000001",
        "000 100 101 00 00 1000010",
        "101 000 000 00 11 0000000",
        // INDRCT(67-68)
        "000 100 000 00 00 1000100",
        "101 000 000 00 10 0000000"};

    ofstream outFile1("output1.bin", ios::binary);
    ofstream outFile2("output2.bin", ios::binary);
    ofstream outFile3("output3.bin", ios::binary);
    if (!outFile1 || !outFile2 || !outFile3)
    {
        cerr << "Failed to open files for writing.\n";
        return;
    }
    outFile1.clear();
    outFile2.clear();
    outFile3.clear();

    for (int i = 0; i < 16; i++)
    {
        // Remove spaces from the string
        string binaryString;
        for (char c : data[i])
        {
            if (c != ' ')
                binaryString += c;
        }

        while (binaryString.length() < 24)
        {
            binaryString += "0"; // Pad with zeros
        }

        // Convert to binary and write to file
        bitset<24> bits(binaryString);
        unsigned long n = bits.to_ulong();

        // Write 3 bytes (24 bits) to the file
        outFile1.put(static_cast<char>((n >> 16) & 0xFF));
        outFile2.put(static_cast<char>((n >> 8) & 0xFF));
        outFile3.put(static_cast<char>(n & 0xFF));
    }
    for (int i = 16; i < 64; i++)
    {
        string binaryString;
        while (binaryString.length() < 24)
        {
            binaryString += "0"; // Pad with zeros
        }
        bitset<24> bits(binaryString);
        unsigned long n = bits.to_ulong();

        // Write 3 bytes (24 bits) to the file
        outFile1.put(static_cast<char>((n >> 16) & 0xFF));
        outFile2.put(static_cast<char>((n >> 8) & 0xFF));
        outFile3.put(static_cast<char>(n & 0xFF));
    }
    for (int i = 16; i < 21; i++)
    {
        // Remove spaces from the string
        string binaryString;
        for (char c : data[i])
        {
            if (c != ' ')
                binaryString += c;
        }

        while (binaryString.length() < 24)
        {
            binaryString += "0"; // Pad with zeros
        }

        // Convert to binary and write to file
        bitset<24> bits(binaryString);
        unsigned long n = bits.to_ulong();

        // Write 3 bytes (24 bits) to the file
        outFile1.put(static_cast<char>((n >> 16) & 0xFF));
        outFile2.put(static_cast<char>((n >> 8) & 0xFF));
        outFile3.put(static_cast<char>(n & 0xFF));
    }

    outFile1.close();
    outFile2.close();
    outFile3.close();
    cout << "File written successfully.\n";
}

int main()
{
    write();
}