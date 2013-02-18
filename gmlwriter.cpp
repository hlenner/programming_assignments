//#ifndef GML_WRITER_H
//#define GML_WRITER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "gmlwriter.h"
#include "user.h"
#include "mylist.h"

using namespace std;

gmlwriter::gmlwriter()
{

}
gmlwriter::~gmlwriter(){

}

int gmlwriter:: write_friends(char * fname, Mylist<User*> users)
{
	int x = users.size();
	
	ofstream ofile(fname);//takes input file
	if (ofile.is_open()){//tests if it is open
	ofile << "graph [" << endl;//formats the graph/node style(the next few lines do the same)
	ofile << "  This is the output file" << endl;
	ofile << "  directed 1" << endl;
	for (int i = 0; i< x; i++){
		ofile << "  " << "node [" << endl;
		int id = users.at(i)->getId();//prints user id at i
		ofile << "  " << " id  " << id << endl;
		string name = users.at(i)->getName();//prints user name at i
		ofile << "  " << " name  " << name << endl;
		int age= users.at(i)->getAge();//prints user age at i
		ofile << "  " << " age  " <<  age << endl;
		int zip = users.at(i)->getZip();//prints user zip at i
		ofile << "  " << " zip  " << zip << endl;
		ofile << "  ]" << endl;
	}
	for (int i=0; i< x; i++){
		for (int j=0; j<users.at(i)->getFriendsSize(); j++){
			ofile << "  edge [" << endl;//formatting
			ofile << "   " << "source " << users.at(i)->getId() <<endl;//gets the id of the user
			ofile <<  "   target " << users.at(i)->getFriendAt(j) << endl;//gets the individual friends of that user
			ofile << "   ]" << endl;			
			}
		}
	}
return 0;
}
//#endif
