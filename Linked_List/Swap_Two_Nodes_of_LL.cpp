/*

You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 

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


Node *swapNodes(Node *head, int i, int j)
{
    if (i == j)
    {
        return head;
    }
    
    if (i > j)
    {
        int a = i;
        i = j;
        j = a;
    }
        
    
    Node *temp = head;
    Node *temp2 = head;
    
    int count = 0;
    
    while (count < i - 1 && i != 0)
    {
        temp = temp -> next;
        temp2 = temp2 -> next;
        count ++;
    }
    
    if (i == 0)
    {
        temp2 = temp;
        count++;
    }
    
    else
    {
        temp2 = temp -> next;
    	count++;        
    }
    
    Node *temp3 = temp -> next;
    
    while (count < j - 1)
    {
        temp3 = temp3 -> next;
        count ++;
    }
    
    Node *temp4 = temp3 -> next;
    
    if (j == i + 1)
    {
        Node *temp5 = temp4 -> next;
        temp -> next = temp5;
        temp -> next = temp4;
        temp4 -> next = temp2;
        temp2 -> next = temp5;
        
        if (i == 0)
        {
            return temp4;
        }
        
        else
        {
            return head;
        }
    }
    
    
    temp -> next = temp2 -> next;
    temp3 -> next = temp4 -> next;
    
    Node *temp5 = temp -> next;
    temp -> next = temp4;
    temp4 -> next = temp5;
    
    Node *temp6 =temp3 -> next;
    temp3 -> next = temp2;
    temp2 -> next = temp6;
    
    if (i == 0)
    {
        return temp4;
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
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}