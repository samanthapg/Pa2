#include <iostream>
using namespace std;

double series(int);

int n; 

int main()
{
	cout<<"Enter n: ";
	cin >> n;
	while(cin.fail()||n<0)
	{
		cin.clear(); 
		cin.ignore();
		cout<<"Input is not a positive integer. Please try again:";
		cin >>n;
	}
	cout << "Series("<< n <<")is: "<<series(n) <<"\n";
	return 0; 	
}

double series(int n)
{
	if (n==0)
	{
		return 0;
	}
	if (n==1) 
	{
		return (double(2)/double(5));
	}
	else 
	{
		return (double(2*n)/double(3*n +2)) + (series(n-1));
	}
}