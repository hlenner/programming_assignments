#ifndef BCUSER_H
#define BCUSER_H
#include "user.h"
#include "mylist.h"

using namespace std;

class BCUser: public User{
public:
	BCUser();
	BCUser(string name, int age);
	BCUser(int id, string name, int age,int zip); 
	BCUser(int i);
	~BCUser();
	int dist; //distance to current source vertex
	int numsp; //number of shortest paths
	Mylist<int> preds; //List of predecessors
	double delta; //partial BC score
	double bc; //total BC score
	//Mylist<double>* computeBC(MyList<BCUser*> &userList);
private:

	};

#endif
