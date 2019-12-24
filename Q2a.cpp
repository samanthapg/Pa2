#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int gcd(int, int);

int main()
{
	int m, n;
//asking for m
	cout << "Enter m: ";
	cin >> m;
	while(cin.fail()||m<0)
	{
		cin.clear(); 
		cin.ignore();
		cout<<"Input is not a positive integer. Please try again:";
		cin >>m;
	}

	if (m<=0)
	{
		cout <<"Input not valid"<<"\n";

	}
	else
	{
		cout << "Enter n: ";
		cin >> n;
		while(cin.fail()|| n<0)
		{
			cin.clear(); 
			cin.ignore();
			cout<<"Input is not a positive integer. Please try again:";
			cin >>n;
		}
		if (n<=0)
		{
			cout<<"Input not valid"<<"\n";
		}
		else 
		{
			cout<< "GCD is: " <<gcd(m,n)<<"\n";
		}
	}
	return 0; 
}

int gcd(int m, int n)
{
	if (m%n==0) 	//base case
	{
		return n; 
	}
	else 
	{
		return gcd(n, m%n);
	}

	//recursive call

}