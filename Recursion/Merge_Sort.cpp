/*

Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

*/



void merge(int input[], int size)
{
    int count = 0, i = 0;
    //j = (size/2);
    int j;
    int ans[size];
    
    if (size % 2 == 0)
    {
        j = size / 2;
        
        //int ans[size];
    
        while (i < size/2 && j < size)
        {
            if (input[i] <= input[j])
            {
                ans[count] = input[i];
                i++;
            }

            else
            {
                ans[count] = input[j];
                j++;
            }

            count++;
        }

        if (i >= size/2)
        {
            for (int m = j; m < size; m++)
            {
                ans[count] = input[m];
                count++;
            }
        }

        else if (j >= size)
        {
            for (int m = i; m < size/2; m++)
            {
                ans[count] = input[m];
                count++;
            }        
        }
    }
    
    else
    {
        j = (size / 2) + 1;
        
        //int ans[size];
    
        while (i <= size/2 && j < size)
        {
            if (input[i] <= input[j])
            {
                ans[count] = input[i];
                i++;
            }

            else
            {
                ans[count] = input[j];
                j++;
            }

            count++;
        }

        if (i > size/2)
        {
            for (int m = j; m < size; m++)
            {
                ans[count] = input[m];
                count++;
            }
        }

        else if (j >= size)
        {
            for (int m = i; m <= size/2; m++)
            {
                ans[count] = input[m];
                count++;
            }        
        }
    }
    
    
    
    for (int k=0; k<size; k++)
    {
        input[k] = ans[k];
    }
    
    return;
}


void split(int input[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    
    int mid = (s + e) / 2;
    
    split(input, s, mid);
    split(input, mid + 1, e);
    
    merge(input + s, e - s + 1);
    
    return;
}

void mergeSort(int input[], int size)
{	
    split(input, 0, size - 1);
    //return;
}


#include <iostream>
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}