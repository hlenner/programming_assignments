//#ifndef GML_WRITER_H
//#define GML_WRITER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "gmlwriter.h"
#include "user.h"
#include "mylist.h"
#include "bcuser.h"
#include "BCAlg.h"

using namespace std;

gmlwriter::gmlwriter()
{

}
gmlwriter::~gmlwriter()
{

}

int gmlwriter:: write_friends(char * fname, Mylist<BCUser*> userList)
{
	int x = userList.size();
	
	ofstream ofile(fname);//takes input file
	if (ofile.is_open()){//tests if it is open
	ofile << "graph [" << endl;//formats the graph/node style(the next few lines do the same)
	ofile << "  This is the output file" << endl;
	ofile << "  directed 1" << endl;
	for (int i = 0; i< x; i++){
		ofile << "  " << "node [" << endl;
		int id = userList.at(i)->getId();//prints user id at i
		ofile << "  " << " id  " << id << endl;
		string name = userList.at(i)->getName();//prints user name at i
		ofile << "  " << " name  " << name << endl;
		int age= userList.at(i)->getAge();//prints user age at i
		ofile << "  " << " age  " <<  age << endl;
		int zip = userList.at(i)->getZip();//prints user zip at i
		ofile << "  " << " zip  " << zip << endl;
		ofile << "  ]" << endl;
	}
	for (int i=0; i< x; i++){
		for (int j=0; j<userList.at(i)->getFriendsSize(); j++){
			ofile << "  edge [" << endl;//formatting
			ofile << "   " << "source " << userList.at(i)->getId() <<endl;//gets the id of the user
			ofile <<  "   target " << userList.at(i)->getFriendAt(j) << endl;//gets the individual friends of that user
			ofile << "   ]" << endl;			
			}
		}
	}
return 0;
}
/*int gmlwriter:: print_bc(char * fname, Mylist<BCUser*> userList){
	int x = userList.size();
	ofstream ofile(fname);//takes input file
	if (ofile.is_open()){//tests if it is open
		for (int i=0; i<x; i++){
			int id= userList.at(i)->getID();
			cout << "id:  " << id << endl;
			cout<< "bc: " << userList.at(i)->bc << endl;
		}
	}
	return 0;
}*/
//#endif
