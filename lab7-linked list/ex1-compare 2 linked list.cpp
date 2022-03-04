#include <iostream>
#include <fstream>
using namespace std;

//ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n)
{
	int count=1;
	node *head=new node;
	cin >> head->data;
	if(n==1){
		head->next=NULL;
		return head;
	}
	
	node *cur= new node;
	cin>>cur->data;
	head->next=cur;
	while(count<=n-2){
		node *sub=new node;
		cin>> sub->data;
		cur->next=sub;
		cur=sub;
		count++;
	}
	cur->next=NULL;
return head;
}

bool isEqual(node *head1, node *head2)
{
	while(head1&& head2 ){
		if(head1->data != head2->data){
			return false;
		}
		head1=head1->next;
		head2=head2->next;
	}
	if(head1==NULL && head2!=NULL ){
		return false;
	}
	if(head1!=NULL && head2==NULL ){
		return false;
	}
	return true;
}
	
int main(int narg, char **argv)
{
  //ifs.open(argv[1]);

  int n = 0;
  cout<<"input n: ";
  cin >> n;
  if (n <= 0)
  {
    cout << "Invalid n" << endl;
    return 0;
  }
  node *head1 = createLinkList(n);
/*
	while(head1!=NULL){
		cout<<head1->data<<" - ";
		head1=head1->next;
	}
*/
  int m = 0;
  cout<<"input m: ";
  cin >> m;
  if (m <= 0)
  {
    cout << "Invalid m" << endl;
    return 0;
  }
  node *head2 = createLinkList(m);

	cout<<'\n'<<'\n';
	cout<<"final result: ";
    cout << isEqual(head1, head2) << endl;

 // ifs.close();
  return 0;
}
