#include <iostream>
#include <fstream>
using namespace std;
bool uniqueElement(int size, int *a, int i)
{
	
	for (int k=i+1;k<size;k++){
		if(a[i]==a[k]){
			return false;
		}
	}
	++i;
	if (i >= size){
		return true;
	}
	else{
		uniqueElement(size,a,i);
	}
}
// the case when user enter more than (size) input ??


int main(int narg, char** argv)
{
	
//	ifstream ifs;
//	ifs.open(argv[1]);

	int size=4;
    int i = 0;
	int *a = new int[size];
	cout<<"input element: ";
	try {

		for(int j=0; j<size  ;j++){
			cin>>a[j];
		}
		cout << uniqueElement(size, a, 0) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

//	ifs.close();
	return 0;
}
