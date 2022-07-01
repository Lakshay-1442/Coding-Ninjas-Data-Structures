/*

For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 

*/


/***********************************************************
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
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) 
{
    if (preLength == 0 || inLength == 0)
    {
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[0]);
    
    int pre_start_left_index = 1;
    int in_start_left_index = 0;
    
    int count1 = 0;
    
    for (int i = 0; i < inLength; i++)
    {        
        if (inorder[i] == root -> data)
        {
            break;
        }
        
        count1++;
    }
    
    int in_end_left_index = count1 - 1;
    
    int pre_end_left_index = (in_end_left_index - in_start_left_index) + pre_start_left_index;
    
    int pre_length_left = (pre_end_left_index - pre_start_left_index) + 1;
    
    int in_length_left = (in_end_left_index - in_start_left_index) + 1;
    
    
    int pre_start_right_index = pre_end_left_index + 1;
    int in_start_right_index = in_end_left_index + 2;
    
    int in_end_right_index = inLength - 1;
    
    int pre_end_right_index = preLength - 1;
    
    int pre_length_right = (pre_end_right_index - pre_start_right_index) + 1;
    
    int in_length_right = (in_end_right_index - in_start_right_index) + 1;
    
    
    BinaryTreeNode<int>* smallAns1 = buildTree(preorder + pre_start_left_index, pre_length_left, inorder + in_start_left_index, in_length_left);
    BinaryTreeNode<int>* smallAns2 = buildTree(preorder + pre_start_right_index, pre_length_right, inorder + in_start_right_index, in_length_right);
    
    root -> left = smallAns1;
    root -> right = smallAns2;
    
    return root;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}