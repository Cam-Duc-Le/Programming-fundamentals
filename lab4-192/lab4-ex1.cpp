#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
bool palindrome(char strg[], int j)
{
	if( j >= (int)(strlen(strg))/2 ){
		return true;
	}
	else{
		if( strg[j] == strg[strlen(strg)-1-j] ){
			j++;
			palindrome(strg, j);
		}
		else{
			return false;
		}
	}
}
int main(int narg, char** argv)
{
	
	char strg[100]="  ";
	try
	{	
			cout << strg << " " << palindrome(strg, 0) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}
	return 0;
}
