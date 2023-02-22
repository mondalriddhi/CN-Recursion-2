/*  Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/


#include<iostream>
using namespace std;


void printarray(int const array[], int const size) {
  for (int i = 0; i < size; ++i){
      cout << array[i] << " ";
  }
  cout << '\n';
  return;
}

void copyarray(int copyfrom[], int copyto[], int copyfromsize) {
  for (int i = 0; i < copyfromsize; ++i) copyto[i] = copyfrom[i];
}

void printsubsetsofarray(int input[], int size, int ans[], int anssize) {
  if (size == 0) {
    printarray(ans, anssize);
    return;
  }

  int smallans[anssize + 1] = {};
  copyarray(ans,smallans, anssize);
  smallans[anssize] = input[0];

  printsubsetsofarray(input + 1, size - 1, smallans, anssize + 1);
  printsubsetsofarray(input + 1, size - 1, ans, anssize);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int ans[size] = {};
  printsubsetsofarray(input, size, ans, 0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

