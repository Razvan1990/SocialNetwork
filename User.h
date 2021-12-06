
#ifndef USER_H
#define USER_H

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<list>

using namespace std;


class User{

private:

    string name;
    int age;
    int height;
    list<string> hobbies;
    char gender;
    int id =0;
    list<string> friends;
    int nrId = 0;
    int getNextId();
    vector<int>ids;
   
  //  set<User> users;

public:
  
    User();
    User(string name);
    //getters
    string getName();
    int getAge();
    int getId();
    //int getNextId();
    char getGender();
    list<string>getHobbies();
    list<string>getFriends();
    int getHeight();
    //setters
    void setName(string name);
    void setAge(int age);
    void setId(int id);
    void setHeight(int height);
    void setGender(char gender);
    void setHobbies(list<string>hobbies);
    void setFriends(list<string>friends);
    void presentYourself(string name, int age,int height, list<string> hobbies, list<string>friends);
    void outputList(list<string>mySet);
    void checkAge(int age);void checkHeight(int height);
    
};


#endif