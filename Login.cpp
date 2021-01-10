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

int main()
{
}