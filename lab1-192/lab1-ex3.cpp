#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int a,b,c;
	do{
		cout<<"input 3 sides of a triangle: ";
		cin>>a>>b>>c;
		if(!cin.good()){ 
			cin.clear();
			cin.ignore(0x0fffffff,'\n');
		}		
	}while(a<=0||b<=0||c<=0);
	
	if (a==b&&b==c){
		cout<<"Equilateral triangle";
	}
	else if(a==b||b==c||a==c){
		cout<<" Isosceles triangle";
	}
	else {
		cout<<"Scalene triangle";
	}

return 0;
}


