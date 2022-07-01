/*

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

*/


#include <iostream>
#include <string>
using namespace std;

int temp_count = 0;
int ans = 0;


/*int returnPermutations(string input, string output[])
{
}*/


int helper (string input, string output[], int index)
{   
    if (index >= input.size())
    {
        return temp_count;
    }

    string str = input;

    char temp2;

    temp2 = str[0];
    str[0] = str[index];
    str[index] = temp2;

    output[temp_count] = str;
    temp_count++;

    int start1 = 1;
    int end1 = input.size() - 1;
    int start2 = 1;
    int end2 = input.size() - 1;
    int start3 = 1;
    int end3 = input.size() - 1;

    for (int i=1; i<input.size(); i++)
    {
        if (start1 < end1)
        {
            char temp = str[start1];
            str[start1] = str[end1];
            str[end1] = temp;

            output[temp_count] = str;
            temp_count++;

            start1++;
            //end--;
        }

        if (start2 < end2 && end2 - start2 > 1)
        {
            end2--;
            char temp = str[start2];
            str[start2] = str[end2];
            str[end2] = temp;

            output[temp_count] = str;
            temp_count++;

            //start++;
            //end2--;
        }

        if (start3 < end3 && end3 - start3 > 2)
        {
            start3++;
            end3--;
            char temp = str[start3];
            str[start3] = str[end3];
            str[end3] = temp;

            output[temp_count] = str;
            temp_count++;

            //start3++;
            //end3--;
        }
    }

    //return temp_count;


    int small_output = helper(input, output, index + 1);

    return small_output;


}


int returnPermutations(string input, string output[])
{
    int index = 0;
    //output[0] = input;
    //string str = input;
    //int count = 0;
    int result = helper(input, output, index);
    return result;
}










/*#include <iostream>
#include <string>
using namespace std;*/

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}