#include <iostream>
#include <string.h>
using namespace std;
struct node{
	char data;
	node *next;
};
node *inputdata (){
	cout<<"Input a string: ";
	string str;
	getline(cin,str,'\n');
	int count=str.length();
	node *head =new node;
	node *cur =new node;
	
	if(count==1) {
		head->data = str[0];
		head->next=NULL;
		return head;
	}
	else{
		head->data = str[0];
		head->next=cur;
		for(int i=1 ; i<count;i++){
			node *sub=new node;
			cur->data=str[i];
			if (i== (count-1)) break;
			cur->next=sub;
			cur=sub;
		}
		cur->next=NULL;
	}
return head;
}

void outputdata(node *head){
	while(head!=NULL){
		
		if(head->next!=NULL) cout<<head->data<<" ";
		if(head->next==NULL) cout<<head->data;
		head=head->next;
	} 
return;
}


bool checkreverse(node *head){
	char arr[30];
	int i=0;
	while(head!=NULL){
		arr[i]=head->data;
		i++;
		head=head->next;
	}
	for(int k =0;k<i;k++){
		if (arr[k] != arr[i-1-k]){
			return false;
		}
	}
	
return true;
}

int main(){
	int n=140;
	cout<<1<<" x ";
	for (int i=2;i<n/2;i++){
		while (n%i==0){ 
			cout<<i<<" x " ;
			n/=i;
		}
	}
	if(n!=1) cout << n;
	cout<<"\n";
	
	node *head;
	head=inputdata();
	cout<<'\n'<<"-------------------------------------------------------"<<'\n';
	outputdata(head);
	cout<<'\n'<<"-------------------------------------------------------"<<'\n';
	if(checkreverse(head)){
		cout<<"EQUAL !"<<'\n';
	}
	else{
		cout<< " NOT EQUAL @@"<<'\n';
	}
	
	
return 0;
}
