/*  Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 

*/



#include<iostream>
using namespace std;


int partition(int input[],int si,int ei){
    int count=0;
   int bin=input[si];
    for(int i=si+1;i<=ei;i++){
        if (input[i]<=bin){
            count++;
        }
    }
    //swap(input[si],input[count+si]);
    int temp1=input[si];
    input[si]=input[count+si];
    input[count+si]=temp1;
    int i=si;
    int j=ei;
    while(i<si+count || j>si+count){
        if(input[i]<=bin){
            i++;
        }
        else if(input[j]>bin){
            j--;
        }
        else{
            //swap(input[i],input[j]);
            int temp;
            temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
    return si+count;
}

void qs(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int piv=partition(input,si,ei);
    qs(input,si,piv-1);
    qs(input,piv+1,ei);
}



void quickSort(int input[], int size) {

    int si=0,ei=size-1;
    qs(input,si,ei);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


