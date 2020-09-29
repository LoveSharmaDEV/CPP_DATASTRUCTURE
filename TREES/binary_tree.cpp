/*
Binary Tree Implementation
*/

#include<iostream>
using namespace std;

class TreeNode
{
	public:
		int value;
		TreeNode* left; // pointer to left sub-tree
		TreeNode* right; // pointer to right sub-tree


		// Constructor to initialize node
		TreeNode()
		{
			value = 0;
			left = NULL;
			right = NULL;		
		}

		TreeNode(int v)
		{
			value = v;
			left = NULL;
			right = NULL;
		}
};

class BST
{
	public:
		TreeNode* root;

		bool isEmpty() // Check Whether Tree Exists or not
		{
			if(root == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		void insertNode(TreeNode *new_node) // Insert A Node Into A Binary Search Tree
		{
			if(root = NULL)
			{
				root = new_node;
				cout<<"Value Inserted At The Root"<<endl;
			}
			else
			{
				TreeNode* temp = root;
				while(temp != NULL)
				{
					if(new_node->value == temp->value)
					{
						cout<<"No Duplicates Allowed"<<endl;
						break;
					}
					else if((new_node->value < temp->value) && (temp->left == NULL))
					{
						temp ->left = new_node;
						cout<<"Node Inserted In The Tree"<<endl;
						break;
					}
					else if(new_node->value < temp->value)
					{
						temp = temp->left;
					}
					else if((new_node->value > temp->value) && (temp->right == NULL))
					{
						temp->right = new_node;
						cout<<"Node Inserted In The Node"<<endl;
						break;
					}
					else if(new_node->value > temp->value)
					{
						temp = temp->right;
					}
				}
			}
		}


		// Preorder Traversal --> (NLR)
		void printPreorder(TreeNode* r) // DFS
		{
			if(r == NULL)
				return;
			cout<<r->value<<"  ";
			printPreorder(r->left);
			printPreorder(r->right);
		}
		
		// Inorder Traversal --> (LNR)
		void printInorder(TreeNode* r) // DFS
		{
			if(r == NULL)
				return;
			printInorder(r->left);
			cout<<r->value<<" ";
			printInorder(r->right);
		}
  		
		// Postorder Traversal --> (LRN)
		void printPostorder(TreeNode* r) // DFS
		{
			if(r == NULL)
				return;
			printPostorder(r->left);
			printPostorder(r->right);
			cout<<r->value<<" ";

		}

		
		TreeNode* search(int v)  // Iterative Approach
		{
			if(root == NULL)
			{
				return root;
			}
			else
			{
				TreeNode* temp = root;
				
				while(temp != NULL)
				{
					if(v == temp->value)
					{
						return temp;
					}
					else if(v < temp->value)
					{
						temp = temp->left;
					}
					else if(v > temp->value)
					{
						temp = temp->right;
					}
				}
			}
			
			return NULL;
		}
		
		int height(TreeNode* r)
		{
			if(r == NULL) // That means r is a leaf node.
				return -1;
			else
			{
				int lheight = height(r->left);
				int rheight = height(r->right);
				if(lheight > rheight)
				{
					return (lheight+1);
				}
				else
				{
					return (rheight+1); 
				}
			}
		}
		
		
		// Levelorder Traversal	
		
		void printLevelOrder(TreeNode* r) // BFS
		{
			int h = height(r);
			for(int i = 0; i<=h; i++) // Traversing all levels
			{
				printGivenLevel(r,i);
			}		
		}
		
		void printGivenLevel(TreeNode* r, int level)
		{
			if(r == NULL)
			{
				return;
			}
			else if(level == 0)
			{	
				cout<<r->value;
			}
			else
			{
				printGivenLevel(r->left, level-1);
				printGivenLevel(r->left, level-1);	
			}  
		}

};

int main()
{
	BST obj;
	int val;
	int option;

	do
	{
		cout<<"What operation do you want to perform ?"<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print BST values"<<endl;
		cout<<"5. Height Of BST"<<endl;		
		cout<<"6. Clear Screen"<<endl;
		cout<<"7. Exit Program"<<endl;
		cin>>option;
		TreeNode *new_node = new TreeNode();

		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter the value of tree node to insert into BST "<<endl;
				cin>>val;
				new_node->value = val;
				obj.insertNode(new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"SEARCH"<<endl;
				cout<<"Enter value of tree node to serach in BST"<<endl;
				cin>>val;
				new_node = obj.search(val);
				if(!new_node)
				{
					cout<<"The value is present in BST"<<endl;
				}
				else
				{
					cout<<"The value is not present in the BST"<<endl;
				}
				
				break;
			case 3:
				cout<<"DELETE"<<endl;
				break;
			case 4:
				cout<<"PRINT BST"<<endl;
				cout<<"Printing PreOrder Traversal"<<endl;
				obj.printPreorder(obj.root);
				cout<<endl;
				cout<<"Printing InOrder Traversal"<<endl;
				obj.printInorder(obj.root);
				cout<<endl;
				cout<<"Printing PostOrder Traversal"<<endl;
				obj.printPostorder(obj.root);
				cout<<endl;
				cout<<"Printing LevelOrder Traversal"<<endl;
				obj.printLevelOrder(obj.root);
				cout<<endl;
				break;
			case 5:
				cout<<"HEIGHT OF BST"<<endl;
				cout<<"HEIGHT: "<<obj.height(obj.root)<<endl;
				break;
			case 6:
				cout<<"CLEAR"<<endl;
				system("clear");
				break;
			
			case 7:
				cout<<"EXIT"<<endl;
				option = 0;
				break;
			
			default:
				cout<<"Enter Correct Choice !!!"<<endl;
		}

	}while(option != 0);
	

	return 0;
}

