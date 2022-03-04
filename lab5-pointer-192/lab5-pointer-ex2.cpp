#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define MAX_LEN 200

void removeLastSubString( char *str, char *sub)
{
//TODO
char *s;
s=str;// s="truong dai hoc bach khoa thanh pho ho chi minh"

while(strstr(s,sub)!=NULL){
	s=strstr(s,sub);//s="hoc bach khoa thanh pho ho chi minh"
	s+=strlen(sub);
}
// after while loop: s=" chi minh"

if(s!=str) memmove(str+strlen(str)-strlen(sub)-strlen(s) , str+strlen(str)-strlen(s),strlen(str));
}


int main(int narg, char **argv)
{
 // ifstream ifs;
//  ifs.open(argv[1]);

  char str1[MAX_LEN]="truong dai hoc bach khoa thanh pho ho chi minh";
  char str2[MAX_LEN]="ho";
/*
  ifs.get(str1, MAX_LEN, '\n');
  ifs.ignore(MAX_LEN, '\n');
  ifs.get(str2, MAX_LEN, '\n');
  ifs.ignore(MAX_LEN, '\n');
*/
  removeLastSubString(str1, str2);
  cout << str1 << endl;
//  ifs.close();
  return 0;
}
