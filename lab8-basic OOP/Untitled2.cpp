#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#include <vector>
#define FILENAME "testcase001.txt"
using namespace std;
class Integer {
	int value;
public:
    Integer () {};
	// Methods prototypes only
	
//	void	display();
//	int getvalue();
	Integer(int _value);
	operator int const();
	Integer operator+(const int Int);
	void operator=(const Integer Int);
	bool operator==(const int &Int);
	bool operator>(const Integer Int);
	bool operator<(const Integer Int);
};
/**
 * Student implement Integer's methods here
*/
/*
int Integer::getvalue(){
	return value;
}
void Integer::display(){
	cout<<"value:"<<value;
}*/
Integer::Integer(int _value){
	value=_value;
}
void Integer::operator=(const Integer Int){
	this->value=Int.value;
}
bool Integer::operator ==(const int &Int ){
	if(this ->value== Int ) return true;
	else return false;
}
bool Integer::operator >(const Integer Int ){
	if(this->value > Int.value ) return true;
	else return false;
}
bool Integer::operator <(const Integer Int ){
	if(this->value < Int.value ) return true;
	else return false;
}
Integer  Integer::operator+(const int  Int){
	Integer m;
	m.value=this->value+Int;
	return m;
}
Integer::operator int const ()
{
	return static_cast<int>(value);
}


Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

int main(){
	int numberOfElements=3;
	Integer* arr = new Integer[numberOfElements];
	arr[0]=467;
	arr[1]=500;
	arr[2]=334;
	cout << max(arr, numberOfElements);
return 0;
}
