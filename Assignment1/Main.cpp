//Assignment 1 Khubaib Waqar Khan MTS 39B

#include <iostream>
#include <iomanip>	
#include "Complex.h"
#include "Linklist.h"

using namespace std;

/*

Operator loading utilized for + - * / == 
In extra a friend size function and position exception handling function used 
Emptying list
a size list as member function that uses friend size function
also in setting of a complex number exception handling used for real and imaginary part

*/

int main ()
{
	complex z1(4,5), z2(3,-3), z3(4,3), z4(0,0), z5(4,5);

	linklist l1;

	cout << "Complex numbers implementation\n"
		 << "---z1=4+5i\t z2= 3-3i\t z3= 4+3i\t z4=0+0i\t z5=4+5i\t z6 from user---\n"
		 << "___________________________________________________\n";

	////////storing z1, z2, z3 in list
	cout << "\n---Inserting at end---\n"
		 << "---Storing z1= 4+5i, z2= 3-3i and z3= 4+3i---\n";
	l1.insert_end(z1);
	l1.print();
	l1.insert_end(z2);
	l1.print();
	l1.insert_end(z3);
	l1.print();

	cout << "___________________________________________________\n";
	////////Adding z1 and z2 and inserting at end 
	cout << "\n---Adding Inserting at end---\n"
		 << "--- z1+z2 ---\n"	;
	l1.insert_end(z1+z2);
	l1.print();
	cout << "___________________________________________________\n";

	////////Subtracting z1 and z3 and inserting at end 
	cout << "\n---Subtracting Inserting at end---\n"
		 << "--- z1-z3 ---\n"	;
	l1.insert_end(z1-z3);
	l1.print();
	cout << "___________________________________________________\n";

	////////Multiply z2 and z3 and inserting at end 
	cout << "\n---Multiply Inserting at end---\n"
		 << "--- z2*z3 ---\n"	;
	l1.insert_end(z2*z3);
	l1.print();
	cout << "___________________________________________________\n";

	////////Divide z1 and z3 and inserting at end 
	cout << "\n---Divide Inserting at end---\n"
		 << "--- z1/z3 ---\n"	;
	l1.insert_end(z1/z3);
	l1.print();
	cout << "___________________________________________________\n";

	////////Divide z1 and z3 and inserting at end 
	cout << "\n---Divide by z4=0+0i (checking exception)---\n"
		 << "--- z1/z4 ---\n"	;
	z4=(z1/z4);
	cout << "___________________________________________________\n";

	////////Checking equality z1 and z3
	cout << "\n---Check Equality---\n"
		 << "--- z1==z3 ---\n"	;

	if (z1==z3)
		cout << "Equal\n";
	else 
		cout << "Not equal\n";

	cout << "--- z1==z5 ---\n"	;

	if (z1==z5)
		cout << "Equal\n";
	else 
		cout << "Not equal\n";
	cout << "___________________________________________________\n";

	int pos=0;

	////////Delete element at given pos
	cout << "\n---Delete at any position (if position greater the size no deletion)---\n"
		 <<"---(you can try entring charters as well)---\n";
	cout << "Enter position: ";
	cin >> pos;
	l1.delete_pos(pos);
	l1.print();
	cout << "___________________________________________________\n";

	////////Delete element at given pos 
	cout << "\n---Delete at end---\n";
	l1.delete_end();
	l1.print();
	cout << "___________________________________________________\n";

	////////Prompt user for complex number
	complex z6;
	z6.setter();

	//displaying complex number entered
	if (z6.imaginary>0)	cout << "z6=" << z6.real << "+" << z6.imaginary << "i\n";
	else				cout << "z6=" << z6.real << z6.imaginary << "i\n";
	cout << "Enter position: ";
	cin >> pos;
	
	l1.insert_afterpos(z6, pos);
	l1.print();
	cout << "___________________________________________________\n";

	////////Value at a given position
	cout << "\n---Value at given position---\n";
	cout << "Enter position: ";
	cin >> pos;
	l1.value_pos(pos);
	l1.print();
	cout << "___________________________________________________\n";

	////////Emptying list
	cout << "\n---Emptying list---\n";
	l1.emptylist();
	l1.print();
	cout << "___________________________________________________\n";
}