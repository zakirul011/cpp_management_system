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
void title(string text)
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

// TAKE INPUT FROM USER
void input()
{
    title("Enter Details of the Player");

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

    cout << "\nCoach: ";
    cin >> coach;
}

// STORE DATA IN FILE
void store()
{
    ofstream file;
    file.open("player.txt", ios::out | ios::app);
    file << name << space
         << id << space
         << age << space
         << mobile << space
         << address << space
         << game << space
         << coach << endl;

    clear();
    cout << "===================================" << endl
         << "Player " << name << " is successfully added." << endl
         << "===================================" << endl;

    file.close();
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
         << left << setw(18) << "Mobile No"
         << " :\t" << mobile << endl
         << left << setw(18) << "Address (City)"
         << " :\t" << address << endl
         << left << setw(18) << "Game"
         << " :\t" << game << endl
         << left << setw(18) << "Coach"
         << " :\t" << coach << endl;
}

// DISPLAY ALL PLAYER OF DATABASE
void showAll()
{
    ifstream file;
    file.open("player.txt");
    found = 0;

    title("Player List");

    if (!file)
    {
        title("There are no Records");
    }
    else
    {
        file >> name >> id >> age >> mobile >> address >> game >> coach;
        while (!file.eof())
        {
            found++;
            cout << "===================================" << endl
                 << "Player no. " << found << endl
                 << "===================================" << endl;
            showSingle();
            file >> name >> id >> age >> mobile >> address >> game >> coach;
        }
        if (found == 0)
        {
            title("There are no Records");
        }
    }

    file.close();
}

// SEARCH BY PLAYER INFO
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
        file >> name >> id >> age >> mobile >> address >> game >> coach;
    }
}

// SEARCH PLAYER
void search()
{
    title("Search By ");
    cout << "1. Name" << endl
         << "2. ID" << endl
         << "3. Mobile No" << endl
         << "4. Address (City)" << endl
         << "5. Game" << endl
         << "6. Coach" << endl
         << "Choose option >> ";
    cin >> option;
    clear();

    ifstream file("player.txt");
    found = 0;

    if (!file)
    {
        title("There is no Records");
    }
    else
    {
        file >> name >> id >> age >> mobile >> address >> game >> coach;
        switch (option)
        {
        case 1:
            title("Enter Player Name");
            searchBy(file, name);
            break;
        case 2:
            title("Enter Player ID");
            searchBy(file, id);
            break;
        case 3:
            title("Enter Player Mobile No");
            searchBy(file, mobile);
            break;
        case 4:
            title("Enter Player Address (City)");
            searchBy(file, address);
            break;
        case 5:
            title("Enter Name of the Game");
            searchBy(file, game);
            break;
        case 6:
            title("Enter Coach Name");
            searchBy(file, coach);
            break;

        default:
            title("Invalid Choice for Search");
            break;
        }

        if (found == 0)
        {
            title("Player Not found");
        }
    }

    file.close();
}

// REMOVE PLAYER
void remove()
{
    title("Enter Player Name or ID");
    cout << ">> ";
    cin >> searchText;

    ifstream file1("player.txt");
    ofstream file2("temp.txt");
    found = 0;

    if (!file1)
    {
        title("There is no Records");
    }
    else
    {
        file1 >> name >> id >> age >> mobile >> address >> game >> coach;
        while (!file1.eof())
        {
            if (strcmp(searchText, name) == 0 || strcmp(searchText, id) == 0)
            {
                found++;
                clear();
                cout << "Are you sure to remove the player \"" << searchText << "\"?" << endl
                     << "1. Yes" << endl
                     << "2. No" << endl
                     << "Choose option >> ";
                cin >> option;
                if (option == 1)
                {
                    clear();
                    title("Player is successfully removed");
                }
                else
                {
                    file2 << name << space
                          << id << space
                          << age << space
                          << mobile << space
                          << address << space
                          << game << space
                          << coach << endl;
                }
            }
            else
            {
                file2 << name << space
                      << id << space
                      << age << space
                      << mobile << space
                      << address << space
                      << game << space
                      << coach << endl;
            }

            file1 >> name >> id >> age >> mobile >> address >> game >> coach;
        }
        if (found == 0)
        {
            title("Player Not found");
        }
    }

    file1.close();
    file2.close();
    remove("player.txt");
    rename("temp.txt", "player.txt");
}

// MODIFY PLAYER
void modify()
{
    title("Enter Player Name or ID");
    cout << ">> ";
    cin >> searchText;

    ifstream file1("player.txt");
    ofstream file2("temp.txt");
    found = 0;

    if (!file1)
    {
        title("There is no Records");
    }
    else
    {
        file1 >> name >> id >> age >> mobile >> address >> game >> coach;
        while (!file1.eof())
        {
            if (strcmp(searchText, name) == 0 || strcmp(searchText, id) == 0)
            {
                found++;
                clear();

                cout << "===================================" << endl
                     << "What do you want to Modify for \"" << searchText << "\"?" << endl
                     << "===================================" << endl;
                cout << "1. Name" << endl
                     << "2. ID" << endl
                     << "3. Age" << endl
                     << "4. Mobile No" << endl
                     << "5. Addess (City)" << endl
                     << "6. Game" << endl
                     << "7. Coach" << endl
                     << "Choose option >> ";
                cin >> option;

                switch (option)
                {
                case 1:
                    cout << "\nEnter modified Name: ";
                    cin >> name;
                    break;
                case 2:
                    cout << "\nEnter modified ID: ";
                    cin >> id;
                    break;
                case 3:
                    cout << "\nEnter modified Age: ";
                    cin >> age;
                    break;
                case 4:
                    cout << "\nEnter modified Mobile no: ";
                    cin >> mobile;
                    break;
                case 5:
                    cout << "\nEnter modified Address (city): ";
                    cin >> address;
                    break;
                case 6:
                    cout << "\nEnter modified Game: ";
                    cin >> game;
                    break;
                case 7:
                    cout << "\nEnter modified Coach: ";
                    cin >> coach;
                    break;
                default:
                    title("Invalid Choice for Modify");
                    break;
                }

                file2 << name << space
                      << id << space
                      << age << space
                      << mobile << space
                      << address << space
                      << game << space
                      << coach << endl;

                clear();
                title("Player is successfully Modified");
            }
            else
            {
                file2 << name << space
                      << id << space
                      << age << space
                      << mobile << space
                      << address << space
                      << game << space
                      << coach << endl;
            }

            file1 >> name >> id >> age >> mobile >> address >> game >> coach;
        }
        if (found == 0)
        {
            title("Player Not found");
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
         << "Choose option >> ";
    cin >> option;
    if (option == 1)
    {
        remove("player.txt");
        ofstream writeFile("player.txt");
        writeFile.close();
        clear();
        title("Player record has been reset");
    }
}

// MAIN FUNCTION
int main()
{
    // WELCOME TEXT
    clear();
    title("Welcome to Ground");

    while (1)
    {
        // MAINMENU
        cout << endl;
        title("SPORTS MANAGEMENT MENU");
        cout << "1. Display All Players" << endl
             << "2. Add New Player" << endl
             << "3. Modify Player" << endl
             << "4. Remove Player" << endl
             << "5. Search Player" << endl
             << "6. Remove All Players" << endl
             << "7. Clear Screen" << endl
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
            modify(); // modify
            break;
        case 4:
            remove(); // remove
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
            title("Invalid choice... \nPlease select option from the menu...");
            break;
        }
    }

    return 0;
}