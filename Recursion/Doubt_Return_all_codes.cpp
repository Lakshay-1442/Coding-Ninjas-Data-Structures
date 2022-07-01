/*

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/


#include <iostream>
//using namespace std;

#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) 
{
    if (input.size() <= 0)
    {
        output[0] = "";
        return 1;
    }
    
    string smallString = input.substr(1);
    string smallStringNew = input.substr(2);
    
    int small_output_size = getCodes(smallString, output);
    int small_output_size = getCodes(smallStringNew, output);
    
    string str = "";
    
    if (input[0] == "1")
    {
        str = "a";
    }
    
    else if (input[0] == "2")
    {
        str = "b";
    }
    
    else if (input[0] == "3")
    {
        str = "c";
    }
    
	else if (input[0] == "4")
    {
        str = "d";
    }
    
	else if (input[0] == "5")
    {
        str = "e";
    }
    
	else if (input[0] == "6")
    {
        str = "f";
    }
    
	else if (input[0] == "7")
    {
        str = "g";
    }
    
	else if (input[0] == "8")
    {
        str = "h";
    }
    
	else if (input[0] == "9")
    {
        str = "i";
    }
    
	else if (input[0] == "1" && input[1] == "0")
    {
        str = "j";
    }
    
	else if (input[0] == "1" && input[1] == "1")
    {
        str = "k";
    }
    
	else if (input[0] == "1" && input[1] == "2")
    {
        str = "l";
    }
    
	else if (input[0] == "1" && input[1] == "3")
    {
        str = "m";
    }
    
	else if (input[0] == "1" && input[1] == "4")
    {
        str = "n";
    }
    
	else if (input[0] == "1" && input[1] == "5")
    {
        str = "o";
    }
    
	else if (input[0] == "1" && input[1] == "6")
    {
        str = "p";
    }
    
	else if (input[0] == "1" && input[1] == "7")
    {
        str = "q";
    }
    
	else if (input[0] == "1" && input[1] == "8")
    {
        str = "r";
    }
    
	else if (input[0] == "1" && input[1] == "9")
    {
        str = "s";
    }
    
	else if (input[0] == "2" && input[1] == "0")
    {
        str = "t";
    }
    
	else if (input[0] == "2" && input[1] == "1")
    {
        str = "u";
    }
    
	else if (input[0] == "2" && input[1] == "2")
    {
        str = "v";
    }
    
	else if (input[0] == "2" && input[1] == "3")
    {
        str = "w";
    }
    
	else if (input[0] == "2" && input[1] == "4")
    {
        str = "x";
    }
    
	else if (input[0] == "2" && input[1] == "5")
    {
        str = "y";
    }
    
	else if (input[0] == "2" && input[1] == "6")
    {
        str = "z";
    }    
    
    for (int i=0; i<small_output_size; i++)
    {
        output[i] = str + output[i];
    }
    
    return small_output_size;	
}



int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}