/*

You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16

*/


#include <unordered_map>
#include <vector>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) 
{
    unordered_map<int, int> map;
    
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    
    unordered_map<int, int> :: iterator it1 = map.begin();
    unordered_map<int, int> :: iterator prev = it1;
    unordered_map<int, int> :: iterator next = it1;
    
    int s = 1, e = 1;
    
    int arr1[] = {0, 0};
    int arr2[] = {0, 0};
    
    while (it1 != map.end())
    {
        while (s != 0 || e != 0)
        {
            int diff = (prev -> first) - 1;
            int sum = (next -> first) + 1;

            if (map.count(diff) > 0)
            {
                prev = map.find(diff);
            }

            else
            {
                arr1[0] = prev -> first;      
                s = 0;
            }

            if (map.count(sum) > 0)
            {
                next = map.find(sum);
            }

            else
            {
                arr1[1] = next -> first;
                e = 0;
            }
        }
        
        it1++;
        prev = it1;
        next = it1;
        
        int diff_arr2 = arr2[1] - arr2[0];
        int diff_arr1 = arr1[1] - arr1[0];
        
        if (diff_arr1 > diff_arr2)
        {
            arr2[0] = arr1[0];
            arr2[1] = arr1[1];
        }
        
        else if (diff_arr1 == diff_arr2)
        {
            int index_arr1 = 0, index_arr2 = 0;
            
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == arr1[0])
                {
                    index_arr1 = i;
                }
                
                if (arr[i] == arr2[0])
                {
                    index_arr2 = i;
                }
            }
            
            if (index_arr1 < index_arr2)
            {
                arr2[0] = arr1[0];
                arr2[1] = arr1[1];
            }
        }
        
        s = 1;
        e = 1;
    }
    
    vector<int> res;
    
    res.push_back(arr2[0]);
    res.push_back(arr2[1]);
    
    if (res[0] == res[1])
    {
        res.pop_back();
        res.pop_back();
        res.push_back(arr[0]);
    }
    
    return res;
}


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}