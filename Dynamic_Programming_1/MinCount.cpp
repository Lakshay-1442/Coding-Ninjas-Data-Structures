/*Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

int minCount(int n)
{
    int* arr = new int[n + 1];
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    
    if (sqrt(n) - floor(sqrt(n)) == 0)
    {
        return 1;
    }
    
    for (int i = 4; i <= n; i++)
    {
        if (sqrt(i) - floor(sqrt(i)) == 0)
        {
            arr[i] = 1;
        }
        
        else
        {
            int root = floor(sqrt(n));
            int sqr = root * root;
            
            arr[i] = 1 + arr[i - sqr];
        }
    }
    
    return arr[n];
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}