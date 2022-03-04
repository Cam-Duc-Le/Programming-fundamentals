#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
 
int main() {
	char str1[100] ="bach khoa khoa 15 TPHCM";
	char str2[100] ="hoa"; 
	
	
	char *substr;
	substr = strstr(str1,str2);
	if(substr==NULL){
		cout<<"Not found";
		cout<<"\n";
	}
	else{
		string sub=substr;  // sub and substr: hoa khoa 15 TPHCM
		cout<<sub.substr(strlen(str2));
		cout<<"\n";
		substr=substr+strlen(str2);
		cout<<substr;
	}

return 0;	
}
