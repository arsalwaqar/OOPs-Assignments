#ifndef Complex_H
#define Complex_H

class complex
{
public:
	double real;	//if data type taken int results of division cannot be properly saved
	double imaginary;
	complex* next;	

	complex();	//constructor
	complex(double real_, double imaginary_);	//overloaded constructor

	~complex();	//destructor

	void setter (); //with exception handling

//Helper functions
	
	complex operator+ (complex num);	//Addition
	complex operator- (complex num);	//Subtraction
	complex operator* (complex num);	//Multiplication
	complex operator/ (complex num);	//Division

//Extra
//Checking Equality

	bool operator== (complex num);
};

#endif