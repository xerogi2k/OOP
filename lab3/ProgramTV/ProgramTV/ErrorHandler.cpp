#include <iostream>
#include "ErrorHandler.h"

using namespace std;

const string ERROR = "Error: ";

void ShowError(ostream& out, const string& message)
{
    out << ERROR << message << "\n";
}
