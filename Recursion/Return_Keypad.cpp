/*

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/



#include <string>
using namespace std;

int keypad(int num, string output[])
{
    if (num == 0 || num == 1)
    {
        output[0] = "";
        return 1;
    }
    
    
    int small_output_size = keypad(num / 10, output);
    
    string str;
    
    if (num % 10 == 2)
    {
        str = "abc";
    }
    
    else if (num % 10 == 3)
    {
        str = "def";
    }
    
    else if (num % 10 == 4)
    {
        str = "ghi";
    }
    
    else if (num % 10 == 5)
    {
        str = "jkl";
    }
    
    else if (num % 10 == 6)
    {
        str = "mno";
    }
    
    else if (num % 10 == 7)
    {
        str = "pqrs";
    }
    
    else if (num % 10 == 8)
    {
        str = "tuv";
    }
    
    else if (num % 10 == 9)
    {
        str = "wxyz";
    }
    
    else if (num % 10 == 0 || num % 10 == 1)
    {
        str = "";
    }
    
    
	if (str.size() == 3)
    {
        for (int i = 0; i < small_output_size; i++) 
        {
            int temp = 0;
            
            output[i + (2*small_output_size)] = output[i] + str[temp+2];
            output[i + small_output_size] = output[i] + str[temp+1];
            output[i] = output[i] + str[temp];
		}
        
        return (3 * small_output_size);
    }
    
    
    else if (str.size() == 4)
    {
        for (int i = 0; i < small_output_size; i++) 
        {
            int temp = 0;
            
            output[i + (3*small_output_size)] = output[i] + str[temp + 3];
            output[i + (2*small_output_size)] = output[i] + str[temp + 2];
            output[i + small_output_size] = output[i] + str[temp + 1];
            output[i] = output[i] + str[temp];
		}
        
        return (4 * small_output_size);
    }    
}


#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}