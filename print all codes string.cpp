/*  Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
 Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
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

void printAllPossibleCodes(string input, string output) {
  int inputlen = input.length();

  if (input[0] == '\0') {
    cout << output << '\n';
    return;
  }
  else if(inputlen < 1) return;

  int includedval = 0, excludedval = int(input[0]) - 48;

  if (inputlen >= 2)
    includedval = excludedval * 10 + (int(input[1]) - 48);

  if (includedval >= 1 && includedval <= 26) {
    string includedoutput = output + char(96 + includedval);
    printAllPossibleCodes(input.substr(2), includedoutput);
  }

  string excludedoutput = output + char(96 + excludedval);
  printAllPossibleCodes(input.substr(1), excludedoutput);
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
     printAllPossibleCodes(input, "");
  return;
    
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

