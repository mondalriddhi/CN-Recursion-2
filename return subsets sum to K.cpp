/*  Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


Note : The order of subsets are not important.


Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
*/

#include<iostream>
using namespace std;
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	 if (k == 0) {
    output[0][0] = 0;
    return 1;
  } else if (n == 0)
    return 0;

  unsigned long outputmaxsize = (n * (n + 1)) / 2;
  int smallout1[outputmaxsize][50];
  int smallout2[outputmaxsize][50];
  int includedans =
      subsetSumToK(input + 1, n - 1, smallout1, k - input[0]);
  int excludedans = subsetSumToK(input + 1, n - 1, smallout2, k);

  for (int i = 0; i < includedans; ++i) {
    for (int j = 0; j <= smallout1[i][0]; ++j) {
      if (j == 0)
        output[i][j] = smallout1[i][j];
      else
        output[i][j + 1] = smallout1[i][j];
    }
    ++output[i][0];
    output[i][1] = input[0];
  }

  for (int i = 0; i < excludedans; ++i) {
    for (int j = 0; j <= smallout2[i][0]; ++j)
      output[i + includedans][j] = smallout2[i][j];
  }

  return includedans + excludedans;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


