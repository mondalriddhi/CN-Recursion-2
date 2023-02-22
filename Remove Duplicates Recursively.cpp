/*  Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

*/

#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
    int len=0;
    while(input[len]){
        len++;
    }
    if(len<=1){
        return;
    }
    removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1]){
        for(int i=1;i<=len;i++){
            input[i-1]=input[i];
        }
    }


}


int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
