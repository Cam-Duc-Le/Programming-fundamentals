#include <iostream>
#include <math.h>
using namespace std;
bool isPrimeNum(int n);

int main(){
	int N,M;
	cout<<"input N-starting point: ";
	cin>>N;
	cout<<"input M-ending point: ";
	cin>>M;
	for (int i=N;i<M;i++){
		if(isPrimeNum(i)==1){
			cout<<i<<" ";
		}
	}
	
return 0;	
}

bool isPrimeNum(int n){
	if (n==1){
		return false;
	}
	else {
		for (int i=2;i<=sqrt(n);i++){
			if ((n % i)==0){
				return false;
			}
		}
	}
return true;
}
