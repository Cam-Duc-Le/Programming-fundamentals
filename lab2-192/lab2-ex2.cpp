#include <iostream>
using namespace std;
void Fibonacci(int n) {
	int fb=1,fb1=0,fb2=1,count=1 ;
	if(n==1){
		goto here;
	}
		do{
			fb=fb1+fb2;
			fb1=fb2;
			fb2=fb;
			count++;
		}while (count<n);
	here:
	;
	cout<<fb;
	cout<<"\n";
	
}
int main(int narg, char** argv){
	int a;
	try
	{
		cin>>a;
		{
			Fibonacci(a);
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

return 0;
}
