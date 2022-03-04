#include <iostream>
#include <fstream>
using namespace std;
int factorial(int n){
	int result;
	if(n==1){
		return 1;
	}
	else{
		return n*factorial(n-1);
	} 
}
int main(int narg, char** argv)
{
//	ifstream ifs;
//	ifs.open(argv[1]);
	int N;
	try
	{
		cin >> N;
		long result;
		// call function calculateFactorial in here and assign value to the variable result
		result=factorial(N);
		
		cout << result << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

//	ifs.close();
	return 0;
}
