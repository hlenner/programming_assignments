#include "bcuser.h"
#include "mylist.h"
#include "user.h"
#include "bcuser.h"
#include "Stack.h"
#include "Queue.h"
#include "BCAlg.h"
#include <iostream>

using namespace std;

BCAlg::BCAlg()
{
	
}
Mylist<double>* BCAlg:: computeBC(Mylist<BCUser*> &userList)//Bc method
{
	for (int i=0; i<userList.size(); i++){
		userList.at(i)->bc=0;//sets all of the bc scores of the users to 0.
	}	
	
	for(int i=0; i<userList.size(); i++){
		for (int j=0; j<userList.size(); j++){
			userList.at(j)->clearPred();//clears the predecessor array of the user
			userList.at(j)->numsp=0;//sets the num of shortest paths from user i to user j to 0
			userList.at(j)->dist=-1;//sets the distance from user i to user j to 0
			userList.at(j)->delta=0.0;//sets the change value to 0
		}
		userList.at(i)->numsp=1;//sets the # of shortest paths for user i to 1
		userList.at(i)->dist=0;// sets the distance for user 1 to 0
		Stack<BCUser*> st;//creates a stack of BCuser*'s
		Queue<BCUser*> q;//creates a queue of BCuser*'s
		q.push_back(userList.at(i));//adds specified user to the queue
		
		while (!q.empty()){//first in first out, while queue isn't empty
			BCUser* v;//creates a bcuser*
			
			v = q.front();//sets temp v to first value of the queue
			q.pop_front();//remove top of the queue 
			st.push(v);//push the temp bcuser to the stack
			for(int w =0; w< v->getFriendsSize(); w++){
			int u= v->getFriendAt(w);
				if (userList.at(u)->dist == -1){//if user v's friend at w, has a dist of -1
					q.push_back(userList.at(u));//push back user v's friend at w onto the queue
					userList.at(u)->dist=v->dist+1;//set user v's friend at w distance equal to one more than user v's distance
				}
				if (userList.at(u)->dist == v->dist+1){//if user v's friend at w distance is equal to one more than user v's distance
					userList.at(u)->numsp = userList.at(u)->numsp  + v->numsp;//user v's friend at w number of shortest paths is itself plus v's number of shortest paths
					userList.at(u)->preds.push_back(v->getId());//push back v onto predecessor of user v's friend at w
					}
			}
		}
		while (!st.empty()){//last in first out
			BCUser* w = st.top(); //creates a temp bcuser
			st.pop(); //removes w from the stack
			for(int v=0; v < w->preds.size(); v++){//loops through preds of w
			int u= w->preds.at(v);//sets u to the pred of w at v
				//sets the delta of the  userList at u
				userList.at(u)->delta =userList.at(u)->delta + ((userList.at(u)->numsp)/(w->numsp))*(1+(w->delta));
			}
			w->bc = w->bc + w->delta;//makes bc at w equal to itself plus the change (delta)
			}
		   }		  
		
		Mylist<double>*scores= new Mylist<double>();//dynamically allocates scores Mylist<double>
		for (int i=0; i<userList.size(); i++){
			(*scores).push_back(userList.at(i)->bc);//pushes back all of the userList bc values to the scores Mylist
		}
		double min, max;
		min = userList.at(0)->bc;//sets min to first value
		max = userList.at(0)->bc;//sets max to first value
		for(int x=0; x<userList.size(); x++){
			if (userList.at(x)->bc >=max){
				max= userList.at(x)->bc;//goes through userlist, if bc value at x is greater than max, sets max to that userlist bc
			}
			if (userList.at(x)->bc <=min){
				min = userList.at(x)->bc;//goes through userlist, if bc value at x is less than min, sets min to that userlist bc
			}	
		}
		for (int y=0; y<userList.size(); y++){
			(*scores)[(userList.at(y)->getId())]= (((*scores).at(y))-min)/(max-min);//sets scores at userlist of the id 	
		}
		for (int i=0; i<userList.size(); i++){
			userList.at(i)->bc= (*scores).at(i);//sets the bc values of userlist to the normalized bc scores
		}
		
	return scores;	
	return 0;
}
