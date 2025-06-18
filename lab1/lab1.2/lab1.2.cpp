#include <iostream>
#include <string>

using namespace std;

const string NUMBER_OF_BITS_1 = "Number of set bits in byte ";
const string NUMBER_OF_BITS_2 = " is: ";
const string BYTE_INPUT = "Enter a byte (0-255): ";
const string BYTE_INPUT_ERROR = "Invalid input. Byte must be an integer between 0 and 255.";

//Bit Manipulation Technique
int countSetBits(int byte)
{
    int count = 0;
    while (byte)
    {
        count += byte & 1;
        byte >>= 1;
    }
    return count;
}

void PrintBitsInByte(int byte, int setBitsCount)
{
    cout << NUMBER_OF_BITS_1 << byte << NUMBER_OF_BITS_2 << setBitsCount << std::endl;
}

int main()
{
    int byte;
    cout << BYTE_INPUT;
    cin >> byte;

    if (cin.fail() || byte < 0 || byte > 255)
    {
        cerr << BYTE_INPUT_ERROR << std::endl;
        return 1;
    }

    int setBitsCount = countSetBits(byte);

    PrintBitsInByte(byte, setBitsCount);

    return 0;
}