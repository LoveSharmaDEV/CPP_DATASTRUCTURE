/*
Optimized Bubble sort
Time Complexity: o(n^2)
*/


#include<iostream>
using namespace std;

// On each iteration the largest element goes to right end.
void bubbleSort(int arr[])
{
	int temp;
	bool flag;
	for(int i=0; i<5; i++)
	{
		flag = false;
		for(int j=0 ; j< 5-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				flag = true;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
// flag is true if swapping happened. If swapping didn't happened that means array was already sorted
		if(flag == false) 
		{
			break;
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
