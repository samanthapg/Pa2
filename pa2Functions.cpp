#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;

extern ofstream myfile; 
extern ifstream myfile2; 
 
extern const int ENTRIES;
const float PI=3.1416;

void initialize()
{
	cout << "EC327: Introduction to Software Engineering \n";
	cout << "Fall 2019\n";
	cout << "Programming Assignment 2\n";
	cout << "Value of Entries is: " << ENTRIES <<"\n";

}

bool checkcode(char command)
{
	bool flag; 
	if (command =='F' || command == 'f' ||command =='B' || command == 'b' || command=='R' || command == 'r' ||command=='U' || command == 'u' ) 
	{
		flag = true; 
	}
	else if ( command=='C' || command == 'c' ||command =='E' || command == 'e' || command=='K' || command == 'k' ||command=='S' || command == 's' )
	{
		flag = true; 
	}
	else if (command=='N' || command == 'n' ||command =='X' || command == 'x' || command=='L' || command == 'l' ||command=='Y' || command == 'y' )
	{
		flag = true;
	}
	else if (command=='D' || command == 'd' ||command=='I' || command == 'i' || command=='O' || command == 'o' ||command=='Q' || command == 'q' )
	{
		flag = true;
	}
	else
	{
		flag =  false; 
	}
	return flag;
}

void readDataFromFile(const char * filename)
{
	string output; 
	myfile2.open(filename);
	if(!myfile2)
	{
		cout <<"Unable to open file\n";
	}

}

void writeDatatoFile (const char * filename)
{
	 myfile.open(filename);
	 if (!myfile2)
	 {
	 cout <<"Unable to open file\n";
	 }
}

int factorial(int number)
{
	if (number == 0)
	{
		return 1;
	}
	else
	{ 
		return number * factorial(number-1);
	}

}
int fibonacci(int index)
{
	if (index==0)
	{
		return 0;
	}
	else if (index == 1)
	{
		return 1;
	}
	else 
	{
		return fibonacci(index-1) + fibonacci(index-2);
	}
}
double findSqrtValue(double number)
{
	return sqrt(number);
}
double naturalLog(double value)
{
	return log(value);
}

double areaCircle(double radius)
{
	return (PI*(pow(radius, 2)));
}
double areaSquare(double number)
{
	return (pow(number,2));
}

int findNextOddValue(int number)
{
	if ((number % 2) == 0)
	{
		return number= number+1; 
	}
	else 
	{
		return number+2;
	}
}

int findNextEvenValue(int number)
{
	if ((number % 2) != 0)
	{
		return number= number+1; 
	}
	else 
	{
		return number+2;
	}
}
double findNyanCatValue(double value)
{
	return (pow(4*value,value)+value+10);
}

double doMath(double value, char command)
{
	if (command =='S' || command=='s')
	{
		return sin(value);
	}
	else if (command =='N' || command=='n')
	{
		return cos(value);
	}
	else
	{
		return exp(value);
	}
}

double lucky(double number)
{
	srand(time(NULL)*number);
	double random;
	double low=0.0; 
	random= (( double)rand() * ( number - low ) ) / ( double )RAND_MAX + low;

	return random; 

}
