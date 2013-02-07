#ifndef USER_H
#define USER_H
#include "mylist.h"

using namespace std;

class User{

public:
	User();
	User(string name, int age);
	User(int id, string name, int age,int zip); 
	User(int i);
	~User();
	void setAge(int age);
	void setName(string name);
	int getAge();
	string getName();
	void makeFriend(int x);
	int getZip();
	void setZip(int zip);
	void getFriends();
	void setId(int id);
	int getId();

private:
	string _name;
	int _age;
	int _zip;
	int _id;
	Mylist<int> friends;
	
};
#endif
