/*

You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6

*/


#include <unordered_map>
#include <cmath>

int getPairsWithDifferenceK(int *arr, int n, int k) 
{
	unordered_map<int, int> map;
    
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    
    unordered_map<int, int> :: iterator it1 = map.begin();
    unordered_map<int, int> :: iterator it2;
    
    int count = 0;
    int temp = 0;
    
    if (k == 0)
    {
        while (it1 != map.end())
        {
            while (it1 -> second > 0)
            {
                it1 -> second--;
                count = count + it1 -> second;
            }
            
            it1++;
        }
        
        return count;
    }
    
    else
    {
        while (it1 != map.end())
        {
            int diff = (it1 -> first) - k;
            int sum = (it1 -> first) + k;
            
            if (map.count(diff) > 0)
            {
                it2 = map.find(diff);
                count = count + ((it1 -> second) * (it2 -> second));
            }
            
            if (map.count(sum) > 0)
            {
                it2 = map.find(sum);
                count = count + ((it1 -> second) * (it2 -> second));
            }
            
            it1++;
        }        
    }
    
    return count / 2;
}


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}