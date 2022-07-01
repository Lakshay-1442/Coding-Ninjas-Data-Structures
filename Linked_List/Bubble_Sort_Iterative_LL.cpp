/*

Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90

*/


/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/


//bubble sort iterative
#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


int length(Node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    
    int smallAns = length(head -> next);
    
    return smallAns + 1;
}


Node *bubbleSort(Node *head)
{
    int len = length(head);
    
    Node *new_head = NULL;
    
    for (int i=0; i<len - 1; i++)    
    {
        Node *temp = head -> next;
        Node *temp_prev = head;
        Node *temp_head = NULL;
        Node *new_head = NULL;

        for (int j=0; j<len-1-i; j++)
        {            
            if (temp_prev -> data > temp -> data)
            {
                temp_prev -> next = temp -> next;
                temp -> next = temp_prev;
                
                if (new_head == NULL)
                {
                    new_head = temp;
                    temp_head = new_head;
                    temp = temp_prev -> next;
                    continue;
                }
                
                temp_head -> next = temp;
                temp_head = temp;
                temp = temp_prev -> next;
            }
            
            else
            {
                if (new_head == NULL)
                {
                    new_head = temp_prev;
                    temp_head = temp_prev;
                    temp_prev = temp;
                    temp = temp -> next;
                    continue;
                }
                
                temp_head = temp_prev;
                temp_prev = temp;
                temp = temp -> next;                
            }
        }
        
        head = new_head;
    }
    
    return head;
}


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}