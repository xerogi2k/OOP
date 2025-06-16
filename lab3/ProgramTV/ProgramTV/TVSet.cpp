#include <utility>
#include "TVSet.h"
#include "ErrorHandler.h"

using namespace std;

const string TV_ON_MSG = "TV was turned on.\n";
const string TV_ALREADY_ON_MSG = "TV is already turned on.";
const string TV_OFF_MSG = "TV was turned off.\n";
const string TV_ALREADY_OFF_MSG = "TV is already turned off.";
const string TV_MUST_BE_ON_MSG = "TV must be turned on.";
const string VALID_CHANNEL_MSG = "Enter a valid channel number (1 to 99).";
const string CHANNEL_SELECTED_MSG = "Channel has been selected.\n";
const string CHANNEL_NOT_EXIST_MSG = "Channel does not exist.";
const string CHANNEL_NAME_EMPTY_MSG = "Channel name cannot be empty.";
const string CHANNEL_NAME_CHANGED_MSG = "Channel name successfully changed.\n";
const string PREVIOUS_CHANNEL_SELECTED_MSG = "Previous channel has been selected.\n";
const string CHANNEL_NAME_DELETED_MSG = "Channel name successfully deleted.\n";
const string INFO_ON = "ON";
const string INFO_OFF = "OFF";
const string INFO_CURRENT_CHANNEL = "Current channel: ";
const string INFO_CURRENT_CHANNEL_NAME = "Current channel name: ";
const string CHANNEL = "Channel ";
const string COMMA = ", ";
const string TV_IS = "TV is ";
const string DASH = " - ";

CTVSet::CTVSet() : m_isOn(false), m_currentChannel(0), m_previousChannel(0) {}

void CTVSet::TurnOn()
{
    if (!m_isOn)
    {
        m_isOn = true;
        if (m_previousChannel != 0)
        {
            m_currentChannel = m_previousChannel;
        }
        else
        {
            m_previousChannel = 1;
            m_currentChannel = 1;
        }
        cout << TV_ON_MSG;
    }
    else
    {
        ShowError(cout, TV_ALREADY_ON_MSG);
    }
}

void CTVSet::TurnOff()
{
    if (m_isOn)
    {
        m_isOn = false;
        m_previousChannel = m_currentChannel;
        m_currentChannel = 0;
        cout << TV_OFF_MSG;
    }
    else
    {
        ShowError(cout, TV_ALREADY_OFF_MSG);
    }
}

void CTVSet::SelectChannel(int channel)
{
    if (!m_isOn)
    {
        ShowError(cout, TV_MUST_BE_ON_MSG);
        return;
    }
    if (!(channel >= 1 && channel <= 99))
    {
        ShowError(cout, VALID_CHANNEL_MSG);
        return;
    }
    m_previousChannel = m_currentChannel;
    m_currentChannel = channel;
    cout << CHANNEL << channel << COMMA << CHANNEL_SELECTED_MSG;
}

void CTVSet::SelectChannelByName(const string& name)
{
    for (auto i = m_channelNames.begin(); i != m_channelNames.end(); ++i)
    {
        if (i->second == name)
        {
            m_previousChannel = m_currentChannel;
            m_currentChannel = i->first;
            cout << CHANNEL << i->first << COMMA << CHANNEL_SELECTED_MSG;
            return;
        }
    }
    ShowError(cout, CHANNEL_NOT_EXIST_MSG);
}

void CTVSet::SelectPreviousChannel()
{
    if (!m_isOn)
    {
        ShowError(cout, TV_MUST_BE_ON_MSG);
        return;
    }
    swap(m_currentChannel, m_previousChannel);
    cout << PREVIOUS_CHANNEL_SELECTED_MSG;
}

void CTVSet::SetChannelName(int channel, const string& name)
{
    if (!m_isOn)
    {
        ShowError(cout, TV_MUST_BE_ON_MSG);
        return;
    }
    if (!(channel >= 1 && channel <= 99))
    {
        ShowError(cout, VALID_CHANNEL_MSG);
        return;
    }
    if (name.empty())
    {
        ShowError(cout, CHANNEL_NAME_EMPTY_MSG);
        return;
    }
    m_channelNames[channel] = name;
    cout << CHANNEL_NAME_CHANGED_MSG;
}

string CTVSet::GetChannelName(int channel) const
{
    auto i = m_channelNames.find(channel);
    if (i != m_channelNames.end())
    {
        return i->second;
    }
    return "";
}

int CTVSet::GetChannelByName(const string& name) const
{
    for (auto i = m_channelNames.begin(); i != m_channelNames.end(); ++i)
    {
        if (i->second == name)
        {
            return i->first;
        }
    }
    return -1;
}

void CTVSet::DeleteChannelName(const string& name)
{
    for (auto i = m_channelNames.begin(); i != m_channelNames.end(); ++i)
    {
        if (i->second == name)
        {
            m_channelNames.erase(i);
            cout << CHANNEL_NAME_DELETED_MSG;
            return;
        }
    }
    ShowError(cout, CHANNEL_NOT_EXIST_MSG);
}

void CTVSet::Info()
{
    cout << TV_IS << (m_isOn ? INFO_ON : INFO_OFF) << "\n";
    cout << INFO_CURRENT_CHANNEL << m_currentChannel << "\n";
    if (m_channelNames.find(m_currentChannel) != m_channelNames.end())
    {
        cout << INFO_CURRENT_CHANNEL_NAME;
        cout << m_channelNames[m_currentChannel] << "\n";
    }
    for (auto i = m_channelNames.begin(); i != m_channelNames.end(); ++i)
    {
        cout << i->first << DASH << i->second << "\n";
    }
}

bool CTVSet::GetIsOn()
{
    return m_isOn;
}

int CTVSet::GetCurrentChannel()
{
    return m_currentChannel;
}

int CTVSet::GetPreviousChannel()
{
    return m_previousChannel;
}
