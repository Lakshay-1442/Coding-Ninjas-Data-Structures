/*

Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/



// Change in the given string itself. So no need to return or print the changed string.

int length(char input[]) 
{
	if (input[0] == '\0') 
    {
		return 0;
	}
	
    int smallStringLength = length(input + 1);
	
    return 1 + smallStringLength;
}

void Right_Shift(char input[])
{
    int l = length(input);
    
    int i;
        
    for (i = l; i > 0; i--)
    {
        input[i+1] = input[i];
    }
    
    //return input;
}

void pairStar(char input[]) {
    
    if (input[0] == '\0')
    {
        return;
    }
    
    if (input[0] == input[1])
    {
        Right_Shift(input);
        
        input[1] = '*';
        
        pairStar(input + 2);
    }
    
    else
    {
        pairStar(input + 1);
    }
}


#include <iostream>
using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}