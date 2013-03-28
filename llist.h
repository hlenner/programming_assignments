#ifndef LLIST_H
#define LLIST_H
#include <iostream>
#include <stdexcept>

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  bool empty() const;
  int size() const;
  void push_back(T new_val);
  void pop_front();
  T& peek_front() const;
  T& peek_back() const;
  T& at(int loc) const;
  bool remove(const T& val);
  void clear();
  void pop_back();
  //void insert(int loc, T val);

 private:
  Item<T> *getNodeAt(int loc) const;

 private:
  Item<T> *head_;
};

template <typename T>
LList<T>::LList()
{
	head_ = NULL;
}

// Write the destructor here
template <typename T>
LList<T>::~LList()
{
  clear();
}

template <typename T>
bool LList<T>::empty() const
{
if (head_==NULL){
	return true;
	}	
else{
	return false;
 	}
}

template <typename T>
int LList<T>::size() const
{
int i=0;
Item<T> *temp = head_;
while(temp != NULL){
	i++;
	temp = temp->next;
	}
	
return i;
}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{
	if(loc<0){
		throw std::invalid_argument("bad location");
	}
	Item<T> *temp = head_;
	
	while(temp != NULL && loc>0){
		temp = temp->next;
		loc--;
	}	
	if(temp == NULL){ 
		throw std::invalid_argument("bad location");
	}
	
	return temp;

}

template <typename T>
void LList<T>::push_back(T new_val)
{
Item<T> *newptr = new Item<T>;
newptr->val =new_val;
newptr->next=NULL;


if (head_ == NULL){//if the list is empty, make head = newptr
	head_ = newptr;
	}
else{
	Item<T> *temp = head_;
	while (temp->next !=NULL){//while (temp->next)
		temp = temp->next;
		}
	
	temp->next = newptr;
	}
} 

template <typename T>
void LList<T>::pop_front()
{
if (head_!=NULL){
	head_=head_->next;
	}
}

template <typename T>
T& LList<T>::peek_front() const
{
if (head_!=NULL){
return head_->val;
}
else{
throw std:: invalid_argument("bad location");
}
}
template <typename T>
void LList<T>::pop_back()
{
	Item<T> *temp=head_;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	remove(temp->val);
 }
 template <typename T>
T& LList<T>::peek_back() const
 {
 	Item<T> *temp = head_;
 	while(temp->next != NULL){
 		temp=temp->next;
 	}
 	return (temp->val);
 }
template <typename T>
bool LList<T>::remove(const T& val)
{
Item<T> *temp=head_;
Item<T> *prev;

while(temp!=NULL)
{
if (temp->val==val)
{
	if (temp==head_){
		head_=temp->next;
		return true;
		}
	else{
		prev->next=temp->next;
		return true;
		}
	}
else{
	prev=temp;
	temp=temp->next;
	}
  }
  return false;
}

template <typename T>
T& LList<T>::at(int loc) const
{
Item<T> *node = getNodeAt(loc);
return node->val;

}
template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
}
/*template <typename T>
void LList<T>:: insert(int loc, T val)
{
Item<T> *newNode = new Item<T>;
Item<T> *nodePtr = NULL;
newNode=head_;
Item<T> *prevNode=nodePtr;
newNode->val = val;
if (loc==size() || size()==0)
{
	push_back(val);
	return;
}
else if (loc==0){
	newNode->next=head_;
	head_=newNode;
	return;
}
 while (loc>0){
	
	prevNode=nodePtr;
	nodePtr=nodePtr->next;
	loc--;
      }
	
	prevNode->next=newNode;
	newNode->next=nodePtr;
  }
  */

#endif
