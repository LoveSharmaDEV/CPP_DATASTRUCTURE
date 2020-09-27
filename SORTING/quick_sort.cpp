/*
Quick_Sort_Algorithm
Time Complexity: O(nlog(n))
Space Complexity: O(log(n))
Quick sort is based on divide and conquer strategy.
*/

#include<iostream>
using namespace std;


int partition_array(int arr[], int s, int e)
{
	int pivot = arr[e];
	int pindex = s;
	for(int i =s; i<e; i++)
	{
		if(arr[i] <= pivot)
		{
			int temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
			pindex++;
		}

	}

	int temp = arr[e];
	arr[e] = arr[pindex];
	arr[pindex] = temp;

	return pindex;
}



void quickSort(int arr[] , int s , int e)
{
	if(s<e)
	{
		int p = partition_array(arr,s ,e);
		quickSort(arr,s,(p-1));
		quickSort(arr,(p+1),e);	
	}
}




int main()
{
	int myarr[5];
	cout<<"Enter 5 elements insode the array"<<endl;
	for(int i=0; i<5; i++)
	{
		cin>>myarr[i];
	}


	cout<<"Array before sorting"<<endl;
	for(int i=0 ; i<5; i++)
	{
		cout<<myarr[i]<< " --> ";
	}
	cout<<endl;

	quickSort(myarr,0 ,4); // quick sort called

	cout<<"Array after sorting"<<endl;
	for(int i =0; i<5; i++)
	{
		cout<<myarr[i]<<" --> ";
	}
	cout<<endl;




	return 0;
}

 




















































