/*

For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
Example:
alt txt

For the above-depicted tree, when printed in a level order fashion, the output would look like:

10
20 30 
40 50 60
Where each new line denotes the level in the tree.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
Sample Output 1:
10 
20 30 
40 50 60 
Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 

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


#include <queue>

void printLevelWise(BinaryTreeNode<int> *root) 
{
    if (root == NULL)
    {
        return;
    }
    
    queue<BinaryTreeNode<int>*> q;
    
    cout << root -> data << endl;
    
    q.push(root);
    
    int level_capacity = 2;
    int count = 2;
    int temp = 0;
    int total_nulls = 0;
    
    
    while (q.size() != 0)
    {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        
        if (front -> left != NULL)
        {
            cout << front -> left -> data << " ";
        	q.push(front -> left);  
            temp++;
        }
        
        else
        {
            total_nulls++;
            count --;
        }
    

        if (front -> right != NULL)
        {
            cout << front -> right -> data << " ";
        	q.push(front -> right);
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
    printLevelWise(root);
}