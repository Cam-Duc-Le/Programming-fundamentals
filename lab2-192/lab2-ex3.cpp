#include <iostream>
using namespace std;
void maxValue(int n, double *a) {
	float max=a[0];
	for(int j=1;j<n;j++){
		if (a[j]>max){
			max=a[j];
		}
	}
	cout<<max;
	cout<<"\n";
}
int main(int narg, char** argv)
{
	int size;
	cin>>size;
	int i = 0;
	double *a = new double[size];
	try {

		for(int i=0;i<size;i++){
			cin>>a[i];
		}
		maxValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}
	
	
return 0;
}
