#include <iostream>
#include <fstream>
using namespace std;
int sum(int array[], int numEls)
{
	int s=0;
	for(int i=0;i<numEls;i++){
		s+=array[i];
	}
return s;
}

void sum2(int * array, int numEls, int &result){
	result=0;
	for(int i=0;i<numEls;i++){
		result+=array[i];
	}
}

int main(int narg, char** argv)
{
//	ifstream ifs;
//	ifs.open(argv[1]);
	int size;
	int t;
	cout<<"input size: "; cin >> size;
	cout<<"input t: "; cin >> t;
//	ifs.ignore(1, '\n');
    int i = 0;
	int *a = new int[size];
	try {
		for( int i=0;i<size;i++){
			cin>>a[i];
		}
		if (t == 1 || t == 3) {
			cout << sum(a, size) << endl;
		}
		if (t == 2 || t == 3) {
			int result = 0;
			sum2(a, size, result);
			cout << result << endl;
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	//ifs.close();
	return 0;
}
