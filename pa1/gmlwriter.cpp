//#ifndef GML_WRITER_H
//#define GML_WRITER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "gmlwriter.h"



using namespace std;

gmlwriter::gmlwriter()
{

}
gmlwriter::~gmlwriter(){

}

int gmlwriter:: write_friends(char * fname, Mylist<User*> users, vector<string> edges, vector<string> nodes)
{
	int x = users.size();
	int y = edges.size();
	ofstream ofile(fname);
	if (ofile.is_open()){
	ofile << "graph [" << endl;
	ofile << "  This is the output file" << endl;
	ofile << "  directed 1" << endl;
	for (int i =0; i< x; i++){
		ofile << "  " << "node [" << endl;
		int id = users.at(i)->getId();
		ofile << "  " << " id  " << id << endl;
		string name = users.at(i)->getName();
		ofile << "  " << " name  " << name << endl;
		int age= users.at(i)->getAge();
		ofile << "  " << " age  " <<  age << endl;
		int zip = users.at(i)->getZip();
		ofile << "  " << " zip  " << zip << endl;
		ofile << "  ]" << endl;
	}
	int source, friends;
	string name1, name2;
	for (int i=0; i< y; i++){
		ofile << "  edge [" << endl;
		stringstream xx(edges[i]);
		xx >> name1;
		xx >> source;
		xx >> name2;
		xx >> friends;
		ofile << "     " <<  name1 << source << endl;
		ofile << "     " <<  name2 << friends << endl;
		ofile << "   ]" << endl;
		}
	ofile << "]" << endl;
	}
	return 0;
}
//#endif
