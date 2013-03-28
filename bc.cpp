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
#include "BCAlg.h"

using namespace std;


int main(int argc, char *argv[])
{
BCUser x;
BCAlg *y = new BCAlg();
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
	//this reads in each user and puts their information into the userList
	for (unsigned int i=0; i<nodes.size(); i++){
		stringstream ss(nodes[i]);//creates a stringstream for the node at i
		for (int x=0; x<4; x++){ //this handles each part of a User, and makes it so entering in any order works
			ss >> random;
			if (random == "id"){
				ss >> id;//sets the id
			}
			if (random == "name"){
				ss >> first>> last;
				name = first +" "+ last;//sets name
			}
			if (random == "age"){
				ss >> age;//sets to age
			}
			if (random == "zip"){
				ss >> zip;//sets to zip
			}
		}
		BCUser* auser= new BCUser(id, name, age, zip);//creates a user of 
		userList.push_back(auser);
	}
	//below this processes the edges(friend connections) of the userList and creates links/friends based on these edges
	int source, friends;
	string definition;
	cout << "Edges size: " <<edges.size()<< endl;
	for (unsigned int i=0; i<edges.size();i++)
	{
	//reads in all edges with a stringstream
		stringstream xx(edges[i]);
		xx >> definition;
		xx >> source;
		xx >> definition;
		xx >> friends;
		if (userList.at(source)){
			userList.at(source)->makeFriend(friends);//makes source/friend friends
		}
	}
	//performs the BC algorithm
	Mylist<double>* score= 	y->computeBC(userList);

	//prints the user id and bc score to a new file
	int z = userList.size(); //stores the size of the userlist
	ofstream ofile(argv[2]);//takes input file
	if (ofile.is_open()) { //tests if it is open/good
		for (int i=0; i<z; i++)//goes through the users
		{
			int id= userList.at(i)->getId();//sets id to the user at i
			ofile << "id:  " << id << "   "; //prints the id
			ofile<< "bc: " << userList.at(i)->bc << endl;//prints normalized bc score of the user
		}	
	}
	
	delete score;
	delete y;
  return 0;
}
