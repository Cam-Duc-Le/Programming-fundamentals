#include <iostream>

using namespace std;

class BaseClass{

public:

  void disp(){

    cout << "Function of Parent Class";

  }

};

class DerivedClass : public BaseClass {

public:

  void disp(){

    cout << "Function of Child Class";

  }

};
/*
class Animal

{

public:

  Animal(string name, int weight)

  {

    cout << name << " weigh " << weight << endl;

  }

};*/
class Animal

{

private:

  Animal(string name, int weight)

  {

    cout << name << " weigh " << weight << endl;

  }

};
int main(){

  BaseClass obj = DerivedClass();

  obj.disp();
  cout<<"\n";
 //Animal monkey = Animal("monkey", 20);
 //Animal* monkey = new Animal("monkey", 20);
 //Animal monkey = ("monkey", 20); wwrong
 //Animal monkey("monkey", 20);
   Animal monkey = Animal("monkey", 20);
  return 0;

}
