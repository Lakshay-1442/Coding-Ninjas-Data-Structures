/*

Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1

*/



int subset(int input[], int n, int output[][50]) 
{
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    
    int small_output_size = subset(input + 1, n - 1, output);
    
    for (int i = 0; i < small_output_size; i++)
    {
        output[i + small_output_size][0] = output[i][0] + 1;
        
        output[i + small_output_size][1] = input[0];
            
        for (int j = 2; j <= output[i + small_output_size][0]; j++)
        {
            output[i + small_output_size][j] = output[i][j-1];
        }
    }
    
    return (2 * small_output_size);
}


int subsetSumToK(int input[], int n, int output[][50], int k) 
{
    int size = subset(input, n, output);
    
    for (int i=0; i<size; i++)
    {
        int sum = 0;
        
        for (int j=1; j<=output[i][0]; j++)
        {
            sum = sum + output[i][j];
        }
        
        if (sum != k)
        {
            for (int m=0; m<=output[i+1][0]; m++)
            {
                output[i][m] = output[i+1][m];
            }
            
            size = size-1;
            i--;
        }
    }
    
    return size+2;
}


#include <iostream>
using namespace std;

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}