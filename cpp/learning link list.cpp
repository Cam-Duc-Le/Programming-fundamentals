#include <iostream>
#include <fstream>
using namespace std;

//ifstream ifs;

struct node
{
  int data;
  node *next;
};
typedef struct node NODE;
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
/* bai 1 : 135531
void func(struct node *head)

{

  if (head == NULL)

    return;

  cout << head->data;

  if (head->next != NULL)

    func(head->next->next);

  cout << head->data;

}*/
/* bai2 print from end to head
void func(struct node *head)

{

  if (head == NULL)

    return;

  func(head->next);

  cout << head->data;

}*/
static void reverse(struct node** head_ref)

{

    struct node* prev   = NULL;

    struct node* current = *head_ref;

    struct node* next;

    while (current != NULL)

    {

        next  = current->next;  

        current->next = prev;   

        prev = current;

        current = next;

    }



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
  node *head = createLinkList(n);
   // cout << head->next->next->next->data;

//func(head);
  
  return 0;
}
