/*

A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274

*/


long staircase(int n)
{
    unsigned long long int arr[n + 1];
    
    arr[1] = 1, arr[2] = 2, arr[3] = 4;
    
    if (n == 1)
    {
        return 1;
    }
    
    for (int i = 4; i < n + 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    
    return arr[n];
}


#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}