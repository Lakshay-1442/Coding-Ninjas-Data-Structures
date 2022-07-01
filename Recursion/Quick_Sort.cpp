/*

Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 

*/



void swap(int &a, int &b) 
{
   int t = a;
   a = b;
   b = t;
}

int Partition(int input[], int lb, int ub)
{
    int pivot = input[lb];
    int start = lb;
    int end = ub;
    
    while (start < end)
    {
        while (input[start] <= pivot)
        {
            start++;
        }
        
        while (input[end] > pivot)
        {
            end--;
        }
        
        if (start < end)
        {
            swap(input[start], input[end]);
        }
    }
    
    swap(input[lb], input[end]);
    
    return end;
}

void Sort(int input[], int lb, int ub)
{
    if (lb >= ub)
    {
        return;
    }
    
    int loc = Partition(input, lb, ub);
    
    Sort(input, lb, loc-1);
    Sort(input, loc+1, ub);
}

void quickSort(int input[], int size) 
{
    Sort(input, 0, size-1);
}


#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}