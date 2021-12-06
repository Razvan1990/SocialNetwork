
#include<iostream>
#include<set>
#include "User.h"
#include<list>
#pragma once

using namespace std;

static int incrementer= 1;

User::User(){
    age = 0; height = 0;
 // this->id = incrementer++;
  //ids.push_back(getNextId());
  //setId(getNextId());

    
   
    
}

User::User(string aname){
    name = aname;
    age = 0; height = 0;  
    //this->id = incrementer++;
      //ids.push_back(getNextId());
 // setId(getNextId());
  
}
//getter implementation
string User::getName(){
    return this->name;
}
int User::getId(){
    return this-> id;
}
int User::getAge(){
    return this -> age;
}
int User::getHeight(){
    return this -> height;
}
char User::getGender(){
    return this -> gender;
}
list<string> User::getHobbies(){
    return this -> hobbies;
}
list<string>User::getFriends(){
    return this -> friends;
}
//setter implementation

void User::setId(int aid){
    id = aid;
}

void User::setName(string aname){
    name = aname;
}
void User::setAge(int aage){
    age = aage;
}

void User::setHeight(int aheight){
    height = aheight;
}
void User::setFriends(list<string>afriends){
    friends = afriends;
}
void User::setHobbies(list<string>ahobbies){
    hobbies = ahobbies;
}
// void User::setId(){
//     id = nrId++;
// }
void User::setGender(char agender ){
    gender = agender;
}

void User::outputList(list<string>myList){
    for (auto it = myList.begin();it!= myList.end();it++){
        if(it!=myList.end() && next(it)==myList.end()){
            cout<<*it<<" ";
        }else{
            cout<<*it<<" ,";
        }
    }
}

void User::checkAge(int age){
    if(age ==0){
        cout<<"User did not mention age ";
    }else{
        age = getAge();
        cout<<age<<" ";
    }
}

void User::checkHeight(int height){
    if(height ==0){
        cout<<"User did not mention height ";
    }else{
        height = getHeight();
        cout<<height<<" ";
    }
}





int User::getNextId(){
    int max = 0;
    for(int i =0;i<ids.size();i++){
        if(ids[i]>max){
            max = ids[i];
        }
    }
return max+1;
        
}

void User::presentYourself(string name, int age,int height,list<string>hobbies, list<string>friends){
    cout<<"Id NUMBER: "<<getId()<< " NAME "<<name<<" and has following attributes  " ;
   cout<<"AGE "; checkAge(age);cout<<"HEIGHT ";checkHeight(height);cout<<" has the following HOBBIES  [";
    outputList(hobbies);cout<< " ] and the following FRIENDS [ ";
    outputList(friends);
    cout<<"]"<<endl;
        
}





















