#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
// libraries CHO4
int main(){
	int a,b,d;
	string urname,myname;
	cout<<"tell me  ";
	getline(cin,urname);
	getline(cin,myname);// process will end when u type "," or "enter" is default denotation
	strcat(urname,myname);
	cout<<urname;
/*	cout<<"hello"<<'t'<<urname<<'\n'<<"input a ,b ,d:  ";
	cin>>a>>b>>d;
*/	
	ifstream ifs; // type : input file stream
	ifs.open("input.txt",ios::in);// open file named input.txt  // and ios::in; fstream:in ; ifstream:in ; is the same!
	char c=ifs.get();   //get 1 character from file
	while (ifs.good()){
		cout<<c<<'\t';
		c=ifs.get();
	}
	ifs.close();

	ofstream ofs;
	ofs.open("input.txt",ios::out);// ofstream or fstream or iostream or ios is the same
	ofs <<" camleduc789";
	ofs.close();

	return 0;
}
