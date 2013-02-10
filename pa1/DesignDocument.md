# Design Document for PA1

## Purpose/Overview
		This piece of software will store ids, names, ages, zip codes,and friends of users within a given gml file and create
		a social network with this information

## Requirements
> What are the functions that this software is supposed to perform?
> Try to phrase them in a clear and concise manner.
		It will take in a gml file with users and connections, and take in a command file dictating any changes to friend connections (add/remove). It will perform these functions and then
		output the updated user list(along with each user's information) and friend connections in gml format.


## Classes 
> What classes do you need to create?

		The classes I created are gmlwriter.cpp, gmlwriter.h, sn.cpp, mylist.h(template), user.cpp, and user.h.

> + Describe the purpose of each class.

		-gmlwriter.h will have the prototypes of the member functions and variables for the gmlwriter.cpp class.
		-gmlwriter.cpp will write the given information, which is the gml input file, to a new file after adding the necessary
		modifications that are in the commands.txt file(add/remove friend connections).

		-user.h will have the prototypes of the member functions and variables for the user.cpp class.
		-user.cpp's main goal is to access and modify all aspects(age, zip, friends, id, name) of the user object that we declare in sn.cpp. 

		-mylist.h is a template class. The purpose is to perform simple tasks on any mylist<T> objects that any normal "list" would need.
		For example, removing an item, adding an item, and accessing the location of an item are all actions performed on a list of anything. 

		-sn.cpp is where the main method is. It ties everything together because it is where the objects are instantiated and declared, and all 
		other functions/classes are called through this. It is also where the read,write, and changing friend list implementations occur.

> + What member data will they have? Why?

-gmlwriter.h/gmlwriter.cpp will have: 
		parameters storing the nodes, edges, and inputted gml file.

-user.h/user.cpp will have
		all of the parameters that make up a user in the get and set methods. (id, zip, name, age) These are all used to get information of the user.

-mylist.h will have
		a template class with all of the functions required of a list, including removing, adding, size, at, and push_back. 

-sn.cpp will have 
		a main file that calls to all of the other files 

> + What methods will they have? Why?
-gmlwriter.h/gmlwriter.cpp will have:
		int write_friends(char *fname, Mylist<User*> users, vector<string> edges, vector<string> nodes);
			This is the method used to write all of the friends to the output file specified by the user.
		
-user.h/user.cpp will have
		void setAge(int age);
			This is to set the age of the specified user object.
		void setName(string name);
			This is to set the name of the specified user object.
		int getAge();
			This is to return the age of the specified user object.
		string getName();
			This is to return the name of the specified user object.
		void makeFriend(int x);
			This is to make the user with the id given in the parameter a friend of the specified user object.
		void removeFriend(int x);
			This is to remove the user with the id given in the parameter as a friend of the specified user object.
		int getZip();
			This is to return the zip code of the specified user object.
		void setZip(int zip);
			This is to set the zip code of the specified user object.
		void getFriends();
			This is to return the friends list of the specified user object.
		void setId(int id);
			This is to set the id of the specified user object.
		int getId();
			This is to return the id of the specified user object.
		string _name;
			This is the private variable storing the name of the user object.
		int _age;
			This is the private variable storing the age of the user object.
		int _zip;
			This is the private variable storing the zip of the user object.
		int _id;
			This is the private variable storing the id of the user object.
		Mylist<int> friends;
			This is the private Mylist int type storing the friends of the user object.
	* note: all of the private variables are private so they will not be altered unintentionally

-mylist.h will have
		void push_back(T x);
			This is going to add a new T type item to the end of the list
		int size() const;
			This is going to return the size of the list
		T at(int loc) const;
			This is going to return the value of a specified location in the list, given through parameters.
		bool remove(T val);
			This is going to return true if the specified T val is found in the list and properly removed, otherwise false. It
			removes by searching for a match to the value and moving each T forward in the list once it is found so it is no longer in the list.
		T *items;
			This is a pointer to the items in the list that is created. Type T because it is a template that will be declared with a type in sn.cpp	
		int _size;
			This is the size of the list that is creating.
		int capacity;
			This is the maximum size that the list can get to before nothing more can be added, unless the capacity is increased.
> Make sure you describe each member variable and member function.


## Global Data/Functions
> What global data & functions do you have? Describe any pieces of your program that are not within a class. You don't need to describe every single variable you use, but are there any global variables or functions that are integral to how your program works?
		The most important global data and functions that are used are in the sn.cpp class. The id, age, zip, and random variables are all important because after using the stringstream, 
		they are an integral part of getting the data. Then, the read functions which was provided was very important because it parsed the information from the gml file into the node and edge string vectors.
		After that, I used the push_back function after creating new users with the stringstream information in order to store the users from the document into the Mylist<*Users> users object. For the stringstream, I 
		made 2 separate stringstreams, one to collect and separate the node vector, and the other to collect and separate the edge vector.
## High-level Architecture
> What is the high level flow of data through your program? How will all of your objects interact? What are the algorithms that your code will use?
		
> You will spend a lot of time describing in detail all the objects and functions that you'll use, but you need to talk a bit about how they all fit together.
		All of the functions fit together because MyList is created to make the friends list of the User and create a pointer User class of Mylist
		gmlreader takes in the file and parses it to the edges and nodes, gmlwriter takes gmlreader information and commands list and outputs a new file with updated information,
		and sn.cpp ties it all together with the main function because it calls the functions and instantiates all of the objects/vectors of the mylist type.

## User Interface
> Describe how the user will interact with your software.
The user will run the program(./sn) and enter the input fml file, space, command file, space, and output file. The code does everything else.
> If you have a GUI, how will it be laid out (provide a sketch if possible)?
> + Where will buttons and other controls be located?
> + Describe how the user will interact with it.
		N/A, there is no GUI

> If you don't have a GUI, what kind of interaction will the user have?
		The user will type in the information into the command line.
> + What data will the user enter?
		The user will enter an input gml file, a list of commands through another file, and the name of an output file.
> + How will they enter it?
		They will type it in the command line and the code will output an updated file and process the commands.


##Test Cases
> + How do you plan on testing your system?
		-We can test the system by altering the specific values in the input files(test.gml and commands.txt) to see if it works when all proper values are used
> + What are the potential problem cases?
		-Potential problem cases are:
			if the user does not have the input file and command file in the proper format
			the user tries to read a gml file or command file that does not exist
			formatting is definitely the most important. If there is one off space, typo, or anything, then the entire program can alter(i.e. a number entered somewhere that a letter should be)
> + What are some nominal test cases?
		We can test if the file is in the appropriate format by making try/catch statements within the functions. This will make sure the data is properly entered.
> + For each function, describe some possible tests (what data would you pass in? What results do you expect?)
		For the set functions, try the function and then catch it if the value in the parameter does not match the type. If anything other than 5 numbers is passed into the zip, it will throw 
		an error. If the read functions passes in argv[1] and argv[1] does not exist, it should print a statement "cannot open file." If it is in the wrong format, it should print "cannot read the file."
		
