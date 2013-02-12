#include <iostream>
#include "gmlreader.h"
#include <vector>
#include <string>
#include "mylist.h"
#include "user.h"
#include "gmlwriter.h"
#include <sstream>

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
	
	ifstream myfile(argv[2]);
	//int linecount;
	string lines;
	string aor;
	string first1, last1, first2, last2, friend1, friend2;
	for (int i=0; i<3; i++){//CANNOT HARDCODE 3, FIGURE OUT HOW TO FIX THIS
	string value1, value2;
		myfile >> aor;
		
		myfile >> first1 >> last1;
		myfile >>first2>> last2;
		friend1= first1 + " " + last1;
		friend2= first2 + " " + last2;
		
		if (aor == "a"){
			for (int i=0; i<users.size(); i++){
				if (users.at(i)->getName()==friend1){
					stringstream cc;
					cc << i;
					value1=cc.str();
						for (int x=0; x<users.size(); x++){
							if (users.at(x)->getName()==friend2){
								users.at(i)->makeFriend(x);
								users.at(x)->makeFriend(i);	
								stringstream tt;
								tt << x;
								value2=tt.str();
								string str("source "+ value1 + " target " + value2);
								string str2("target "+value2 + " source " + value1);
								//cout << str << endl;
								//cout << str2 << endl;
								edges.push_back(str);
								edges.push_back(str2);
							}
					}
				}
			}
		}
		
		if (aor == "r"){
			for (int i=0; i<users.size(); i++){
				if (users.at(i)->getName()==friend1){
					stringstream cc;
					cc << i;
					value1=cc.str();
						for (int x=0; x<users.size(); x++){
							if (users.at(x)->getName()==friend2){
								users.at(i)->removeFriend(x);
								users.at(x)->removeFriend(i);
								stringstream tt;
								tt << x;
								value2=tt.str();
								string str("source "+ value1 + " target " + value2);
								string str2("target "+value2 + " source " + value1);
								//cout << str << endl;
								//cout << str2 << endl;
								//edges.erase(str);
								//edges.erase(str2);
							}
					}
				}
			}
		}
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
	for (int i=0; i<edges.size(); i++){
		cout << edges[i] << endl;
	}
	gmlwriter g;
	g.write_friends(argv[3], users, edges, nodes);
  return 0;
}
