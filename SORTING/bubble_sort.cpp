/*
Bubble sort
Time Complexity: o(n^2)
*/


#include<iostream>
using namespace std;

// On each iteration the largest element goes to right end.
void bubbleSort(int arr[])
{
	int temp;
	for(int i=0; i<5; i++)
	{
		for(int j=0 ; j< 5-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

}

int main()
{
	int myarr[5];
	cout<<"Enter the number"<<endl;
	for(int i = 0; i<5; i++)
	{
		cin>>myarr[i];
	}

	cout<<"Array before sorting"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<myarr[i]<<" ";

	}
	cout<<endl;
	
	bubbleSort(myarr);

	cout<<"Array after sorting"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
