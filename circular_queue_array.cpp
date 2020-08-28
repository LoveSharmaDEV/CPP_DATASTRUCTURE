/*
CIRCULAR QUEUE IMPLEMENTATION

1. Queue is a linear data structure which operates FIFO (First In First Out) ot LILO (Last In Last Out)
2. Queue is an abstract data type (ADT) with a bounded capacity.
3. It is a simmple data structure that allows adding and removing elements in a particular order.
4. The order is FIFO (First In First Out) or LILO (Last In Last Out)
5. Elements added at one end (rear end). This is called Enqueue.
6. Elements are removed from the other end (front/head). This is called Dequeue.

Standard Queue Operations

1. enqueue() - Elements are added from one end. (Rear/Back).
2. dequeue() - Elements are removed from one end. (Head/Front)
3. isFull() - Check if queue is full.
4. isEmpty() - Check if queue is empty.
5. count() - get the count of total items in queue.
 
*/

#include<iostream>
using namespace std;

class CircularQueue
{
	private:
		int front;
		int rear;
		int arr[5];
		int itemCount;

	public:
		CircularQueue()
		{
		        itemCount = 0; 
			front = -1;
			rear = -1;
			for(int i=0; i<5; i++)
			{
				arr[i] =0;
			}
		}

		bool isEmpty()
		{
			if(front == -1 && rear == -1)
				return true;
			else
				return false;
		}

		bool isFull()
		{
			if((rear+1)% 5 == front)
				return true;
			else
				return false;
		}
		
		void enqueue(int val)
		{
			if(isFull())
			{
				cout<<"Queue is full"<<endl;
			}
			else if(isEmpty())
			{
				rear=0;
				front=0;
				arr[rear] = val;
				itemCount++;
			}
			else
			{
				rear=(rear+1)%5;
				arr[rear] = val;
				itemCount++;
			}
		}

		int dequeue()
		{
			int x;
			if(isEmpty())
			{
				cout<<"Queue is empty"<<endl;
				return 0 ; 
			}
			else if(front==rear)
			{
				x = arr[front];
				arr[front] =0;
				front= -1;
				rear= -1;
				itemCount--;
				return x;
			}
			else 
			{
				x = arr[front];
				arr[front]=0;
				front=(front+1)%5;
				itemCount--;
				return x;
			}
		}

		int count()
		{
			return itemCount;
		}

		void display()
		{
		        cout<<"Display the queue "<<endl;
			for(int i=0 ; i<5; i++)
			cout<<arr[i]<<" ";
		}
};

int main()
{
	CircularQueue q;
	int option,value;
	do
	{
		cout<<"\nWhat operation do you want to perform? Select option number. Enter 0 to exit"<<endl;
		cout<<"1. Enqueue()"<< endl;
		cout<<"2. Dequeue"<< endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. clear screen"<<endl;
		cin>> option;
	
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enter item to insert"<<endl;
				cin>> value;
				q.enqueue(value);
				break;
			case 2:
				cout<<"Value deleted is "<< q.dequeue()<<endl;
				break;
			case 3:
				if(q.isEmpty())
					cout<<"Queue is empty"<<endl;
				else
					cout<<"Queue is not empty "<<endl;
				break;
			case 4:
				if(q.isFull())
					cout<<"Queue is full "<<endl;
				else
					cout<<"Queue is not full "<<endl;
				break;
			
			case 5:
				cout<<"No of items in Queue are "<< q.count() <<endl;
				break;
			
			case 6:
				q.display();
				break;
			
			case 7:
				system("clear");
				break;
			default: 
				cout<<"Enter operation number correctly "<<endl;
		}
	}while(option !=0);

	return 0;
}



