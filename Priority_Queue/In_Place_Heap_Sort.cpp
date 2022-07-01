/*
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/



void heapSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++)    
    {
        int ci = i;
        int pi = (i - 1) / 2;
        
        while(pi >= 0)
        {
            if (arr[pi] > arr[ci])
            {
                int temp = arr[pi];
                arr[pi] = arr[ci];
                arr[ci] = temp;
            }
            
            else
            {
                break;
            }

            ci = pi;
            pi = (ci - 1) / 2;            
        }
    }
    
    
    int size = n;
    
    while (size > 1)
    {
        int first = arr[0];    
        arr[0] = arr[size - 1];
        arr[size - 1] = first;
        
        size --;
        
        int pi = 0;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int min = pi;

        while(lci < size)
        {            
            if (arr[pi] > arr[lci])
            {
                min = lci;;
            }

            if (rci < size && arr[min] > arr[rci])
            {
                min = rci;
            }

            if (pi == min)
            {
                break;
            }

            int temp = arr[pi];
            arr[pi] = arr[min];
            arr[min] = temp;

            pi = min;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
            min = pi;        
        }
    }    
}


#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}