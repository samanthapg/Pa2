#include <iostream>
#include <stdlib.h>
using namespace std; 

int * ReverseMultiply(int *list, int size);
int * ReverseAdd(int *list, int size);

int main()
{
	int size;

	cout <<"Enter the number of entries: ";
	cin >> size; 
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000,'\n');
		cout <<"Input error. Please enter a positive integer: ";
		cin >> size;
	}
if (size==0)
{
	cout <<"No array to perform calculations\n"; 
	exit(1); 
}
	int list [size];
	int *onel, *twol;

	for (int i=0; i < size; i++)
	{
		cout <<"Entry " << i << " is: ";
		cin >> list[i];
	}

	cout <<"Original array is: ";

	
	for (int i=0; i < size; i++) 
	{
		cout << list[i] <<" ";
	}
	cout <<"and the address of the zero element is: "<<&list<<"\n";
	cout << "One array is: ";
	
	onel=ReverseMultiply(list, size);
	
	
	for (int i=0; i < (2*size+1); i++) 
	{
		cout << (onel[i]) <<" ";
	}
	cout <<"and the address of the zero element is: "<<&onel<<"\n";
	
	cout <<"Two array is: ";

	twol=ReverseAdd(list,size);

	for (int i=0; i < (2*size-1); i++) 
	{
		cout << (twol[i]) <<" ";
	}
	cout <<"and the address of the zero element is: "<<&twol<<"\n";
	return 0; 
}

int * ReverseMultiply (int *list, int size)
{
	int mult=1;
	int j=size-1; 
	int *olist= new int[(size*2)+1];
	for (int i = 0; i < (size*2); i++)
	{
		if (i<size)
		{
			olist[i]=list[i];
		}
		else if (i>=size)
		{
			olist[i]=list[j];
			j--; 
		}
	}		

	for (int i=0; i<(2*size); i++)
	{
		mult=mult*olist[i];
	}
	olist[(2*size)]= mult;
	return olist;
}

int * ReverseAdd (int *list, int size)
{
	int j=size-1;
	int *tlist=new int [(size*2)-1];
	for (int i=0; i < (size*2-1); i++)
	{
		if (i<size)
		{
			tlist[i]=list[i];
		}
		else if (i>=size)
		{
			tlist[i]=(list[j]+list[j-1]);
			j--;
		}
	}
		return tlist;
}