/*  Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

#include<iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string smalloutput;
    if(num==0||num==1){
        output[0]="";
        return 1;        
    }
    int lastdig=num%10;
    num=num/10;
    int smalloutputsize = keypad(num,output);
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
    int retsize=smalloutputsize*smalloutput.size();
    string small[retsize];
    int m=0;
    for(int i=0;i<smalloutputsize;i++){
        for(int j=0; j<smalloutput.size(); j++){
            small[m] = output[i]+smalloutput[j];
            m++;
        }
    }
    for(int i=0; i<retsize; i++){
        output[i] = small[i];
    }
    return smalloutput.size()*smalloutputsize;
   
    
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

