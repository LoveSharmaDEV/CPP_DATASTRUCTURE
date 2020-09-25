/*
INSERTION SORT:
TIME COMPLEXITY: O(n^2)
*/

#include<iostream>
using namespace std;

void insertionSort(int arr[])
{
	int j = 0;
	int key = 0;
	for(int i = 1; i <5 ; i++)
	{
		key = arr[i];
		j = i-1;

		while(j >=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}

		arr[j+1] = key;
	}
}

int main()
{
	int myarr[5];
	cout<<"Enter the numbers "<<endl;
	for(int i =0 ; i<5; i++)
	{
		cin>>myarr[i];
	}

	cout<<"Array before sorting "<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<myarr[i]<<" ";		
	}
	cout<<endl;

	insertionSort(myarr);


	cout<<"Array after sorting"<<endl;
	for(int i = 0; i<5; i++)
	{
		cout<<myarr[i]<< " ";
	}
	cout<<endl;
}
















































