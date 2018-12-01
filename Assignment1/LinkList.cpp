#include <iostream>
#include <iomanip>
#include "Complex.h"
#include "Linklist.h"

using namespace std;

linklist::linklist ()		//constructor
{
	head=NULL;
}

linklist::~linklist ()	//destructor
{;}
	
////////////////////////////////////////////////////////////////////////////////
//Size of list	
void linklist::sizelist ()
{
	cout << "Size of List: " << size(head) << endl;
}

////////////////////////////////////////////////////////////////////////////////
//Insert at end
void linklist::insert_end(complex num)
{
	complex* newnode=new complex(num.real,num.imaginary);	
		
	/*new calls overload constructor 

	newnode->re=num.re;
	newnode->imaginary=num.imaginary;
	newnode->next=NULL; 

	all this is done by constructor
	*/

	complex* temp= head;

	if (temp==NULL)	//or use (!temp), list is empty
	{
		head=newnode;
	}

	else	//list has blocks of data
	{
		while (temp->next)	//move temp to last block
		{
			temp=temp->next;
		}
		//now temp pointing to last block
		temp->next=newnode;
		/*now last block is pointing to new last 
		/hence insertion at end*/
	}
}

//Insert after position
//if pos is 1 insert at 2nd pos
void linklist::insert_afterpos (complex num, int pos)
{
	pos= pos_handler(head,pos);		//pos return by function will be new and correct position 

	complex* newnode=new complex(num.real,num.imaginary);	//overload construction called
		
	complex* temp=head;

	for (int i=1; i<pos; i++)	
		temp=temp->next;	

	//temp is pointing  to block at pos+1

	//setting for proper node insertion
	newnode->next=temp->next;
	temp->next=newnode;
}

////////////////////////////////////////////////////////////////////////////////
//delete at pos

void linklist::delete_pos (int pos)
{
	pos= pos_handler(head,pos);

	complex* previous=head;
	complex* current=head->next;

	if (pos==1)	//delete at start
	{
		head=current;
		delete previous;
	}
	else 
	{
		for (int i=1; i<pos-1; i++)
			previous=previous->next;	//move previous to pos-1  

		current=previous->next;	//current point to pos
		previous->next=current->next;	//create pointer link between pos-1 and pos+1	

		delete current;	//free memory 
	}
	
}

//delete at end!
void linklist::delete_end ()
{
	complex* previous=head;
	complex* current=head->next;

	while (current->next)
	{
		current=current->next;
		previous=previous->next;
	}

	delete current;
	previous->next=NULL;
}

////////////////////////////////////////////////////////////////////////////////
//value at pos

void linklist::value_pos (int pos)
{
	pos= pos_handler(head,pos);
	
	complex* temp=head;

	for (int i=1; i<pos; i++)	//move to req pos 
		temp=temp->next;

	//displaying in form of a+bi or a-bi
	if (temp->imaginary>0)	cout << temp->real << "+" << temp->imaginary << "i\t";
	else					cout << temp->real << temp->imaginary << "i\t";
	cout << endl;
	
}

////////////////////////////////////////////////////////////////////////////////
//Printing List
void linklist::print ()
{
	complex* temp= head;
	cout <<"Size of list: "<< size(head)<< setw(15) << " " ;

	while (temp)	//traversing and displaying if temp!=NULL 
	{
		if (temp->imaginary>0)	cout << temp->real << "+" << temp->imaginary << "i" << setw (4) << " ";
		else					cout << temp->real << temp->imaginary << "i" << setw (4)<< " ";
		temp=temp->next;
	}
	cout << endl;
}

////////////////////////////////////////////////////////////////////////////////
//Emptying list

void linklist::emptylist()
{
	while (head!=NULL)	//deleting at start till head is NULL
	{
		complex* temp=head;
		//delete at start
		head=head->next;
		delete temp;
	}
	}

////////////////////////////////////////////////////////////////////////////////
//Friend functions

/*a friend function that takes head as pass by value 
complex* temp=head happening during calling
it returns size of list 
advantage can be called from member functions of linklist*/
int size(complex* temp)
{
	if (temp==NULL)
	{
		cout << "Empty list\n";
		return 0;
	}

	else 
	{
		int size=1;
		while (temp->next)	//traverse till end and increment size by one
		{
			size++;
			temp=temp->next;
		}
		return size;
	}
}

//a friend function for exception handling of position entered
int pos_handler (complex* temp_head, int pos)
{
	cin.clear();
	cin.ignore(100, '\n');

	int a=0;
	int size_list=size(temp_head) ;
	
	while (pos>size_list || pos<=0)	
	{
		try 
		{
			if (a==0 && (pos>size_list || pos<=0))
				throw "Invalid first entry";

			cout << "Enter position: ";
			cin >> pos;
			cin.clear();
			cin.ignore(100, '\n');

			if (pos>size_list || pos<=0)
				throw 0;	
		}

		catch (int temp)
		{
			cout << "Invalid entry\n\n";
		}

		catch (char msg[])
		{
			cout << msg << ". Entry must not be a character and be within 1 to " << size_list << endl <<endl;
			a++;
		}
	}
	return pos;
}
