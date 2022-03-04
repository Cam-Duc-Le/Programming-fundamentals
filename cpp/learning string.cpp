#include <iostream>

#include <string.h>

using namespace std;

 

int main(){
	string str=  string ("Bach Khoa TPHCM"); //  way 2:  string str("Bach Khoa");
	int a=str.length(),b=str.size();  // str.length or str.size used for string parameter
	cout<<a<<"-"<<b<<"\n";
	
  cout << str.substr(5, 4).substr(1, 2) << endl; // substr used for minus a string
  
	char str1[] = "Hello";
  char str2[] = "Bach Khoa";
  strcat(str1, str2);      // str1 become: HelloBach Khoa
cout << str1 << "-" << strlen(str1) << endl;
  
    char str4[10] = "bach khoa"; // if str4[9] will cause compile error
	cout << strlen(str4) << endl; // strlen use for char-array 
  
    char str10a[] = "ly phuc man";
    char str10b[] ="ly thai to";
    cout<<strcmp(str10a,str10b);
return 0;

}
