#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <functional>
#include "TVSet.h"

using namespace std;

const string WELCOME_MSG = "Welcome to TV Control! Type 'help' or '0' for the list of commands.\n";
const string MENU_HEADER = "TV Control Menu:\n";
const string MENU_ITEMS =
"1. turn_on\n"
"2. turn_off\n"
"3. select_channel <channel_number>\n"
"4. select_channel_by_name <channel_name>\n"
"5. select_previous_channel\n"
"6. set_channel_name <channel_number> <channel_name>\n"
"7. get_channel_name <channel_number>\n"
"8. get_channel_by_name <channel_name>\n"
"9. delete_channel_name <channel_name>\n"
"10. TV_info\n"
"11. exit\n";
const string MENU_FOOTER = "_____________________________\n";
const string PROMPT_SYMBOL = "> ";
const string EXIT_MSG = "Exiting...\n";
const string NO_CHANNEL_NAME = "No channel name\n";
const string INVALID_COMMAND_MSG = "Invalid command. Type 'help' or '0' for the list of commands.";
const string CHANNEL_NAME_PREFIX = "Channel name: ";
const string CHANNEL_NUMBER_PREFIX = "Channel Number: ";
const string NO_CHANNEL_WITH_NAME = "No channel with this name";
const string MISSING_PARAMETR1 = "Missing parameter. Enter ";
const string ERROR_DOT = ".";
const string INVALID_PARAMETR = "Invalid ";
const string CHANNEL_NUMBER = "channel number";
const string CHANNEL_NAME = "channel name";
const string CHANNEL_NUMBER_AND_NAME = "channel number and name.";

void DisplayMenu()
{
    cout << MENU_HEADER
        << MENU_ITEMS
        << MENU_FOOTER;
}

void PrintError(const string& error)
{
    cout << error << endl;
}

void PrintMissingParameterError(const string& parameter)
{
    PrintError(MISSING_PARAMETR1 + parameter + ERROR_DOT);
}

void PrintInvalidParameterError(const string& parameter)
{
    PrintError(INVALID_PARAMETR + parameter + ERROR_DOT);
}

void ProcessCommand(CTVSet& tv, const string& command)
{
    istringstream iss(command);
    string cmd, param1, param2;
    iss >> cmd >> param1 >> param2;

    map<string, string> numericToCommand = {
        {"0", "help"},
        {"1", "turn_on"},
        {"2", "turn_off"},
        {"3", "select_channel"},
        {"4", "select_channel_by_name"},
        {"5", "select_previous_channel"},
        {"6", "set_channel_name"},
        {"7", "get_channel_name"},
        {"8", "get_channel_by_name"},
        {"9", "delete_channel_name"},
        {"10", "TV_info"},
        {"11", "exit"}
    };

    auto numericCmdIt = numericToCommand.find(cmd);
    if (numericCmdIt != numericToCommand.end()) {
        cmd = numericCmdIt->second;
    }

    map<string, function<void()>> commandMap = {
        {"turn_on", [&]() { tv.TurnOn(); }},
        {"turn_off", [&]() { tv.TurnOff(); }},
        {"select_channel", [&]() {
            if (param1.empty()) {
                PrintMissingParameterError(CHANNEL_NUMBER);
                return;
            }
            int channel;
            if (!(istringstream(param1) >> channel)) {
                PrintInvalidParameterError(CHANNEL_NUMBER);
                return;
            }
            tv.SelectChannel(channel);
        }
        },

        {"select_channel_by_name", [&]() {
            if (param1.empty()) {
                PrintMissingParameterError(CHANNEL_NAME);
                return;
            }
            tv.SelectChannelByName(param1);
        }
        },

        {"select_previous_channel", [&]() { tv.SelectPreviousChannel(); }},
        {"set_channel_name", [&]() {
            if (param1.empty() || param2.empty()) {
                PrintMissingParameterError(CHANNEL_NUMBER_AND_NAME);
                return;
            }
            int channel;
            if (!(istringstream(param1) >> channel)) {
                PrintInvalidParameterError(CHANNEL_NUMBER);
                return;
            }
            tv.SetChannelName(channel, param2);
        }
        },

        {"get_channel_name", [&]() {
            if (param1.empty()) {
                PrintMissingParameterError(CHANNEL_NUMBER);
                return;
            }
            int channel;
            if (!(istringstream(param1) >> channel)) {
                PrintInvalidParameterError(CHANNEL_NUMBER);
                return;
            }
            string channelName = tv.GetChannelName(channel);
            if (channelName.empty()) {
                cout << NO_CHANNEL_NAME;
            }
            else {
                cout << CHANNEL_NAME_PREFIX << channelName << "\n";
            }
        }
        },

        {"get_channel_by_name", [&]() {
            if (param1.empty()) {
                PrintMissingParameterError(CHANNEL_NAME);
                return;
            }
            int channelNumber = tv.GetChannelByName(param1);
            if (channelNumber == -1) {
                cout << NO_CHANNEL_WITH_NAME;
            }
            else {
                cout << CHANNEL_NUMBER_PREFIX << channelNumber << "\n";
            }
        }
        },

        {"delete_channel_name", [&]() {
            if (param1.empty()) {
            PrintMissingParameterError(CHANNEL_NAME);
            return;
            }
            tv.DeleteChannelName(param1);
        }
        },

        {"TV_info", [&]() { tv.Info(); }},
        {"exit", [&]() {
            cout << EXIT_MSG;
            exit(0);
        }
        },
        {"help", [&]() { DisplayMenu(); }}
    };

    auto it = commandMap.find(cmd);
    if (it != commandMap.end()) {
        it->second();  
    }
    else {
        PrintError(INVALID_COMMAND_MSG);
    }
}


void TVRun()
{
    CTVSet tv;
    cout << WELCOME_MSG;
    string command;
    while (true)
    {
        cout << PROMPT_SYMBOL;
        getline(cin, command);
        ProcessCommand(tv, command);
    }
}
