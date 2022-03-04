#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void printOrder(char *str1, char *str2, char *str3)
{
	// TODO
	char substr[100];
	if(strcmp(str1,str2)>0){
		strcpy(substr,str1);		// strcpy and strcmp take 
		strcpy(str1,str2);
		strcpy(str2,substr);
	}
	if(strcmp(str2,str3)>=0){
		if(strcmp(str1,str3)>0){
				cout<<str3<<'\n';
				cout<<str1<<'\n';
				cout<<str2;
				cout<<"\n";
				return;
		}
		else{
			cout<<str1<<'\n';
			cout<<str3<<'\n';
			cout<<str2;
			cout<<"\n";
		return;
		}
	}
	else{
		cout<<str1<<'\n';
		cout<<str2<<'\n';
		cout<<str3;
		cout<<"\n";
		return;
	}
}

int main(int narg, char **argv)
{

   char str1[100]="aa bc";
  char str2[100]="aa cc";
  char str3[100]="aa ac";
  
 /* cout<<"input str1: ";
  cin.getline(str1,'\n');
  cout<<"input str2: ";
  cin.getline(str2,'\n');
  cout<<"input str3: ";
  cin.getline(str3,'\n'); // cin.getline to get input from char[] 
  							// getline(cin, parameter) tp get input from string
*/
  printOrder(str1, str2, str3);
  return 0;
}
