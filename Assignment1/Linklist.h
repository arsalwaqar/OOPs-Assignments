#ifndef Linklist_H
#define Linklist_H

#include "Complex.h"

class linklist
{
private:
	complex* head;	//private variable, head of linked_list
public: 
	linklist ();	//constructor
	~linklist ();	//destructor

	/*passing head by value to friend function this can be called within the class as a handler 
	if position for deletion or insertion is greater than size
	input complex* was chosen so within class member functions it can be used*/
	friend int size(complex*);	

	//for exception handling in position, prompting user to enter position until correct is entered 
	friend int pos_handler (complex*, int);	

	void sizelist ();	/*Size of list	when list is obj
	there is difference between size and sizelist function due to input argument
	object.sizelist can be done in main whereas size(head) can be done in class member functions*/

	void insert_end(complex num);					//Insert at end
	void insert_afterpos (complex num, int pos);	//Insert after position
	void delete_pos	(int pos);		//delete at pos
	void delete_end	();				//delete at end
	void value_pos	(int pos);	//value at pos
	void print ();				//Printing List
	void emptylist();			//Emptying list
};

#endif