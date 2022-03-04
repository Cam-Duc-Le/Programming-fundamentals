#include <iostream>
#include <math.h>
using namespace std;

int  calcount(int n);
int check(int n,int count);
int main(){
	int N;
	do{
		cout<<"input N:";
		cin>>N;
		if(!cin.good()){ 
			cin.clear();
			cin.ignore(0x0fffffff,'\n');
		}		
	}while(N<0);
	
	int count=calcount(N);
	if ((N-check(N,count))==0){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	
return 0;	
}

int  calcount(int n){
	int count=1;
	while(n>10){
		if ((n/10)!=0){
		count++;
		n/=10;
		}
	}
return count;
}

int check(int n,int count){
	int a[count],s=0;
	for (int i=0;i<count;i++){
		a[i]=n%10;
		n/=10;
	}
	
	for (int j=0;j<count;j++){
		s+=pow(a[j],count);
	}
return s;
}
