/*

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  

*/


/*#include <climits>

// Brute Force Recursion

int countMinStepsToOne(int n)
{
	if (n == 1)
    {
        return 0;
    }
    
    int res1 = countMinStepsToOne(n - 1);
    
    int res2 = INT_MAX, res3 = INT_MAX;
    
    if (n % 2 == 0) 
    {
        res2 = countMinStepsToOne(n / 2);
    }
    
    if (n % 3 == 0)
    {
        res3 = countMinStepsToOne(n / 3);
    }
    
    return (min(res1, min(res2, res3))) + 1;
}*/



// Memoization

/*#include <climits>

int countMinStepsToOneHelper(int* arr, int n)
{
    if (n == 1)
    {
        return 0;
    }
    
    if (arr[n] != -1)
    {
        return arr[n];
    }
    
    int res1 = countMinStepsToOneHelper(arr, n - 1);
    
    int res2 = INT_MAX, res3 = INT_MAX;
    
    if (n  % 2 == 0)
    {
        res2 = countMinStepsToOneHelper(arr, n / 2);
    }
    
    if (n % 3 == 0)
    {
        res3 = countMinStepsToOneHelper(arr, n / 3);
    }
    
    arr[n] = min(res1, min(res2, res3)) + 1;
    
    return arr[n];
}

int countMinStepsToOne(int n)
{
    int* arr = new int[n + 1];
    
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    
    return countMinStepsToOneHelper(arr, n);
}*/



// Dynamic Programming

#include <cmath>

int countMinStepsToOne(int n)
{
    int* arr = new int[n + 1];
    
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    
    
    
    for (int i = 4; i <= n; i++)
    {
        int res1 = INT_MAX, res2 = INT_MAX, res3 = INT_MAX;
        
        res1 = arr[i - 1];
        
        if (i % 2 == 0)
        {
            res2 = arr[i / 2];
        }
        
        if (i % 3 == 0)
        {
            res3 = arr[i / 3];
        }
        
        arr[i] = min(res1, min(res2, res3)) + 1;
    }
    
    return arr[n];
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}