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
int gmlwriter:: write_friends(char * fname, Mylist<User*> users)
{
	int x = users.size();
	ofstream ofile(fname);
	if (ofile.is_open()){
	ofile << "graph [" << endl;
	ofile << "  directed 1" << endl;
	for (int i =0; i< x; i++){
		cout << "  " << "node  [" << endl;
		int id = users.at(i)->getId();
		ofile << '\t' << "id   " << id << endl;
		string name = users.at(i)->getName();
		ofile << '\t' << "name   " << name << endl;
		int age= users.at(i)->getAge();
		ofile << '\t' <<"age   " <<  age << endl;
		int zip = users.at(i)->getZip();
		ofile << '\t' << "zip   " << zip << endl;
		}
	}
	/*for (int i=0; i< ; i++){
		cout << "edge  [" << endl;
		cout << '\t' << "source  " __ << endl;
		cout << '\t' << "target  " __ << endl;
	}*/
	return 0;
}
//#endif
