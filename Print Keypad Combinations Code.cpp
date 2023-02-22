/*  Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
void keypad(int num,string output){
    string smalloutput;
    if(num==0||num==1){
        cout<<output<<endl;
        return;        
    }
    int lastdig=num%10;
    num=num/10;
    
    if(lastdig==2){
        smalloutput="abc";
    }
    else if(lastdig==3){
        smalloutput="def";
    }
    else if(lastdig==4){
        smalloutput="ghi";
    }
    else if(lastdig==5){
        smalloutput="jkl";
    }
    else if(lastdig==6){
        smalloutput="mno";
    }
    else if(lastdig==7){
        smalloutput="pqrs";
    }
    else if(lastdig==8){
        smalloutput="tuv";
    }
    else if(lastdig==9){
        smalloutput="wxyz";
    }
    int len=smalloutput.length();
    for (int i=0;i<len;i++){
        keypad(num,smalloutput[i]+output);
    }
    
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    keypad(num,output);
}



int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

