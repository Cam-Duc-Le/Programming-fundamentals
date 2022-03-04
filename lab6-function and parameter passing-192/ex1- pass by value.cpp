#include <iostream>
#include <fstream>
using namespace std;
bool completeNum(int N)
{
	unsigned int sum=0;
	for(int i=1;i<=N;i++){
		if(N%i==0) 	sum+=i;
	}
	if(sum == (N*2)){
		return true;
	}
	else{
		return false;
	}
}
int main(int narg, char** argv)
{
//	ifstream ifs;
//	ifs.open(argv[1]);
	int N;
	try
	{
		cout<<"input a num N to check: ";
		cin >> N;
		cout << completeNum(N) << endl;//pass by value
		
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

//	ifs.close();
	return 0;
}

