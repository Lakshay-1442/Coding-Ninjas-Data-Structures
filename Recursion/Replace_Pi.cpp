/*

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50

*/



// Change in the given string itself. So no need to return or print anything

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
        
    for (i = l; i > 1; i--)
    {
        input[i+1] = input[i];
    }
    
    //return input;
}

void replacePi(char input[]) {
	
    if (input[0] == '\0')
    {
        return;
    }
    
    
    if (input[0] == 'p' && input[1] == 'i')
    {
        input[0] = '3';
        input[1] = '.';
        
        Right_Shift(input);
        Right_Shift(input);
        
        input[2] = '1';
        input[3] = '4';
        
        replacePi(input + 4);
    }
    
    else
    {
        replacePi(input + 1);
    }

}


#include <iostream>
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}