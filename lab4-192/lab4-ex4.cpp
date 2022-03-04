#include <iostream>
#include <fstream>
using namespace std;
int permutation(int n, int m) {
	if( m==0 || m==n){
		return 1;
	}
	else{
		return permutation( n-1,m)+ permutation(n-1,m-1);
	}
}

int main(int narg, char** argv)
{
	int N=100;
	int M=1;
	try
	{
		cout << permutation(N, M) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	return 0;
}
