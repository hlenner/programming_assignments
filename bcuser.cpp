#ifndef bcuser_h
#define QUEUE_H
#include "bcuser.h"
#include "user.h"
#include "mylist.h"

using namespace std;

BCUser::BCUser() : User()
{
	
}
BCUser::BCUser(int i) : User(i)
{
	
}
BCUser::BCUser(string name, int age) : User(name, age)
{
	
}
BCUser::BCUser(int id, std::string name, int age, int zip): User(id, name, age, zip)
{
	
}
BCUser::~BCUser()
{

}
void BCUser:: clearPred()
{
	preds.clearList();
}

#endif
