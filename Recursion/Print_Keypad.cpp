/*

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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



#include <iostream>
#include <string>
using namespace std;

void keypad(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
    }
    
    string str;
    
    if (num % 10 == 2)
    {
        str = "abc";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);        
    }
    
    else if (num % 10 == 3)
    {
        str = "def";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
    }
    
    else if (num % 10 == 4)
    {
        str = "ghi";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
    }
    
    else if (num % 10 == 5)
    {
        str = "jkl";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
    }
    
    else if (num % 10 == 6)
    {
        str = "mno";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
    }
    
    else if (num % 10 == 7)
    {
        str = "pqrs";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
        keypad(num / 10, str[3] + output);
    }
    
    else if (num % 10 == 8)
    {
        str = "tuv";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
    }
    
    else if (num % 10 == 9)
    {
        str = "wxyz";
        keypad(num / 10, str[0] + output);
        keypad(num / 10, str[1] + output);
        keypad(num / 10, str[2] + output);
        keypad(num / 10, str[3] + output);
    }
}

void printKeypad(int num)
{
    string output = "";
    keypad(num, output);
}


#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}