#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
bool recFunc(int arr[], int left, int right, int value) { 
  // arr has ascending elements 
  if (left > right) return false; // base case 
  if (value < arr[left] || value > arr[right]) 
   return false; 
  int middle = (left+right)/2; 
  if (arr[middle] == value) return true; 
  if (value < arr[middle]) 
   return recFunc(arr, left, middle - 1, value); 
  else return recFunc(arr, middle + 1, right, value); 
} 

int main(){
	 int arr[5] = {1, 3, 5, 7, 9} ; 
  cout << recFunc(arr, 0, 4, 8) ;
	
return 0;
}
