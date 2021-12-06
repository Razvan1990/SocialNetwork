#include <iostream>
#include "User.h"
#include "User.cpp"
#include "SocialNetwork.cpp"
#include "SocialNetwork.h"
#include "Work.h"
#include <vector>
#pragma once
#include <list>
#include <typeinfo>
#include <limits>
#include <bits/stdc++.h>

using namespace std;

Work::Work() {}

void Work::runApplication()
{
    list<string> f1;
    list<string> f2;
    list<string> h1;
    list<string> h2;
    list<string> f3;
    list<string> h3;

    f1.push_back("Di Maria");
    f1.push_back("Paredes");
    f1.push_back("Neymar");
    h1.push_back("Football");
    h1.push_back("Dogs");
    h1.push_back("Travelling");

    f2.push_back("Ramos");
    f2.push_back("Bernardo Silva");
    f2.push_back("Jean");
    h2.push_back("Penalties");
    h2.push_back("Shopping");
    h2.push_back("going with the yacht");
    // set1
    f3.push_back("Messi");
    f3.push_back("Aguero");
    f3.push_back("Draxler");
    h3.push_back("Pasta");
    h3.push_back("Reading");
    h3.push_back("fifa 22");

    User u1;
    User u2("Killian Mbappe");
    User u3("Lewandowski");

    u1.setAge(34);
    u1.setHeight(170);
    u1.setGender('M');
    u1.setName("Messi");
    u1.setFriends(f1);
    u1.setHobbies(h1);
    // u1.presentYourself(u1.getName(),u1.getAge(),u1.getHeight(),u1.getHobbies(), u1.getFriends());
    // u2.presentYourself(u2.getName(),u2.getAge(),u2.getHeight(),u2.getHobbies(), u2.getFriends());
    // u3.presentYourself(u3.getName(),u3.getAge(),u3.getHeight(),u3.getHobbies(), u3.getFriends());

    User u4;
    u4.setAge(37);
    u4.setHeight(187);
    u4.setGender('M');
    u4.setName("Ronaldo");
    u4.setFriends(f2);
    u4.setHobbies(h2);
    // u4.presentYourself(u4.getName(),u4.getAge(),u4.getHeight(),u4.getHobbies(), u4.getFriends());

    u2.setAge(23);
    // u2.presentYourself(u2.getName(),u2.getAge(),u2.getHeight(),u2.getHobbies(), u2.getFriends());
    User u5;
    u5.setAge(33);
    u5.setHeight(174);
    u5.setGender('M');
    u5.setName("Di Maria");
    u5.setFriends(f3);
    u5.setHobbies(h3);

    SocialNetwork s("Facebook 2.99 alfa-beta");
    s.addUser(u1);
    s.addUser(u2);
    s.addUser(u3);
    s.addUser(u4);
    s.addUser(u5);

    bool continueProgram = true;

    while (continueProgram)
    {
        cout << "What option would you like to choose" << endl;
        cin.clear();
        cout << "1. Show Social Network" << endl;
        cout << "2. Add user on Social Network" << endl;
        cout << "3. Delete user on Social Network" << endl;
        cout << "4. Get the friends of the user" << endl;
        cout << "5. Search a user in the storyboard" << endl;

        int numberChoose;
        cin >> numberChoose;

        while (1)
        {
            if (cin.fail())
            {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the number" << endl;
                cin >> numberChoose;
            }
            if (!cin.fail())
            {
                break;
            }
        }

        switch (numberChoose)
        {
        case 1:
            s.showNetwork();
            break;
        case 2:
            s.addUserKeyboardInput();
            break;
        case 3:
            s.deleteUser();
            break;
        case 4:
            s.getFriendsOfUser();
            break;

        case 5:

            cout << "1. Search by user name" << endl;
            cout << "2. Search by user age" << endl;
            cout << "3. Search by user hobbies" << endl;

            int secondOption;
            cin >> secondOption;

            while (1)
            {
                if (cin.fail())
                {

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter the number" << endl;
                    cin >> secondOption;
                }
                if (!cin.fail())
                {
                    break;
                }
            }

            switch (secondOption)
            {
            case 1:
                s.searchByUserName();
                break;
            case 2:
                s.searchByUserAge();
                break;
            case 3:
                s.searchUserByHobbies();
                break;
            }
            break;

        default:
            cout << "No such option" << endl;
            break;
        }

        cout << "Do you use to continue? 1 - for yes and 0 for no" << endl;
        int continueOption;
        cin >> continueOption;

        while (1)
        {
            if (cin.fail())
            {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter the number" << endl;
                cin >> continueOption;
            }
            if (!cin.fail())
            {
                break;
            }
        }

        if (continueOption == 1)
        {
            continue;
        }
        else
        {
            continueProgram = false;
        }
    }
}

    Work::~Work()
    {
        cout << "Our Social network was deleted" <<endl;
    }
