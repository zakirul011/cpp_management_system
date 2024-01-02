#include <iostream>
#include <fstream> // File handling
#include <iomanip> // left, setw()
#include <cstring> // strcmp()
using namespace std;

// INITIALIZE VALIABLES
int option,
    found = 0,
    age;

char name[100],
    id[100],
    address[100],
    coach[100],
    game[100],
    mobile[100],
    space = '\t',
    searchText[100];

// FUNCTIONS

// TITLE FOR DISPLAY
void notify(string text)
{
    cout << "===================================" << endl
         << text << endl
         << "===================================" << endl;
}

// CLEAR THE SCREEN
void clear()
{
    system("CLS");
}

// STORE DATA IN FILE
void store()
{
    ofstream file;
    file.open("player.txt", ios::out | ios::app);
    file << name << space
         << id << space
         << age << space
         << address << space
         << mobile << space
         << game << space
         << coach << endl;

    clear();
    cout << "===================================" << endl
         << "Player " << name << " is successfully added." << endl
         << "===================================" << endl;

    file.close();
}

// TAKE INPUT FROM USER
void input()
{
    notify("Enter Details of the Player");

    cout << "\nName: ";
    cin >> name;

    cout << "\nID: ";
    cin >> id;

    cout << "\nAge: ";
    cin >> age;

    cout << "\nMobile No: ";
    cin >> mobile;

    cout << "\nAddress (City): ";
    cin >> address;

    cout << "\nGame: ";
    cin >> game;

    cout << "\nCoach  ";
    cin >> coach;
}

// DISPLAY SINGLE PLAYER
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
         << " :\t" << game << endl
         << left << setw(18) << "Coach Name"
         << " :\t" << coach << endl;
}

// DISPLAY ALL PLAYER OF DATABASE
void showAll()
{
    ifstream readFile;
    readFile.open("player.txt");
    found = 0;

    notify("Player List");

    if (!readFile)
    {
        notify("There is no Records");
    }
    else
    {
        readFile >> name >> id >> age >> address >> mobile >> game >> coach;
        while (!readFile.eof())
        {
            found++;
            cout << "===================================" << endl
                 << "Player no. " << found << endl
                 << "===================================" << endl;
            showSingle();
            readFile >> name >> id >> age >> address >> mobile >> game >> coach;
        }
        if (found == 0)
        {
            notify("There is no Records");
        }
    }

    readFile.close();
}

// MODIFY PLAYER
void modify(ofstream &file)
{
    if (strcmp(searchText, name) == 0 || strcmp(searchText, id) == 0)
    {
        found++;
        clear();
        input();
        file << name << space
             << id << space
             << age << space
             << address << space
             << mobile << space
             << game << space
             << coach << endl;

        clear();
        notify("Player is successfully Modified");
    }
    else
    {
        file << name << space
             << id << space
             << age << space
             << address << space
             << mobile << space
             << game << space
             << coach << endl;
    }
}

// REMOVE PLAYER
void remove(ofstream &file)
{
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
            file << name << space
                 << id << space
                 << age << space
                 << address << space
                 << mobile << space
                 << game << space
                 << coach << endl;
        }
    }
    else
    {
        file << name << space
             << id << space
             << age << space
             << address << space
             << mobile << space
             << game << space
             << coach << endl;
    }
}

void searchBy(ifstream &file, char *info)
{
    cout << ">> ";
    cin >> searchText;
    cout << "===================================" << endl
         << "Search Result for \"" << searchText << "\"" << endl
         << "===================================" << endl;
    while (!file.eof())
    {
        if (strcmp(searchText, info) == 0)
        {
            found++;
            cout << "===================================" << endl
                 << "Player " << found << endl
                 << "===================================" << endl;
            showSingle();
        }
        file >> name >> id >> age >> address >> mobile >> game >> coach;
    }
}

// SEARCH PLAYER
void search()
{
    notify("Search By ");
    cout << "1. Name" << endl
         << "2. ID" << endl
         << "3. Mobile No" << endl
         << "4. Addess (City)" << endl
         << "5. Game" << endl
         << "6. Coach" << endl
         << "Choose option >> ";
    cin >> option;
    clear();

    ifstream file("player.txt");
    found = 0;

    if (!file)
    {
        notify("There is no Records");
    }
    else
    {
        file >> name >> id >> age >> address >> mobile >> game >> coach;
        switch (option)
        {
        case 1:
            notify("Enter Player Name");
            searchBy(file, name);
            break;
        case 2:
            notify("Enter Player ID");
            searchBy(file, id);
            break;
        case 3:
            notify("Enter Player Mobile No");
            searchBy(file, mobile);
            break;
        case 4:
            notify("Enter Player Address (City)");
            searchBy(file, address);
            break;
        case 5:
            notify("Enter Name of the Game");
            searchBy(file, game);
            break;
        case 6:
            notify("Enter Coach Name");
            searchBy(file, coach);
            break;

        default:
            notify("Invalid Search Choice");
            break;
        }

        if (found == 0)
        {
            notify("Player Not found");
        }
    }

    file.close();
}

// ACTIONS DEPEND ON USER CHOICE
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
        file1 >> name >> id >> age >> address >> mobile >> game >> coach;
        while (!file1.eof())
        {
            switch (action)
            {
            case 1:
                // Modify by searched text
                modify(file2);
                break;
            case 2:
                // remove by searched text
                remove(file2);
                break;
            default:
                break;
            }

            file1 >> name >> id >> age >> address >> mobile >> game >> coach;
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

// RESET OR CLEAR THE DATABASE
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

// MAIN FUNCTION
int main()
{
    // WELCOME TEXT
    clear();
    notify("Welcome to Ground");

    while (1)
    {
        // MAINMENU
        cout << endl;
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

        // SHOW ACTION ON USER CHOICE
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
            actions(1); // modify
            break;
        case 4:
            actions(2); // remove
            break;
        case 5:
            search(); // search
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