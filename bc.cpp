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
#include "bcuser.h"

using namespace std;

int main(int argc, char *argv[])
{
BCUser x;
gmlwriter g;

if(argc < 3){
    cerr << "Please provide the input GML file name and output file" << endl;
    return 1;
  }
	vector<string> nodes;
	vector<string> edges;
	string gml, output;
	Mylist<BCUser*> userList;

	if (GMLReader::read(argv[1], nodes, edges)){//reads the input file and puts info to nodes/edges
		//tests if it can open the file
	}
	else {
		cout << "Cannot open this Input GML file" << endl;//exits/quits program if it cannot open input file
		exit (EXIT_FAILURE);
	}	
	string name, first, last;
	int id, age, zip;
	string random;
	for (int i=0; i<nodes.size(); i++){
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
		BCUser* auser= new BCUser(id, name, age, zip);
		userList.push_back(auser);
	}
	//below this processes the edges(friend connections) of the userList and creates links/friends based on these edges
	int source, friends;
	string definition;
	for (int i=0; i<edges.size();i++)
	{
		stringstream xx(edges[i]);
		xx >> definition;
		xx >> source;
		xx >> definition;
		xx >> friends;
		if (userList.at(source)){
		userList.at(source)->makeFriend(friends);
		}
	}
	g.write_friends(argv[2], userList);//writes friends to a new file
  return 0;
}
	

