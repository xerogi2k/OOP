#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string USAGE_ERROR_1 = "Usage: ";
const string USAGE_ERROR_2 = " <filename> <search_word>";
const string OPEN_FILE_ERROR_MESSAGE = "File open error.";
const string FOUND_TEXT_ERROR_MESSAGE = "Text not found";


vector<int> FindStringInFile(ifstream& file, const string& search_word)
{
    vector<int> found_lines;
    string line;
    int line_number = 1;

    while (getline(file, line))
    {
        size_t found = line.find(search_word);
        if (found != string::npos)
        {
            found_lines.push_back(line_number);
        }
        line_number++;
    }

    return found_lines;
}

void PrintFoundLineIndex(vector<int> found_lines)
{
    for (int num : found_lines)
    {
        cout << num << endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << USAGE_ERROR_1 << argv[0] << USAGE_ERROR_2 << endl;
        return 1;
    }

    string filename = argv[1];
    string search_word = argv[2];

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << OPEN_FILE_ERROR_MESSAGE << endl;
        return 1;
    }

    vector<int> found_lines = FindStringInFile(file, search_word);

    file.close();

    if (found_lines.empty())
    {
        cout << FOUND_TEXT_ERROR_MESSAGE << endl;
        return 1;
    }

    PrintFoundLineIndex(found_lines);

    return 0;
}