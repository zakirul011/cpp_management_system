#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int option,
    age,
    found = 0;

char name[50],
    id[50],
    address[50],
    coachName[50],
    gameName[50],
    mobile[50],
    space = '\t',
    searchText[50];

void notify(string text)
{
    cout << "===================================" << endl
         << text << endl
         << "===================================" << endl;
}

void clear()
{
    system("CLS");
}

void store()
{
    ofstream file;
    file.open("player.txt", ios::out | ios::app);
    file << name << space
         << id << space
         << age << space
         << address << space
         << mobile << space
         << gameName << space
         << coachName << endl;

    clear();
    cout << "===================================" << endl
         << "Player " << name << " is successfully added." << endl
         << "===================================" << endl;

    file.close();
}

void input()
{
    cout << "===================================" << endl
         << "Enter Details of the Player" << endl
         << "===================================" << endl;

    cout << "\nPlayer Name: ";
    cin >> name;

    cout << "\nPlayer ID: ";
    cin >> id;

    cout << "\nPlayer Age: ";
    cin >> age;

    cout << "\nPlayer Mobile No: ";
    cin >> mobile;

    cout << "\nPlayer Address (City): ";
    cin >> address;

    cout << "\nGame Name: ";
    cin >> gameName;

    cout << "\nPlayer's Coach Name: ";
    cin >> coachName;
}

void showSingle()
{
    cout << left << setw(18) << "Player Name:"
         << " :\t" << name << endl
         << left << setw(18) << "Player ID"
         << " :\t" << id << endl
         << left << setw(18) << "Player Age"
         << " :\t" << age << endl
         << left << setw(18) << "Address (City)"
         << " :\t" << address << endl
         << left << setw(18) << "Mobile No"
         << " :\t" << mobile << endl
         << left << setw(18) << "Game Name"
         << " :\t" << gameName << endl
         << left << setw(18) << "Coach Name"
         << " :\t" << coachName << endl
         << left << setw(18) << endl;
}

void showAll()
{
    ifstream readFile;
    readFile.open("player.txt");
    found = 0;

    notify("All Player List");

    if (!readFile)
    {
        notify("There is no Records");
    }
    else
    {
        readFile >> name >> id >> age >> address >> mobile >> gameName >> coachName;
        while (!readFile.eof())
        {
            found++;
            cout << "===================================" << endl
                 << "Player no. " << found << endl
                 << "===================================" << endl;
            showSingle();
            readFile >> name >> id >> age >> address >> mobile >> gameName >> coachName;
        }
        if (found == 0)
        {
            notify("There is no Records");
        }
    }

    readFile.close();
}

void actions(int action)
{
    notify("Enter Player Name or ID");
    cout << ">> ";
    cin >> searchText;

    ifstream file1("player.txt");
    ofstream file2("temp.txt");
    found = 0;

    if (!file1)
    {
        notify("There is no Records");
    }
    else
    {
        file1 >> name >> id >> age >> address >> mobile >> gameName >> coachName;
        while (!file1.eof())
        {
            switch (action)
            {
            case 1:
                // Modify by searched text
                if (strcmp(searchText, name) == 0 || strcmp(searchText, id) == 0)
                {
                    found++;
                    clear();
                    input();
                    file2 << name << space
                          << id << space
                          << age << space
                          << address << space
                          << mobile << space
                          << gameName << space
                          << coachName << endl;

                    clear();
                    notify("Player is successfully Modified");
                }
                else
                {
                    file2 << name << space
                          << id << space
                          << age << space
                          << address << space
                          << mobile << space
                          << gameName << space
                          << coachName << endl;
                }
                break;
            case 2:
                // remove by searched text
                if (strcmp(searchText, name) == 0 || strcmp(searchText, id) == 0)
                {
                    found++;
                    clear();
                    cout << "Are you sure to remove the player " << searchText << "?" << endl
                         << "1. Yes" << endl
                         << "2. No" << endl
                         << ">> ";
                    cin >> option;
                    if (option == 1)
                    {
                        clear();
                        notify("Player is successfully removed");
                    }
                    else
                    {
                        file2 << name << space
                              << id << space
                              << age << space
                              << address << space
                              << mobile << space
                              << gameName << space
                              << coachName << endl;
                    }
                }
                else
                {
                    file2 << name << space
                          << id << space
                          << age << space
                          << address << space
                          << mobile << space
                          << gameName << space
                          << coachName << endl;
                }
                break;
            case 3:
                // search by searched text
                if (strcmp(searchText, name) == 0 || strcmp(searchText, id) == 0)
                {
                    found++;
                    notify("Searched Player Information");
                    showSingle();
                    file2 << name << space
                          << id << space
                          << age << space
                          << address << space
                          << mobile << space
                          << gameName << space
                          << coachName << endl;
                }
                else
                {
                    file2 << name << space
                          << id << space
                          << age << space
                          << address << space
                          << mobile << space
                          << gameName << space
                          << coachName << endl;
                }

            default:
                break;
            }

            file1 >> name >> id >> age >> address >> mobile >> gameName >> coachName;
        }
        if (found == 0)
        {
            notify("Player Not found");
        }
    }

    file1.close();
    file2.close();
    remove("player.txt");
    rename("temp.txt", "player.txt");
}

void removeAll()
{
    cout << "Are you sure to remove all players?" << endl
         << "1. Yes" << endl
         << "2. No" << endl
         << ">> ";
    cin >> option;
    if (option == 1)
    {
        remove("player.txt");
        ofstream writeFile("player.txt");
        writeFile.close();
        clear();
        notify("Player record has been reset");
    }
}

int main()
{
    clear();
    notify("Welcome to Ground");

    while (1)
    {
        notify("SPORTS MANAGEMENT MENU");
        cout << "1. Display All Players" << endl
             << "2. Add New Player" << endl
             << "3. Modify Player" << endl
             << "4. Remove Player" << endl
             << "5. Search Player" << endl
             << "6. Remove All Players" << endl
             << "7. Clear screen" << endl
             << "0. Exit" << endl
             << "Choose option >> ";
        cin >> option;
        clear();

        switch (option)
        {
        case 1:
            showAll();
            break;
        case 2:
            input();
            store();
            break;
        case 3:
            actions(1);
            break;
        case 4:
            actions(2);
            break;
        case 5:
            actions(3);
            break;
        case 6:
            removeAll();
            break;
        case 7:
            clear();
            break;
        case 0:
            exit(0);
            break;
        default:
            notify("Invalid choice. Please select from the menu");
            break;
        }
    }

    return 0;
}