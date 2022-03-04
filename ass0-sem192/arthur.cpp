/*****Version 1.1***********/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
// Le Duc Cam-1952588

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0

int readFile(int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	char* file_name = "input.txt";
	ifstream in;
	in.open(file_name);
	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;
	in.close();
	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;
	in.close();
	return 1;

}


int calrealHP1(int wp1, int baseHP1, int ground){    // caculate realHP1- realHP of Knight 
	int realHP1;
	switch (wp1){
		case (0):{
			realHP1=baseHP1/10;
			if(ground==baseHP1){
				realHP1*=1.1;
			}
			if (realHP1>999){
				realHP1=999;
			}
			break;
		}
		case (1):{
			realHP1=baseHP1;
			if(ground==baseHP1){
				realHP1*=1.1;
			}
			if (realHP1>999){
				realHP1=999;
			}
			break;
		}  
		case(2):{
			realHP1=baseHP1;
			if(ground==baseHP1){
				realHP1*=1.1;
			}
			if (realHP1>999){
				realHP1=999;
			}
			break;
		}
		case(3):{
			realHP1=baseHP1;
			if(ground==baseHP1){
				realHP1*=1.1;
			}
			if (realHP1>999){
				realHP1=999;
			}
			else{
				realHP1*=2;
				if (realHP1>999){
				realHP1=999;
				}
			}
			break;
		}
	}
return realHP1;	
}


int calrealHP2(int wp2, int baseHP2, int ground){    // caculate realHP2- realHP of saxion 
	int realHP2;
	switch (wp2){
		case (0):{
			realHP2=baseHP2/10;
			if(ground==baseHP2){
				realHP2*=1.1;
			}
			if (realHP2>999){
				realHP2=999;
			}
			break;
		}
		case (1):{
			realHP2=baseHP2;
			if(ground==baseHP2){
				realHP2*=1.1;
			}
			if (realHP2>999){
				realHP2=999;
			}
			break;
		}  
		case(2):{
			realHP2=baseHP2;
			if(ground==baseHP2){
				realHP2*=1.1;
			}
			if (realHP2>999){
				realHP2=999;
			}
			break;
		}
		case(3):{
			realHP2=baseHP2;
			if(ground==baseHP2){
				realHP2*=1.1;
			}
			if (realHP2>999){
				realHP2=999;
			}
			break;
		}
	}
return realHP2;	
}


bool isPrimeNumber(int n) { //primenum function
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


void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		cout << s;
	}
}



int main(void){
	int realHP1,realHP2;
	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(baseHP1,baseHP2,wp1,wp2,ground);
	
	if (baseHP1==999){
		fOut=1;
	}
	 // baseHP1#999
	else{
		if (baseHP2==888){
			fOut=0.00;
		}
		// bonus section
		else {
			if(isPrimeNumber(baseHP1)==1 && isPrimeNumber(baseHP2)==0 ){
				fOut=0.99;
			}
			else if(isPrimeNumber(baseHP1)==0 && isPrimeNumber(baseHP2)==1 ){
				fOut=0.01;
			}
			else if(isPrimeNumber(baseHP1)==1 && isPrimeNumber(baseHP2)==1 ){
				if(baseHP1==baseHP2){
					fOut=0.50;
				}
				else if(baseHP1>baseHP2){
					fOut=0.99;
				}
				else {
					fOut=0.01;
				}
			}		
			else{          // calculate realHP when baseHP1#999 and baseHP2#888 and baseHP not a prime num using function above
				realHP1=calrealHP1(wp1,baseHP1,ground);				
				realHP2=calrealHP2(wp2,baseHP2,ground);
				// start calculate fOut by using realHP
				if(wp1==3 && wp2==2){
					fOut=float(realHP1-realHP2+999)/2000;
				}
				else if(wp1==2 && realHP1<realHP2){
					fOut=0.50;
				}
				else if(wp2==2 && realHP2<realHP1){
					fOut=0.50;
				}
				else{
					fOut=float(realHP1-realHP2+999)/2000;
				}
			}
		}
	}
	//write your code here

	display(fOut);
return 0;
}
