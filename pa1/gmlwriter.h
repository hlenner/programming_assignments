#ifndef GML_WRITER_H
#define GML_WRITER_H
#include "user.h"

using namespace std;

class gmlwriter{

public:
	gmlwriter();
	~gmlwriter();
	int write_friends(char *fname, Mylist<User*> users, vector<string> edges, vector<string> nodes);
private:

};

#endif
