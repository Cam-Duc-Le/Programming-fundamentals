#include <iostream>

#include <string.h>

using namespace std;

 

int main(){
/*
 int a = 100, b = 200;

  int *p = &a, *q = &b;

  q = p;

  cout << ++*p << endl;
*/

    char *ptr;

  char Str[] = "abcdefg";

  ptr = Str;

  ptr += 5;

  cout << "*ptr: "<<*ptr << endl<<"ptr: "<<ptr<<'\n';
  /*
  int a[] = {1, 3, 5, 7, 9};

  int *p = a;

  p+=2;

  cout << *p << endl;
  */
  /*
   int a[] = {1, 3, 5, 7};

  int *p = a;

  p++;

  p[1]++;

  cout << p[1] * a[1] << endl;
  */
  int a = 100, b = 200;

int *p = &a, *q = &b;

q = p;

   (*p)++;
   cout<<a<<endl;
   //
    cout << sizeof(char *) << "-"<< sizeof(int *) << "-"<< sizeof(double *) << endl;
      int n = 3;

  int *z = &n;

  cout << sizeof(z) << endl;
return 0;
}
