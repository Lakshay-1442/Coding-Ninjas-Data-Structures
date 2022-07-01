/*

Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.


*/


#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() 
    {
        int ans = pq[0];
        
        int a = pq.size() - 1;
        
        pq[0] = pq[a];
        
        pq.pop_back();
        
        int flag = 0;
        int res = 0;
        
        int pi = 0;
        int lci = 1;
        int rci = 2;
        int minIndex = 0;
        
        while (flag == 0)
        {
            if (lci < pq.size() && rci < pq.size())            
            {
                if (pq[lci] <= pq[rci])
                {
                    minIndex = lci;
                    res = pq[lci];
                }
                
                else
                {
                    minIndex = rci;
                    res = pq[rci];
                }
                
                if (pq[pi] <= res)
                {
                    flag = 1;
                }
                
                else
                {
                    int temp = pq[pi];
                    pq[pi] = pq[minIndex];
                    pq[minIndex] = temp;
                }
            }
            
            else if (lci < pq.size() && rci >= pq.size())
            {
                if (pq[pi] <= pq[lci])
                {
                    flag = 1;
                }
                
                else
                {
                    res = pq[lci];
                    minIndex = lci;
                    int temp = pq[pi];
                    pq[pi] = pq[minIndex];
                    pq[minIndex] = temp;
                }
            }
            
            
            else if (lci >= pq.size() && rci >= pq.size())
            {
                flag = 1;
            }
            
            pi = minIndex;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }
        
        return ans;
    }
};


#include <iostream>
#include <climits>
using namespace std;


int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}