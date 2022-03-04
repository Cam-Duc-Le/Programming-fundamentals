#include <iostream>
#include <fstream>
using namespace std;
void averageValue(int n, double *a) {
	double aver=0;
	for(int i=0;i<n;i++){
		aver+=a[i];
	}
	cout<<aver/n;
	cout<<"\n";
}
int main(int narg, char** argv)
{
	int size;
	cin >> size;
	cin.ignore(1, '\n');
    int i = 0;
	double *a = new double[size];
	try {
		for(int i=0;i<size;i++){
			cin>>a[i];
		}
		averageValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}


	return 0;
}
