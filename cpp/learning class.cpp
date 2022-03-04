#include <iostream>
using namespace std;

class Triangle { 
public: 
 static int numOfTriangle; 
private: 
 int edgeA; 
 int edgeB; 
 int edgeC; 
public: 
 Triangle(int edgeA = 0, int edgeB = 0, int edgeC = 0){ 
   this->edgeA = edgeA; 
   this->edgeB = edgeB; 
   this->edgeC = edgeC; 
   numOfTriangle++; 
 } 
 ~Triangle(){ 
   cout << --numOfTriangle; 
 } 
 double getArea() const; 
 int getPerimeter() const; 
}; 


int Triangle::numOfTriangle = 0; 


int main(){ 
 Triangle aList[5] = {Triangle(3,4,5)}; 
 cout << (*(aList + 2)).numOfTriangle; 
} 

