/*  Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/


#include<iostream>
using namespace std;

void merge2arrays(int input[],int si,int mid,int ei){
    int n1=mid+1-si;
    int n2=ei-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=input[si+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=input[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=si;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            input[k]=a[i];
            k++;
            i++;
        }
        else{
            input[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        input[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        input[k]=b[j];
        k++;
        j++;
    }
}

void merge(int input[],int si,int ei){
    if (si>=ei){
        return;
    }
    int mid=(si+ei)/2;
    merge(input,si,mid);
    merge(input,mid+1,ei);
    merge2arrays(input,si,mid,ei);
}


void mergeSort(int input[], int size){
	// Write your code here
        int si=0,ei=size-1;
    
    merge(input,si,ei);
    
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
