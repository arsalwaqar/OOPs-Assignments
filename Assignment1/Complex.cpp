#include <iostream>
#include "Complex.h"

using namespace std;

complex::complex()	//constructor
{
	real=0; imaginary=0; next=NULL;
}

complex::complex(double real_, double imaginary_)	//overloaded constructor
{
	real=real_; imaginary=imaginary_; next=NULL;
}

void complex:: setter ()
{	
	bool flag=false;
	do
	{
		try
		{
		flag=false;
		cout << "\n---User promt and insert after a given position---\n(eg: enter 4 for insertion at 5)\n";
		cout << "Enter real part: ";
		cin >> real;
		flag=cin.fail();
		cin.clear();
		cin.ignore(100, '\n');
		if (flag)
			throw 1;

		cout << "Enter imaginary part: ";
		cin >> imaginary;
		flag=cin.fail();
		cin.ignore(100,'\n');
		cin.clear();
		if (flag)
			throw 1;
		}
		catch (...)
		{
			cout << "invalid\n";
		}
	}
	while (flag);

	cin.clear();
}

complex::~complex()
{;}
////////////////////////////////////////////////////////////////////////////////
//Helper functions
	
//Addition
complex complex::operator+ (complex num)
{
	complex sum;
/*
z1=a+bi
z2= c+di
sum	= z1 + z2
= (a+c) + (b+d)i 
*/

/*
real=this->real
imaginary=this->imaginary

i choose this->real and this->imaginary expression because of better 
readibility as this keyword highlighted as blue
*/
	sum.real=num.real+ this->real;					
	sum.imaginary=num.imaginary+ this->imaginary;	

	return sum;
}

///////////////////////////////
//Subtraction
complex complex::operator- (complex num)
{
	complex sub;
/*
z1=a+bi
z2= c+di
sub	= z1 - z2
= (a+c) - (b+d)i 
*/
	sub.real=this->real-num.real;				
	sub.imaginary=this->imaginary-num.imaginary;	

	return sub;
}

///////////////////////////////
//Multiplication
complex complex::operator* (complex num)
{
	complex pro;
/*
z1=a+bi
z2= c+di
pro	= z1 * z2
= (ac - bd) + (ad + cb)i 
*/		
	pro.real=this->real * num.real - this->imaginary * num.imaginary ;
	pro.imaginary=this->real * num.imaginary + this->imaginary * num.real; 

	return pro;
}

///////////////////////////////
//Division
complex complex::operator/ (complex num)
{
	complex quo;
/*
z1=a+bi
z2= c+di
quo	=(a+bi) / (c+di)
=(ac+db)/(c^2+d^2) + (cb-ad)/(c^2+d^2) 
*/
	double denom = (num.real * num.real + num.imaginary * num.imaginary);

	try 
	{
		if (denom==0)
			throw 0;
			
		quo.real= ( this->real * num.real + this->imaginary * num.imaginary) / denom ;
		quo.imaginary=( -this->real * num.imaginary + this->imaginary * num.real ) / denom ; 
		return quo;
			
	}
	catch (int x)
	{
		cerr << "Exception division by zero\n";
		quo.real= 0 ;
		quo.imaginary=0; 
		return quo;
	}
}

///////////////////////////////
//Extra
//Checking Equality

bool complex::operator== (complex num)
{
/*
z1=a+bi
z2=c+di
a==c && b==d then z1=z2
*/		
	if ( num.real==this->real && num.imaginary==this->imaginary)
		return true;
	else 
		return false;
}