#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

void readArray(int **a){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				for(int k=j+1;k<10;k++){
					a[i][k]=0;
				}
				break;//break of second loop
			}
		}
	}
}

void printArray(int **a){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j<9){
				cout<<a[i][j]<<" ";
			}else{
				cout<<a[i][j];
			}
		}
		
		cout<<'\n';
	}
	
}

int main(int narg, char **argv)
{
 // ifs.open(argv[1]);
// declare a 2 dimension array 10x10
  int **arr;
  arr = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    arr[i] = new int[10];
  }

  readArray(arr);
  printArray(arr);

  for (int i = 0; i < 10; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;

//  ifs.close();
  return 0;
}
