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
User::User(int id, string name, int age,int zip)
{
	_name = name;
	_age = age;
	_id = id;
	_zip = zip;
}
User::~User()
{

}
string User:: getName()
{
	return _name;
}
int User:: getAge()
{
	return _age;
}
void User:: setName(string name)
{
	_name=name;
}
void User:: setAge(int age)
{
	_age=age;
}
int User:: getZip()
{
	return _zip;
}
void User:: setZip(int zip)
{
	_zip=zip;
}
void User:: makeFriend(int x)
{
	friends.push_back(x);
}
void User:: removeFriend(int x)
{
	friends.remove(x);
}
int User:: getId()
{
	return _id;
}
void User:: setId(int id)
{
	_id=id;
}
#endif
