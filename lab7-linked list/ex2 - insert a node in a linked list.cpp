#include <iostream>
#include <fstream>
using namespace std;

//ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n){
	node *head=new node;
	cin>>head->data;
	if(n==1){
		head->next=NULL;
		return head;
	}
	
	node *cur=new node;
	cin>>cur->data;
	head->next=cur;
	while(n >= 3){ // already creat 2 node;
		node *sub=new node;
		cin>> sub->data;
		cur->next=sub;
		cur=sub;
		n--;
	}
	cur->next=NULL;
return head;
}

node *insertNode(node *head, node *newNode, int position)
{
	if(position<=0) return head;
	if(position==1){
		newNode->next=head;
		head=newNode;
		return head;
	}
	
	//
	int count=2;
	node *temp;
	temp=head;
	while(temp!=NULL){	
		if(count==position){
			newNode->next=temp->next;
			temp->next=newNode;
			return head;
		}
		count++;
		
		if(temp->next==NULL){		// position > number of node:   	//the case when no more node exsit			
			temp->next=newNode;
			return head;
		}
		temp=temp->next;
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
//  ifs.open(argv[1]);

  int n = 0;
 // ifs >> n;
 cout<<"input n:";
  cin>>n;
  if (n > 0)
  {
    node *head = createLinkList(n);

    node *newNode = new node();
    cout<<"input newNode-> data: ";
    cin >> newNode->data;
    int position = 0;
    cout<<"input position: ";
    cin >> position;
    head = insertNode(head, newNode, position);

    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

 // ifs.close();
  return 0;
}
