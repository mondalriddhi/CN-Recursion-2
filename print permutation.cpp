/*  Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line

Sample Input 1:
cba
Sample Output 1:
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
void permutation(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<output.length()+1;++i){
        string smalloutput=output.substr(0,i)+input[0]+output.substr(i);
        permutation(input.substr(1),smalloutput);
    }
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output;
    permutation(input,output);
    return;
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
