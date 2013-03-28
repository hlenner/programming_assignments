#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <User.cpp>
//unbounded dynamic array
using namespace std;

class List{

public:
	List();
	~List();
	void push_back(int val);
	int size() const;
	string at(int loc) const;
	
private:
	string *items;	
	int size;
	int capacity;
};

List::List()
{
	size=0;
	items= new string[size];
}
List:: ~List()
{
	delete [] items;
}
void List:: push_back(User* name)
{
	
	items[size]=name;
	size++;
}
int List:: size() const
{
	return size;
}
string List:: at(int loc) const
{
	return *items[loc-1];
}
