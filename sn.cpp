#include <iostream>
#include "gmlreader.h"
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	mylist<User*> users;
	vector<string> nodes;
	vector<string> edges;
	string gml, command, output;
  if(argc < 4){
    cerr << "Please provide the input GML file name, command file name, and output file" << endl;
    return 1;
  }
	
	GMLReader::read(argv[1], nodes, edges);
	
	/*for (unsigned int i=0; i<nodes.size(); i++){
	cout << nodes[i] << endl;
	}
	for (unsigned int i=0; i<edges.size(); i++){
	cout << edges[i] << endl;
	}*/
  return 0;
}
