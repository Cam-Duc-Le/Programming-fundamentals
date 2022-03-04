#include <iostream>
#include <fstream>
using namespace std;
int gcd(int p, int q)// greatest comon divisor
{
	//todo
	//euclid methhod
	if(p <= 0 || q<=0){
		return 1;
	}
	if(p==q){
		return p;
	}
	if(p>q){
			p-=q;
			return gcd(p,q);
	}
	else{
			q-=p;
			return gcd(p,q);
	}

	return 1;
}


int main(int narg, char** argv)
{
	//ifstream ifs;
	//ifs.open(argv[1]);
	int p;
	int q;
	try
	{
		cout<<"input p, q in order:";
		cin >> p;
		cin >> q;
		cout << gcd(p, q) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	//ifs.close();
	return 0;
}
