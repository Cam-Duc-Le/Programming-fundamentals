#include <iostream>

using namespace std;
void transposition(int rows,int cols,int **matrix){
	bool k=true;
	int a[cols][rows];
	for(int i=0;i<cols;i++){
		for(int j=0;j<rows;j++){
			a[i][j]=matrix[j][i];
		}
	}
	for(int i=0;i<cols;i++){
		for(int j=0;j<rows;j++){
			if(k){
				cout<<a[i][j];
				k=false;
			}
			else{
				cout<<" "<<a[i][j];
			}
		}
		cout<<'\n';
		k=true;
	}
}
int main(int narg, char**argv){
	int rows,cols;
	cout<<"input rows and colums respectively: ";
	cin>> rows>> cols;	
	cout<<"input value of A[i][j]: ";
	// input dynamic 2-dimension array
	int **matrix=new int *[rows];
try
{
	int i=0,j=0;
	for (int i=0;i<rows;i++){
		matrix[i]=new int [cols];
		for(int j=0;j<cols;j++){
			cin>>matrix[i][j];
		}
	} 

	//transpose
	transposition(rows,cols,matrix);
}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}
return 0;
}

