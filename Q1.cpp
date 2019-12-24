#include <iostream>
#include "pa2Functions.h"
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

extern const int ENTRIES = 10;
ofstream myfile; 
ifstream myfile2; 

int main() 
{

char command;
string filename; 
bool x, flag, flagread;  
int result;
initialize();

while (command !='q' || command !='Q')
{
//asking for user input
	if (myfile2.is_open() && !myfile2.eof())
	{
		myfile2 >> command; 
	}
	else  
	{
		cout <<"Please enter command code: ";
		cin >> command;
	}

//everytime there is if (flag), we are checking if file is open to write to it	
	if (flag)
	{
		myfile<<command<<"\n"; 
	}
//command options 
	x=checkcode(command);
	if (x == false)
	{
		cout << "Invalid command code. \n";
		if (flag)
		{
			myfile << "Invalid command code. \n";
		}
	} 
	
	else if (command == 'F' || command =='f')
	{ //calculating factorial of input
		int number;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>number; 
		}
		else 
		{
		cout <<"Please enter an integer number: ";
		cin >> number;
		}
		while (cin.fail()) //checking that the user inpputs the type needed
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter a positive integer: ";
			cin >> number;
			if (flag)
			{
				myfile<<"Input error. Please enter a positive integer: ";
			}
		}
		cout <<"Calculating factorial...Result:"<<endl; 
		cout  <<factorial(number)<<"\n";
		if (flag)
		{
			myfile <<number<<"\n";
			myfile << "Calculating factorial...Results: "<<factorial(number)<<"\n"; 
		}

	}
	else if (command == 'B' || command =='b')
	{
		//calculating fibonnacci of given integer inddex. 
		int index;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>index; 
		}
		else 
		{
		cout <<"Please enter an integer index: ";
		cin >> index;
		}
	
		//index starts at 1 so fib 1=1, fib 2=1, fib3=2....
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter a positive integer: ";
			cin >> index;
			if (flag)
			{
				myfile<<"Input error. Please enter a positive integer: ";
			}
		}
		cout <<"Calculating fibonacci...Result:"<<endl; 
		cout << fibonacci(index)<<"\n";
		if (flag)
		{
			myfile << index <<"\n";
			myfile << "Calculating fibonacci...Results: \n"<<fibonacci(index)<<"\n"; 
		}
	}

	else if (command == 'R' || command =='r')
	{//calculating roots assuming input is positive
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else
		{
		cout <<"Please enter a value for first, delta and last: ";
		cin >> first >> delta >> last;
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter a positive doubles: ";
			}
		}	
		cout<<"Computing square roots...Results:\n"; 

		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
			if (flag)
			{
			myfile << first << ", " <<delta <<", "<<last<<"\n";
			myfile << "No computation needed\n"; 
			}
		}
		else
		{
			if (flag)
			{
				myfile << first << ", " <<delta <<", "<<last<<"\n";
				myfile<<"Computing square roots...Results:"<<endl;  
			}
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last) //condition for first+delta^x > last;
				{
					cout << findSqrtValue(last) << "\n";
					if (flag)
					{
						myfile <<findSqrtValue(last) <<"\n";
					}
					break;
				}
				cout << findSqrtValue(value) << "\n";
				if (flag)
					{
						myfile<<findSqrtValue(value) <<"\n";
					}
			}
		} 
	}
	else if (command == 'U' || command =='u')
	{//compute area of square values given a length 
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else
		{
		cout <<"Please enter a value for first, delta and last: ";
		cin >> first >> delta >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive doubles: ";
			}
		}	
		cout << "Computing area of square...Results:\n";
		if (flag)
		{
		myfile << first << ", " <<delta <<", "<<last<<"\n";
		myfile<<"Computing area of square...Results:\n";
		}

		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
			if (flag)
			{
				myfile << "No computation needed\n"; 
			}
		}
		else
		{
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last)
				{
					cout << areaSquare(last) << "\n";
					if (flag)
					{
						myfile <<areaSquare(last) <<"\n";
					}
					break;
				}
				cout << areaSquare(value) << "\n";
				if (flag)
					{
						myfile <<areaSquare(value) <<"\n";
					}
			}
		} 
	}
	else if (command == 'C' || command =='c')
	{
		//compute area of circles given a radius
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else
		{
			cout <<"Please enter a value for first, delta and last: ";
			cin >> first >> delta >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive doubles: ";
			}
		}	
		cout << "Computing area of circle...Results:\n";
		if (flag)
		{
			myfile << first << ", " <<delta <<", "<<last<<"\n";
			myfile<<"Computing area of circle...Results:\n";
		}

		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
			if (flag)
			{
				myfile <<"No computation needed\n";
			}
		}
		else
		{
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last)
				{
					cout << areaCircle(last) << "\n";
					if (flag)
					{
						myfile <<areaCircle(last) <<"\n";
					}
					break;
				}
				cout << areaCircle(value) << "\n";
				if (flag)
					{
						myfile <<areaCircle(value) <<"\n";
					}
			}
		} 
	}
	else if (command == 'E' || command =='e')
	{
		//computing next even value (Not considering first value)
		int first, last, value; 
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>last; 
		}
		else 
		{
			cout <<"Please enter values for first and last: ";
			cin >> first >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive integers: ";
			cin >> first >> last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive integers: ";
			}
		}
		value=first;
		cout<<"Computing even numbers...Results:\n"; 
		if (flag)
		{
			myfile << first << ", " <<last<<"\n";
			myfile<<"Computing even numbers...Results:\n";
		}
		if (first > last)
		{
			cout << "No computation needed \n";
			if (flag)
			{
				myfile<<"No computation needed\n";
			}
		}
		else
		{
			if (first % 2==0)
			{
				cout << first <<"\n";
				if (flag)
				{
					myfile << first<<"\n"; 
				}
			}
			int j=0; 
			while (value <= (last-2) && j<ENTRIES)
			{ 
				value=findNextEvenValue(value);
				cout << value <<"\n";
				if (flag)
					{
						myfile << value <<"\n";
					}
				j++; 
			}
		}
	} 
	else if (command == 'K' || command =='k')
	{
		//computing lucky numbers
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else 
		{
		cout <<"Please enter a value for first, delta and last: ";
				cin >> first >> delta >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive doubles: ";
			}
		}	
		cout << "Computing lucky (random) numbers...Results: \n" ;
		if (flag)
		{
			myfile << first << ", " <<delta <<", "<<last<<"\n";
			myfile<<"Computing lucky (random) numbers...Results:\n";
		}
		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
			if (flag)
			{
			myfile <<"No computation needed \n";
			}
		}
		else
		{
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last)
				{
					cout << lucky(last) << "\n";
					if (flag){
						myfile<<lucky(last) <<"\n"; 
					}
					break;
				}
				cout << lucky(value) << "\n";
				if (flag)
				{
				myfile<<lucky(last)<<"\n";
				}
			}
		} 
	}
	else if (command == 'S' || command =='s' || command =='N' || command=='n' || command=='X' || command=='x')
	{
		//math functions: sin, cos, exp
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else 
		{
		cout <<"Please enter a value for first, delta and last: ";
		cin >> first >> delta >> last; 
		}

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive doubles: ";
			}
		}	
		cout <<"Computing math functions...Results:\n"; 
		if (flag)
		{
			myfile << first << ", " <<delta <<", "<<last<<"\n";
			myfile<<"Computing math functions...Results:\n";
		}
		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
			if (flag)
					{
						myfile <<"No computation needed" <<"\n";
					}
		}
		else
		{
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last)
				{
					cout << doMath(last,command) << "\n";
					if (flag)
					{
						myfile <<doMath(last,command) <<"\n";
					}
					break;
				}
				cout << doMath(value, command) << "\n";
				if (flag)
					{
						myfile <<doMath(value,command) <<"\n";
					}
			}
		} 
	}
	else if (command == 'L' || command =='l')
	{//computing natural logs 
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else 
		{
		cout <<"Please enter a value for first, delta and last: ";
		cin >> first >> delta >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive doubles: ";
			}
		}	
		cout<<"Computing natural logs...Results:\n";
		if (flag)
		{
			myfile << first << ", " <<delta <<", "<<last<<"\n";
			myfile<<"Computing natural logs...Results:\n";
		}
		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
			if (flag)
			{
				myfile<<"No computation needed \n"; 
			}
		}
		else
		{
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last)
				{
					cout << naturalLog(last) << "\n";
					if (flag)
					{
						myfile<<naturalLog(last)<<"\n";
					}
					break;
				}
				cout << naturalLog(value) << "\n";
				if (flag)
				{
					myfile <<naturalLog(value)<<"\n";
				}
			}
		} 
	}
	else if (command == 'Y' || command =='y')
	{
		//nyanCat value
		double first, delta, last, value;
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>delta>>last; 
		}
		else 
		{
		cout <<"Please enter a value for first, delta and last: ";
		cin >> first >> delta >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive doubles: ";
			cin >> first >> delta >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive doubles: ";
			}
		}	
		if (flag)
		{
			myfile << first << ", " <<delta <<", "<<last<<"\n";
			myfile<<"Computing Nyancat values...Results:\n";
		}
		cout << "Computing Nyancat values...Results: \n" ;
		if (delta <= 0 || first > last)
		{
			cout <<"No computation needed \n";
		}
		else
		{
			for (int i=0; i < ENTRIES ; i++)
			{
				value=first + delta * i; 
				if (value >= last)
				{
					cout << findNyanCatValue(last) << "\n";
					if (flag)
					{
						myfile<<findNyanCatValue(last)<<"\n";
					}
					break;
				}
				cout << findNyanCatValue(value) << "\n";
				if (flag)
				{
					myfile<<findNyanCatValue(value)<<"\n";
				}
			}
		} 
	}
	else if (command == 'D' || command =='d')
	{
		//computing odd numbers not taking the first one; 
		int first, last, value; 
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>first>>last; 
		}
		else 
		{
			cout <<"Please enter values for first and last: ";
			cin >> first >> last; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter positive integers: ";
			cin >> first >>last; 
			if (flag)
			{
				myfile<<"Input error. Please enter positive integers: ";
			}
		}	
		value=first;
		if (flag)
		{
			myfile << first <<", "<<last<<"\n";
			myfile<<"Computing odd numbers...Results:\n";
		}
		cout <<"Computing odd numbers...Results: \n";
		if (first > last)
		{
			cout << "No computation needed \n";
			if (flag)
			{
				myfile<<"No computation needed\n"; 
			}
		}
		else
		{
			if (first %2 != 0)
			{
				cout <<first <<"\n";
				if (flag)
				{
					myfile <<first << "\n";
				} 
			}
			int j=0; 
			while (value <= (last-2) && j<ENTRIES)
			{ 
				value=findNextOddValue(value);
				cout << value <<"\n";
				if (flag)
				{
					myfile<<value<<"\n";
				}
			j++; 
			}
		}
	} 
	else if (command == 'I' || command == 'i')
	{//read from input
		string output; 
		string filename; 
		if (myfile2.is_open())
		{
			myfile2.close();
		}
		cout << "Please enter the name of the file: ";
		cin >> filename;

		if (flag)
		{
			myfile<<filename;  
			myfile<<"Reading from file...\n"; 
		}
		cout <<"Reading from file...\n"; 
		readDataFromFile(filename.c_str());
		flagread=true;
	// 	if (myfile2.is_open())
	// 	{
	// 		//cin.rdbuf(myfile2.rdbuf());
	// 		myfile2 >> output;
	// //		cout << output; 
	// 		flagread=true; 
	// 	}

	}
	else if (command =='O' || command =='o')
	{//write to a file
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile2>>filename; 
		}
		else 
		{
			cout << "Please enter the name of the file: ";
			cin >> filename; 
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Input error. Please enter a string filename: ";
			cin >> filename; 
			if (flag)
			{
				myfile<<"Input error. Please enter a string filename: ";
			}
		}
		cout <<"Writing to a file\n"; 
		writeDatatoFile(filename.c_str());
		flag=true; 

	}
	else if (command =='Q' || command =='q')
	{ //continue loop until Q is entered
		if (myfile2.is_open() && !myfile2.eof())
		{
			myfile.close();
		}
		else
		{
			myfile.close(); 
		}
		break;
	}

}
if (myfile2.is_open())
{
	myfile2.close(); 
}
return 0;
}