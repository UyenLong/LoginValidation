#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void getLoginInforFromConsole(string &username, string &password)
{
    cin.ignore();
    cout << "Enter username: " << endl;
    getline(cin, username);
    cin.ignore();
    cout << "Enter password: " << endl;
    getline(cin, password);
}

void printfLoginInfor(string username, string password)
{
    cout << "Your username: " << username << endl;
    cout << "Your password: " << password << endl;
}

map<string, string> getListOfAccountsFromTextFile(string fileName)
{
    map<string, string> listOfAccounts;
    ifstream fileText;
    fileText.open(fileName);
    string accountInfo;
    while (getline(fileText, accountInfo))
    {
        size_t spaceCharacter = accountInfo.find(" ");
        listOfAccounts[accountInfo.substr(0, spaceCharacter)] = accountInfo.substr(spaceCharacter + 1);
    }
    fileText.close();
    return listOfAccounts;
}

bool isValidAccount(string username, string password, map<string, string> listOfAccounts)
{
    bool isValid = false;
    map<string, string>::iterator account;
    for (account = listOfAccounts.begin(); account != listOfAccounts.end(); ++account)
    {
        if (account->first == username && account->second == password)
        {
            isValid = true;
            break;
        }
    }
    return isValid;
}

int main()
{
    string username, password;
    string isTryAgain;
    do
    {
        getLoginInforFromConsole(username, password);
        cout << "The information you have just entered: " << endl;
        printfLoginInfor(username, password);
        map<string, string> lstOfAccounts = getListOfAccountsFromTextFile("accountInfo.txt");
        if (isValidAccount(username, password, lstOfAccounts))
        {
            cout << "You are authorized to login!" << endl;
        }
        else
        {
            cout << "Fail to login..." << endl
                 << "Please enter valid account!" << endl
                 << "Do you want to try again?" << endl
                 << "Please enter \"ok\" to try again. Press any characters to exit..." << endl;
            cin >> isTryAgain;
        }
    } while (isTryAgain == "ok");
}