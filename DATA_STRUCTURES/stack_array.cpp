/*
STACK DATA STRUCTURE 
Linear data stucture which operates in a LIFO(last in first out) or FILO(first in last out).

1. It is a abstract data type (ADT) which has a bounded capacity.
2. It is a simple data structure that allows adding and removing elements in a particular order.
3. The order may be LIFO(last in first out) and FILO (first in last out). 

STANDARD STACK OPERATIONS

1. push() - Place an item onto the stack. If there is no place for new item, stack is in overflow state.

2. pop() - Return the item at the top of the stack and then remove it. If pop is called when stack is empty, it is in an underflow state.

3. isEmpty() - telss if stack is empty or not.

4. isFull() - tell if stack is full or not.

5. peek() - access item at i position.

6. count() - Get the number of items in the stack.

7. change() - change the item at the i position.

8. display() - display all items in the stack.
*/


#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class Stack
{
private:
	int top;
	int arr[5];

public:
	Stack()
	{
		top = -1;
		for(int i=0; i<5;i++)
			arr[i]=0;
	}  
	
	bool isEmpty()
	{
		if(top == -1)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if(top==4)
			return true;
		else
			return false;
	}

	void push( int val)
	{
		if(isFull())
			cout<<"stack overflow "<<endl;
		else
		{
			top++;
			arr[top] = val;
		}

	}

	int pop()
	{
		if(isEmpty())
		{
			cout<<"stack underflow"<<endl;
			return 0;
		}
		else
		{
			int popvalue = arr[top];
			arr[top] = 0;
			top--;
			return popvalue;
		}
	}

	int count()
	{
		return (top + 1);

	}

	int peek(int pos)
	{
		if(isEmpty())
		{
			cout<<"stack underflow"<<endl;
			return 0;
		}	
		else
			return arr[pos];

	}

	void change(int pos , int value)
	{
		arr[pos] = value;
		cout<<"value changed at location "<<pos<<endl;
	}
 
	void display()
	{
		cout<<"All the elements in the stack are"<<endl;
		for(int i=4; i>=0 ; i--)
		{
			cout<<arr[i] <<endl;
		}
	}

};

int main()
{
	Stack s;
	int option, position, value;

	do
	{
		cout<<"What operation do you want to perform? Select Option Number. Enter 0 to exit"<<endl;
		cout<<"1. Push()"<<endl;
		cout<<"2. Pop()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. Peek()"<<endl;
		cout<<"6. Count()"<<endl;
		cout<<"7. Change()"<<endl;
		cout<<"8. Display()"<<endl;
		cout<<"9. Clear Screen"<<endl<<endl;

		cin>>option;

		switch(option)
		{
			case 1:
				cout<<"\n Enter an item to push on to the stack"<<endl;
				cin>>value;
				s.push(value);
				break;
			case 2:
				cout<<"\n Pop Function called, Popped value is"<<s.pop()<<endl;
				break;
			case 3:
				if(s.isEmpty())
					cout<<"\n Stack is empty"<<endl;
				else
					cout<<"\n Stack is not empty"<<endl;
				break;
			case 4:
				if(s.isFull())
					cout<<"\n Stack is full"<<endl;
				else
					cout<<"\n Stack is not full"<<endl;
				break;
			case 5:
				cout<<"\n Enter value to peek on"<<endl;
				cin>>position;
				cout<<"\n Peek function called. Value at position"<<position<<" is "<<s.peek(position)<<endl;
				break;
			case 6:
				cout<<"\n Number of items in the stack is "<<s.count()<<endl;
				break;
			case 7:
				cout<<"\n Enter the position to be changed "<<endl;
				cin>>position;
				cout<<"\n Enter the new value "<<endl;
				cin>>value;
				s.change(position, value);
				break;

			case 8:
				s.display();
				break;

			case 9:
				system("clear");
				break;

			default:
				cout<<"Enter Proper Option Number "<<endl;
				
		}
		
	}while(option !=0);
	
	return 0;
}



  


