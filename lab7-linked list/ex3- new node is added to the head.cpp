#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n)  //new node is added to the head of the linked list
{
	node *cur=new node;
	cin>>cur->data;
	if(n==1){
		cur->next=NULL;
		return cur;
	}
	cur->next=NULL;
	node *head=new node;
	cin>>head->data;
	head->next=cur;
	
	while(n>=3){
		node *sub=new node;
		cin>>sub->data;
		sub->next=head;
		head=sub;
		n--;
	}
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
  //ifs.open(argv[1]);

  int n = 0;
  cout<<"input n: ";
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
