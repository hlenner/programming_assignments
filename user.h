#ifndef USER_H
#define USER_H
#include "mylist.h"

using namespace std;

class User{

public:
	User();
	User(string name, int age);
	User(int i);
	~User();
	void setAge(int age);
	void setName(string name);
	int getAge();
	string getName();
	//void addFriend(string s);
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
	mylist<int> friends;
	
};
#endif
