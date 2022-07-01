/*

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9

*/


/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/


#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


#include <deque>

void zigZagOrder(BinaryTreeNode<int> *root) 
{
    if (root == NULL)
    {
        return;
    }
    
    deque<BinaryTreeNode<int>*> q;
    
    cout << root -> data << endl;
    
    q.push_front(root);
    
    int level_capacity = 2;
    int count = 2;
    int temp = 0;
    int total_nulls = 0;
    int order = 1;
    
    
    while (q.size() != 0)
    {
        if (order % 2 == 0)
        {
            BinaryTreeNode<int>* back = q.back();
            q.pop_back();

            if (back -> left != NULL)
            {
                cout << back -> left -> data << " ";
                q.push_front(back -> left);  
                temp++;
            }

            else
            {
                total_nulls++;
                count --;
            }


            if (back -> right != NULL)
            {
                cout << back -> right -> data << " ";
                q.push_front(back -> right);
                temp++;
            }

            else
            {
                total_nulls++;
                count--;
            }


            if (temp == count)
            {
                cout << endl;
                temp = 0;
                level_capacity = level_capacity * 2;
                total_nulls = total_nulls * 2;
                count = level_capacity - total_nulls;
                order = 1;
            }
        }
        
        else
        {
            BinaryTreeNode<int>* front = q.front();
            q.pop_front();

            if (front -> right != NULL)
            {
                cout << front -> right -> data << " ";
                q.push_back(front -> right);  
                temp++;
            }

            else
            {
                total_nulls++;
                count --;
            }


            if (front -> left != NULL)
            {
                cout << front -> left -> data << " ";
                q.push_back(front -> left);
                temp++;
            }

            else
            {
                total_nulls++;
                count--;
            }


            if (temp == count)
            {
                cout << endl;
                temp = 0;
                level_capacity = level_capacity * 2;
                total_nulls = total_nulls * 2;
                count = level_capacity - total_nulls;
                order = 2;
            }
        }        
    }
}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}