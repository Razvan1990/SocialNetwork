
            #include<iostream>
            #include<vector>
            #include<list>
            #include"SocialNetwork.h"
            #include "User.h"
            #include"User.cpp"
            #include<algorithm>
            #pragma once

            using namespace std;

            SocialNetwork::SocialNetwork(){

            }

            SocialNetwork::SocialNetwork(string socialNetworkName_){
                socialNetworkName = socialNetworkName_;
                cout<<"Welcoime to "<<socialNetworkName<<endl;
            }

            void SocialNetwork::addUser(User u){
               u.setId(getMaxId());
                userList.push_back(u);
            }

            void SocialNetwork::addUserKeyboardInput(){
             
               User u;
            //new inputs
                string newName;
                int newAge;
                int newHeight;
                list<string> newFriends; list<string> newHobbies;
                int numberOfFriends; int numberOfHobbies;

               //u.setId(getMaxId());

                cout<<"Introduce the new name"<<endl;
                getline(cin>>ws, newName);

                for (int i =0;i<userList.size();i++){
                    while(userList[i].getName() ==  newName){
                        cout<<"A similar user already exists. Pick another user name "<<endl;
                        getline(cin>>ws, newName);
                    }
                }

                cout<<"Introduce the age. If you don't want to show your age please type 0"<<endl;
                cin>>newAge;

            // it is already processed in presentYourself based on the new valiue;

                cout<<"Introduce the height. If you don;t want to  show your height please type 0 "<<endl;
                cin>>newHeight;

                cout<<"Please introduce number of friends you would like to add. "<<endl;
                cin>>numberOfFriends;

                for (int i =0;i<numberOfFriends;i++){
                    string tempFriend;

                    cout<<"Introduce friend number "<<i<< " ";
                    getline(cin>>ws, tempFriend);
                    //introduce in the list
                    newFriends.emplace_back(tempFriend);
                }

                cout<<"Please introduce the number of hobbies you want to add "<<endl;
                cin>>numberOfHobbies;

            for (int i =0;i<numberOfHobbies;i++){
                string tempHobbies;
                cout<<"Introduce hobby number "<<i<<" ";
                getline(cin>>ws, tempHobbies);

                newHobbies.emplace_back(tempHobbies);
            }
                u.setId(getMaxId());
                u.setName(newName); u.setAge(newAge);u.setHeight(newHeight);u.setFriends(newFriends); u.setHobbies(newHobbies);
                userList.push_back(u);
                 
                cout<<"User added"<<endl;
                

            }

            void SocialNetwork::showNetwork(){
                for (int i =0;i<userList. size(); i++){
                    userList[i].presentYourself(userList[i].getName(), userList[i].getAge(), userList[i].getHeight(),
                    userList[i].getHobbies(), userList[i].getFriends());
                }
            }

            void SocialNetwork::deleteUser(){
                cout<<"Let's delete a user. Please enter the ID of the user "<<endl;
                int idToDelete;
                cin.clear();
                cin>>idToDelete;
                int sizeOfUsers = userList.size();

                for (int i =0;i<userList.size();i++){
                    if(userList[i].getId() == idToDelete){
                        cout<<"User has been deleted"<<endl;
                        cout<<"Details of the deleted user : ";userList[i].presentYourself(userList[i].getName(), userList[i].getAge(), userList[i].getHeight(),
                    userList[i].getHobbies(), userList[i].getFriends());
                        userList.erase(userList.begin()+i);
                        cout<<""<<endl;
                        break;


                    }
                }

                if(userList.size() == sizeOfUsers){
                    cout<<"We did not find this user "<<endl;
                }


            }

            void SocialNetwork::searchByUserName(){
                cout<<"What user are you looking for?"<<endl;
                string wantedUser;
                getline(cin>>ws, wantedUser);
                bool foundUser = false;

            for (int i =0;i<userList.size();i++){
                if(userList[i].getName() == wantedUser){
                    cout<<"User " <<i<<" with the following details"<<endl;
                    userList[i].presentYourself(userList[i].getName(), userList[i].getAge(), userList[i].getHeight(),
                    userList[i].getHobbies(), userList[i].getFriends());
                    foundUser = true;
                }
            }
            if (foundUser==false){
                cout<<"No such user on the network"<<endl;
            }
        }

        void SocialNetwork::searchByUserAge(){
                cout<<"What is the age of the user you are looking for?"<<endl;
                int wantedUserAge;
            cin.clear();
            cin>>wantedUserAge;

            while(wantedUserAge==0 || wantedUserAge>90){
                cout<<"Age is incorrect. Enter a correct age "<<endl;
                    cin.clear();
                    cin>>wantedUserAge;

            }
                bool foundUser = false;

            for (int i =0;i<userList.size();i++){
                if(userList[i].getAge()== wantedUserAge){
                    cout<<"User " <<i<<" with the following details"<<endl;
                    userList[i].presentYourself(userList[i].getName(), userList[i].getAge(), userList[i].getHeight(),
                    userList[i].getHobbies(), userList[i].getFriends());
                    foundUser = true;
                }
            }
            if (foundUser==false){
                cout<<"No such user on the network"<<endl;
            }
        }

        void SocialNetwork::searchUserByHobbies(){
            cout<<"What hobby are you looking for?"<<endl;
            string hobby;
            getline(cin>>ws, hobby);
            bool found  = false;

            for (int i =0;i<userList.size();i++){
                list<string>tempList = userList[i].getHobbies();
                list<string>::iterator itFind = find(tempList.begin(), tempList.end(), hobby);

                if(itFind!=tempList.end()){
                    cout<<"User "<<i<<" found with the following details"<<endl;
                    userList[i].presentYourself(userList[i].getName(), userList[i].getAge(), userList[i].getHeight(),
                    userList[i].getHobbies(), userList[i].getFriends());
                    found = true;
                }
                tempList.clear();
            }
            if(!found){
                cout<<"No user has this hobby"<<endl;
            }

        }

       int SocialNetwork::returnId(string isearchName){
           
            for (int i =0;i<userList.size();i++){
                if(userList[i].getName()==isearchName){
                int result = userList[i].getId();
                return result;
                }
            }
          
        }

        void SocialNetwork:: getFriendsOfUser(){
            vector<int>ids;
            string searchedUser;
            cout<<"Introduce the name of the user"<<endl;
            getline(cin>>ws, searchedUser);

            for(int i = 0;i<userList.size();i++){
                if(userList[i].getName() ==searchedUser){
                    list<string> friendsOfUser = userList[i].getFriends();
                    for(auto it = friendsOfUser.begin();it!=friendsOfUser.end(); it++){
                        ids.push_back(returnId(*it));
                    }
            
                    }
                }
                if(ids.size()==0){
                    cout<<" No friend of "<<searchedUser<<" in the social Network"<<endl;
                 return;
              
                }
                for(int i =0;i<ids.size();i++){
                    if(ids[i]==0){
                        ids.erase(remove(ids.begin(),ids.end(),ids[i]),ids.end());
                    }
                }
                cout<<"Friends found ";
                for(int i = 0;i<ids.size();i++){
                    cout<<ids[i] <<" ";
                }
            }

            int SocialNetwork::getMaxId(){
                int max = 0;

                for(int i =0;i<userList.size();i++){
                    if(userList[i].getId() >max){
                        max = userList[i].getId();
                    }
                }
                return max +1;
                
            }

        






            




