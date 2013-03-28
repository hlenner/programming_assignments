#include <iostream>
#include "gmlreader.h"
#include <vector>
#include <string>
#include "mylist.h"
#include "user.h"
#include "gmlwriter.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{/*
User x;
gmlwriter g;

if(argc < 4){
    cerr << "Please provide the input GML file name, command file name, and output file" << endl;
    return 1;
  }
	vector<string> nodes;
	vector<string> edges;
	string gml, command, output;
	Mylist<User*> users;

	if (GMLReader::read(argv[1], nodes, edges)){//reads the input file and puts info to nodes/edges
		//tests if it can open the file
	}
	else {
		cout << "Cannot open this Input GML file" << endl;//exits/quits program if it cannot open input file
		exit (EXIT_FAILURE);
	}	
	//code below creates a new user based on input information from the nodes vector and pushes that user into the users vector
	string name, first, last;
	int id, age, zip;
	string random;
	for (int i=0; i<4; i++){
		stringstream ss(nodes[i]);
		for (int x=0; x<4; x++){
			ss >> random;
			if (random == "id"){
				ss >> id;
			}
			if (random == "name"){
				ss >> first >> last;
				name = first +" "+ last;
			}
			if (random == "age"){
				ss >> age;
			}
			if (random == "zip"){
				ss >> zip;
			}
		}
		User* auser= new User(id, name, age, zip);
		users.push_back(auser);
	}
	//below this processes the edges(friend connections) of the users and creates links/friends based on these edges
	int source, friends;
	string definition;
	for (int i=0; i<edges.size();i++)
	{

		stringstream xx(edges[i]);
		xx >> definition;
		xx >> source;
		xx >> definition;
		xx >> friends;
		users.at(source)->makeFriend(friends);
	}
	//below this open the commands file(and tests if it can even be opened) and determines the number of lines in it through the linecount variable
	int linecount = 0;
	ifstream xfile(argv[2]);
	string line;
	if (xfile.is_open()){
		while(!xfile.eof()){
			getline(xfile, line);
			linecount++;
		}
		linecount = linecount-1;
	xfile.close();
	}
	else {
		cout << "Sorry the command file cannot be opened"<< endl;
	}
	//below deals with the commands file and adds/removes appropriate friends depending on the command/if they exist/if the formatting of the commands file is correct
	ifstream myfile(argv[2]);
	string lines;
	string aor;
	string first1, last1, first2, last2, friend1, friend2;
	
	for (int i=0; i<linecount; i++){	//linecount variable determined above
		myfile >> aor;
		myfile >> first1 >> last1;
		myfile >>first2>> last2;
		friend1= first1 + " " + last1;
		friend2= first2 + " " + last2;
		
		if (aor == "a"){
			for (int i=0; i<users.size(); i++){
				if (users.at(i)->getName()==friend1){
					for (int x=0; x<users.size(); x++){
						if (users.at(x)->getName()==friend2){
							users.at(i)->makeFriend(x);
							users.at(x)->makeFriend(i);
						}
					}
				}
			}
		}
		else if (aor == "r") {
	
		for (int i=0; i<users.size(); i++){
			if (users.at(i)->getName()==friend1){
				for (int j=0; j<users.size(); j++){
					if (users.at(j)->getName()==friend2){
							users.at(i)->removeFriend(j);
							users.at(j)->removeFriend(i);
						}
					}
   			}
		}
		}
	else {
	//this skips the line if it does not start with an "a" or an "r"
		}
	}
	g.write_friends(argv[3], users);//writes friends to a new file
  return 0;
*/}
	

