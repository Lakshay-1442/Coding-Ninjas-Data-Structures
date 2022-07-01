/*

Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9

*/


/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/


#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) 
{
    if (root == NULL)
    {
        vector<Node<int>*> res;
        res.push_back(NULL);
        return res;
    }
    
    queue<BinaryTreeNode<int>*> q;
    
    vector<Node<int>*> res;
    
    Node<int>* root_head = new Node<int>(root -> data);
    
    res.push_back(root_head);
    
    q.push(root);
    
    int level_capacity = 2;
    int count = 2;
    int temp_count = 0;
    int total_nulls = 0;
    
    Node <int>* head = NULL;
    Node <int>* temp = NULL;
    
    
    while (q.size() != 0)
    {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        
        if (front -> left != NULL)
        {
            if (head == NULL)
            {
                Node <int>* next_Node = new Node<int>(front -> left -> data);
                head = next_Node;
            	temp = head;            
            }
            
            else
            {
                Node <int>* next_Node = new Node<int>(front -> left -> data);
                temp -> next = next_Node;
                temp = next_Node;
            }

        	q.push(front -> left);  
            temp_count++;
        }
        
        else
        {
            total_nulls++;
            count --;
        }
    

        if (front -> right != NULL)
        {
            if (front -> left != NULL)
            {
                Node<int>* next_Node = new Node<int>(front -> right -> data);
                temp -> next = next_Node;
                temp = next_Node;
                q.push(front -> right);
                temp_count++;                
            }
            
            else
            {
                if (head != NULL)
                {
                    Node<int>* next_Node = new Node<int>(front -> right -> data);
                    temp -> next = next_Node;
                    temp = next_Node;
                }
                
                else
                {
            		Node <int>* next_Node = new Node<int>(front -> right -> data);
            	    head = next_Node;
                    temp = head;                          
                }

                q.push(front -> right);  
                temp_count++;
            }
        }
        
        else
        {
            total_nulls++;
            count--;
        }
        
        
        if (temp_count == count)
        {
            res.push_back(head);
            temp_count = 0;
            level_capacity = level_capacity * 2;
            total_nulls = total_nulls * 2;
            count = level_capacity - total_nulls;
            head = NULL;
            temp = head;
        }
    }
    
    return res;
}


BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}