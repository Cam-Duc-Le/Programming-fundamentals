#include <iostream>
#include <fstream>
using namespace std;
int linearSearch(int *a, int key /* key=M */, int sizeofArray  /* =N */)
{
		if (sizeofArray==0){
			return -1;
		}
		sizeofArray--;
		if ( a[sizeofArray]==key ){
			cout<< " the position of the specified value in the array: ";
			return sizeofArray;
		}
		else{
			linearSearch(a,key,sizeofArray);
		}
}

int* removeElement(int *a, int &n, int position){
		for (int i=position;i<n;i++){
			a[i]=a[i+1];
		}
		n--;
	return a;
}

int main(int narg, char** argv)
{
//	ifstream ifs;
//	ifs.open(argv[1]);

	int N= 5  , M=2   , position=1  ;
	
    int i = 0;
	int *a = new int[N];
	try {
		cout<<" input element for an array:  ";
		for (int j=0;j<N;j++){
			cin>>a[j];
		}
		cout << linearSearch(a, M, N) << endl;
		cout<<"new array after remove target element: ";
		int* newA = removeElement(a, N, position);
		for(int i = 0; i < N; i++) {
			cout << newA[i] << " ";
		}
		cout << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	return 0;
}
