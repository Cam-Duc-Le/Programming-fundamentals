#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n) // new node added to the end 
{
	node *head=new node;
	cin>>head->data;
	if(n==1){
		head->next=NULL;
		return head;
	}
	
	node *cur=new node;
	cin>> cur->data;
	head->next=cur;
	
	while(n>=3){
		node *sub=new node;
		cin>>sub->data;
		cur->next=sub;
		cur=sub;
		n--;
	}
	cur->next=NULL;
return head;
}
void print(node *head)
{
  while (head != NULL)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int narg, char **argv)
{
//  ifs.open(argv[1]);
	cout<<"input n: ";
  int n = 0;
  cin >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

//  ifs.close();
  return 0;
}
