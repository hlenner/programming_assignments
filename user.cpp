#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "user.h"



using namespace std; 

User::User()
{
	
}
User::User(int i)
{
	
}
User::User(string name, int age)
{
	_name = name;
	_age = age;
}
User::User(int id, string name, int age,int zip)//used in sn.cpp to push back new users to <User*> users from input file
{
	_name = name;
	_age = age;
	_id = id;
	_zip = zip;
}
User::~User()
{

}
string User:: getName()//accesor to return name
{
	return _name;
}
int User:: getAge()//accesor to return name
{
	return _age;
}

int User::getFriendAt(int i)//accesor to return name
{	
	
	return friends.at(i);
}

void User:: setName(string name)//mutator to set the name
{
	_name=name;
}
void User:: setAge(int age)//mutator to set the age
{
	_age=age;
}
int User:: getZip()//accesor to return name
{
	return _zip;
}
void User:: setZip(int zip)//mutator to set the zip
{
	_zip=zip;
}
void User:: makeFriend(int x)//adds id to friend mylist
{

	friends.push_back(x);
}
void User:: removeFriend(int x)//remove the friend, calls to mylist remove
{
	friends.remove(x);
}
int User:: getId()//accesor to return id
{
	return _id;
}
void User:: setId(int id)//mutator to set id
{
	_id=id;
}
int User:: getFriendsSize()//accesor to return size of friends 
{
	return friends.size();
}
Mylist<int> User:: getFriends()//accesor to return friends mylist item
{
	return friends;
}
#endif
