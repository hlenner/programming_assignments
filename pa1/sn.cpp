#include <iostream>
#include "gmlreader.h"
#include <vector>
#include <string>
#include "mylist.h"
#include "user.h"
#include "gmlwriter.h"

using namespace std;

int main(int argc, char *argv[])
{
if(argc < 4){
    cerr << "Please provide the input GML file name, command file name, and output file" << endl;
    return 1;
  }
	vector<string> nodes;
	vector<string> edges;
	string gml, command, output;
	Mylist<User*> users;
	
	GMLReader::read(argv[1], nodes, edges);
	
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
		users.at(friends)->makeFriend(source);
	}
	gmlwriter g;
	g.write_friends(argv[3], users, edges, nodes);
  return 0;
}
