# SPORTS MANAGEMENT SYSTEM

# Features (8) :

    1. Display All Players
    2. Add New Player
        a. Name
        b. ID
        c. Age
        d. Mobile
        e. Address
        f. Game
        g. Coach
    3. Modify Player
        a. Modify Name
        b. Modify ID
        c. Modify Age
        d. Modify Mobile
        e. Modify Address
        f. Modify Game
        g. Modify Coach
    4. Remove Player
    5. Search Player
        a. Search by Name
        b. Search by ID
        c. Search by Mobile
        d. Search by Address
        e. Search by Game
        f. Search by Coach
    6. Remove All Players
    7. Clear Screen
    0. Exit

# Variables (11):

## Basic variable (4)

    option
    found
    space
    searchText

## Player variable (7)

    name
    id
    age
    mobile
    address
    coach
    game

# Function (11):

## User Interface (2)

    title()
    clear()

## Player function (9)

    input()
    store()
    showSingle()
    showAll()
    Mofify()
    Remove()
    searchBy()
    search()
    removeAll()

# Function Connectivity for features

## Display All Players

### showAll()

    Loop -> showSingle()

## Add New Player

    input()
    store()

## Modify Player

    modify()

## Remove Player

    remove()

## Search Player

### search()

    searchBy()

## Remove All Players

    removeAll()

## Clear Screen

    clear()

## Exit

    exit(0)
