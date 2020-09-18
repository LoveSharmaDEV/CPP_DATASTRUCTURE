/*
 Doubly linked list:

Doubly linked list is similar to the singly linked list except the fact that, doubly linked list has an extra pointer to traverse back in the linked list. So a single node in DLL would basically contain 2 pointers.
1. One pointing to next node
2. And other pointing to previous one

Standard operation on linked list:

1. Traversing the linked list.
2. Append the new node.
3. Prepend the new node.
4. Inserting a new node to the specific position.
5. Deleting a node form the list.
6. Updating a node in the list.
*/

	
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		int key;
		Node* next;
		Node* previous;

		Node()
		{
			data = 0;
			key = 0;
			next = NULL;
			previous = NULL;
		}

		Node(int k , int d)
		{
			data = d;
			key = k;
		}


};

class DoublyLinkedList
{
	public:
		Node* head;

		DoublyLinkedList()
		{
			head = NULL;
		}

		DoublyLinkedList(Node* n)
		{
			head = n;
		}

		Node* checkifNodeExists(int k)
		{
			Node* temp = NULL;
			Node* ptr = head;
			while(ptr!=NULL)
			{
				if(ptr->key == k)
				{
					temp=ptr;
					break;
				}
				ptr = ptr->next;
			}

			return temp;
	
		}

		void appendNode(Node* n)
		{
			if(checkifNodeExists(n->key) != NULL)
			{
				cout<<"Node with this already exists, use another key"<<endl;
			}
			else
			{
				if(head ==NULL)
				{
					head = n;
				}
				else
				{
					Node* ptr = head;
					while(ptr->next != NULL)
					{
						ptr=ptr->next;
					}
					ptr->next = n;
					n->previous = ptr;
					cout<<"Node Appended"<<endl;
				}
			}
		}

		void prependNode(Node* n)
		{
			if(checkifNodeExists(n->key) !=NULL)
			{
				cout<<"Node with this key already exists"<<endl;
			}
			else
			{
				if(head == NULL)
				{
					head = n;
					cout<<"Node Prepended At Head Node"<<endl;
				}
				else
				{
					head->previous = NULL;
					n->next=head;
					head =n;
					cout<<"Node Prepended"<<endl;
				}

			}


		}

		void insertNodeAfter(int k, Node* n)
		{
			Node* ptr = checkifNodeExists(k);
			if(ptr == NULL)
			{
				cout<<"No Node Exists With Key Value: "<<k<<endl;
			}

			else
			{
				Node* nextNode = ptr->next;

				if(nextNode == NULL)
				{
					ptr->next = n;
					n->previous=ptr;
					cout<<"Node Inserted In The End"<<endl;
				}
				else
				{
					n->next = nextNode;
					nextNode->previous = n;
					n->previous = ptr;
					ptr->next = n;
					cout<<"Node Inserted In The Between"<<endl;


				}
			}

		}

		void deleteNodeByKey(int k)
		{
			Node* ptr = checkifNodeExists(k);
			if(ptr==NULL)
			{
				cout<<"Sorry The Element Doesn't Exists"<<endl;
			}
			else
			{
				if(head==NULL)
				{
					head = head->next;
					cout<<"Node Deleted"<<endl;
				}
				else
				{
					Node* nextNode = ptr->next;
					Node* prevNode = ptr->previous;

					if(nextNode==NULL)
					{
						prevNode->next = NULL;
						cout<<"Node Deleted At The End "<<endl;
					}
					else
					{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout<<"Node hsa been deleted from the betweeen"<<endl;
					}

				}

			}
		}

		void updateNodeByKey(int k , int d)
		{
			Node* ptr = checkifNodeExists(k);
			if(ptr!=NULL)
			{
				ptr->data = d;
			}
			else
			{
				cout<<"Node Doesn't Exists With This Key Value "<<endl;
			}
		}

		  void printList() 
		  {
			  if (head == NULL) 
			  {
				  cout << "No Nodes in Doubly Linked List";
			  }
			  else 
			  {
				  cout << endl << "Doubly Linked List Values : ";
				  Node* temp = head;
				  
				  while (temp != NULL) 
				  {
					  cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
					  temp = temp -> next;
				  }

			  }
		  }

};


int main() {
 
  DoublyLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
 
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependNode(n1);
      break;
 
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      obj.insertNodeAfter(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);
 
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);
 
      break;
    case 6:
      obj.printList();
 
      break;
    case 7:
      system("clear");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}




