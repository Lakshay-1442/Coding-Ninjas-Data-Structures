/*

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

*/


/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/


#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


TreeNode<int>* maximum;
int flag = 0;

TreeNode<int>* getMax(TreeNode<int>* root) 
{
	TreeNode<int> *max = new TreeNode<int>(root->data);
    
    for(int i = 0; i < root -> children.size(); i++)
    {
        TreeNode<int> *child = getMax(root -> children[i]);
        
        if (child -> data > max -> data)
        {
            max = child;
        }
    }
    
    return max;
}


TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) 
{
    if (flag == 0)
    {
        maximum = getMax(root);
        
        flag = 1;
    }
    
	TreeNode<int> *res = new TreeNode<int>(root->data);
    
    for (int i = 0; i < root -> children.size(); i++)
    {
        TreeNode<int>* smallAns = getSecondLargestNode(root -> children[i]);
        
        if (smallAns != NULL)
        {
            if (res -> data != maximum -> data)
            {
                if (smallAns -> data > res -> data && smallAns -> data < maximum -> data)
                {
                    res = smallAns;            
                }            
            }

            else
            {
                res = smallAns;            
            }

        }
    }
    
    if (res -> data == maximum -> data)
    {
        return NULL;
    }
    
    else
    {
        return res;
    }
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}