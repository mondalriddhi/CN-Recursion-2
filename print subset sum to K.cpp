/*  Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/

#include<iostream>
using namespace std;

void print_array(int const *const array, int const size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i];
    if (i + 1 != size) std::cout << " ";
  }
  std::cout << '\n';
  return;
}

void print_subset_sum_to_k(int input[], int size, int k, int ans[],
                           int ans_size) {
  if (k == 0) {
    print_array(ans, ans_size);
    return;
  } else if (size == 0)
    return;

  int *small_ans = new int[ans_size + 1];
  for (int i = 0; i < ans_size; ++i) small_ans[i] = ans[i];

  small_ans[ans_size] = input[0];
  print_subset_sum_to_k(input + 1, size - 1, k - input[0], small_ans,
                        ans_size + 1);
  print_subset_sum_to_k(input + 1, size - 1, k, ans, ans_size);

  delete[] small_ans;
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
     int *ans = new int[size];
  print_subset_sum_to_k(input, size, k, ans, 0);
  delete[] ans;
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
