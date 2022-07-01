/*

Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
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


int length(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    
    int smallAns = length(head -> next);
    
    return smallAns + 1;
}


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{    
    Node *final_head;
    Node *final_tail;
        
    
    if (head1 -> data <= head2 -> data)
    {
        final_head = head1;
        final_tail = head1;
        head1 = head1 -> next;
    }
    
    else
    {
        final_head = head2;
        final_tail = head2;
        head2 = head2 -> next;
    }
    
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 -> data <= head2 -> data)
        {
            final_tail -> next = head1;
            final_tail = head1;
            head1 = head1 -> next;
        }
        
        else
        {
            final_tail -> next = head2;
            final_tail = head2;
            head2 = head2 -> next;
        }
    }
    
    if (head1 == NULL)
    {
        final_tail -> next = head2;
    }
    
    else if (head2 == NULL)
    {
        final_tail -> next = head1;
    }
    
    return final_head;
}


Node *split(Node *head, int len)
{
    if (len == 1)
    {
        return head;
    }
    
    Node *tail = head;
    
    int count = 0;
    
    while (tail -> next != NULL && count < (len / 2) - 1)
    {
        count++;
        tail = tail -> next;
    }
    
    Node *temp = tail -> next;
    tail -> next = NULL;
    
    Node *smallAns1 = split(head, len / 2);
    Node *smallAns2 = split(temp, len - (len / 2));
    
	mergeTwoSortedLinkedLists(smallAns1, smallAns2);
}


Node *mergeSort(Node *head)
{
    int len = length(head);
    
    if (len == 0 || len == 1)
    {
        return head;
    }
    
    split(head, len);
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
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}