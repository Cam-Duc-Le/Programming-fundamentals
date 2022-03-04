#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/*void func(int a){

  if (a % 2 == 0){

    a /= 2;

  } else {

    a *= 2;

  }	

}*/
/*
void func(int a[])

{

  a[0]+=5;

}
*/
/* bai 4
int func(int a, int b)

{

  return a * b;

}

double func(double a, double b)

{

  return a + b;

}
*/
/*bai 5 
void fun(int m){
  static int n = 0;
 if ((m++ % 3) == 0)
    n++;

  cout << n << " ";
}
*/

void func6(int *a){
	if (*a % 2 == 0){
		*a /= 2;
	} else {
		*a *= 2;
	}	
}

int func(int a)

{

  static int num = 0;

  num++;

  return a * num;

}
int main(){
	/*bai 1
	 int a = 5;
	cout << func(2);
	*/
	/*	bai 2 
	 int a = 10;
	func(a);
	cout << a;
	*/
	/*bai 3
	  int a[] = {1, 2, 3, 4, 5};
	func(a);
	cout << a[0];// cout 6 NOT 1;
	*/
	/*bai 4
	cout << func(1.5, 4.2);
	*/
	/*bai 5 
	  for (int i = 1; i <= 9; i++) fun(i);
	*/
	//bai 6
	  int a = 10;
	func6(&a);
	cout << a<<"\n";
	
	cout << func(5) << "-" << func(10);
return 0;
}
/* bai1 
int func(int b){

  int a = 10;

  return a + b;

}*/
