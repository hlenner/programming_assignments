#ifndef GML_WRITER_H
#define GML_WRITER_H
#include "user.h"
#include "bcuser.h"

using namespace std;

class gmlwriter{

public:
	gmlwriter();
	~gmlwriter();
	int write_friends(char *fname, Mylist<BCUser*> userList);
private:

};

#endif
