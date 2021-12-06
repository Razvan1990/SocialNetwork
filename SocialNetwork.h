#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H


#include<iostream>
#include<list>
#include<vector>
#include<string>
#include "User.h"
#include "User.cpp"
#pragma once

class SocialNetwork:public User{

    string socialNetworkName;
    vector<User> userList;
    //implement this to use in getFriends
   int returnId(string name);

    public:

        SocialNetwork();
        SocialNetwork (string socialNetName);
        void addUser(User u);
        void addUserKeyboardInput();
        void deleteUser();
        void searchByUserName();
        void searchByUserAge();
        void searchUserByHobbies();
        void getFriendsOfUser();
        void showNetwork();
        int getMaxId();

};
#endif
