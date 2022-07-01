/*

Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false

*/



#include <bits/stdc++.h>

bool isPalRec(char input[], int s, int e)
{
	
	// If there is only one character
	if (s == e)
	return true;

	// If first and last
	// characters do not match
	if (input[s] != input[e])
	return false;

	// If there are more than
	// two characters, check if
	// middle substring is also
	// palindrome or not.
	if (s < e + 1)
	return isPalRec(input, s + 1, e - 1);

	return true;
}


bool checkPalindrome(char input[]) {
    
    int n = strlen(input);
	
	// An empty string is
	// considered as palindrome
	if (n == 0)
		return true;
	
	return isPalRec(input, 0, n - 1);
}


#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}