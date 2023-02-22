/*  Given a string S, find and return all the possible permutations of the input string.
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

#include<iostream>
#include <string>
using namespace std;


unsigned long factorial(int n) {
  if (n == 0)
    return 1;

  return n * factorial(n - 1);
}


int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if (input[0] == '\0') {
    output[0] = "";
    return 1;
  }

  string *smallans = new string[factorial(input.length() - 1)];
  int smallanslen = returnPermutations(input.substr(1), smallans);

  int possibleplaces = smallans[0].length() + 1;
  for (int i = 0; i < smallanslen; ++i) {
    for (int j = 0; j < possibleplaces; ++j) {
      output[i * possibleplaces + j] =
          smallans[i].substr(0, j) + input[0] + smallans[i].substr(j);
    }
  }
  delete[] smallans;
  return possibleplaces * smallanslen;
}

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


