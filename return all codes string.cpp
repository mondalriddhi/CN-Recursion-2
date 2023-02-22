/*  Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
 Write a program to return the list of all possible codes that can be generated from the given string.
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

#include<iostream>
#include <string.h>
using namespace std;


unsigned long power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n < 0)
    return 0;
  return x * power(x, n - 1);
}


int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if (input[0] == '\0') {
    output[0] = "";
    return 1;
  }

  string *combined = new string[power(2, input.length() - 2) + 2];
  string *notcombined = new string[power(2, input.length() - 1) + 2];

  int excludeddecimalval = (int(input[0]) - 48);
  int includeddecimalval = 27;
  if (input.length() >= 2)
    includeddecimalval = excludeddecimalval * 10 + (int(input[1]) - 48);

  int nextcombinedlen = 0;
  if (input.length() >= 2 && includeddecimalval >= 1 &&
      includeddecimalval <= 26)
    nextcombinedlen = getCodes(input.substr(2), combined);

  int nextnotcombinedlen = getCodes(input.substr(1), notcombined);

  for (int i = 0; i < nextcombinedlen; ++i)
    output[i] = char(96 + includeddecimalval) + combined[i];

  for (int i = 0; i < nextnotcombinedlen; ++i)
    output[i + nextcombinedlen] =
        char(96 + excludeddecimalval) + notcombined[i];

  delete[] combined;
  delete[] notcombined;
  output[nextcombinedlen + nextnotcombinedlen] = '\0';
  return nextcombinedlen + nextnotcombinedlen;
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
