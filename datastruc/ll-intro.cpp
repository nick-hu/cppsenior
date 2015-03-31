
#include <iostream>
using namespace std;

struct node{
	string st;
	node* next;
};

void walk(node* nd){
	cout<< nd->st <<" ";
	if (nd->next  !=0 )
		walk(nd->next);
}

void length(node* nd, int& count){



}

node* NewNode(string s){
	node* np = new node;
	np->st = s;
	np->next = 0;
	return np;
}

//Must pass nd by ref or seg fault. We must change root node address in main.
void pushfront(node* &nd, string s){ 



}


void popfront(node* &nd){




}


/*can't pushback on root=0 since no node exists yet. So must check for it.
copy ctor called for nd pointer so root in main not changed. This is 
okay if one node already exists since we just add to the end of it.
But if no node exists yet (root=0) then we must change root addr so we
have to pass by ref also.*/

void pushback(node* &nd, string s){ 





}


void popback(node* &nd){





}


/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, string s){ 





}

	
void lfree(node* nd){



}
	


int main(){
	
	const char* sarray[6] = {"b","d","a","e","f","c"};
	node* root=0;
	
	int x;
	for (x=0; x<6 ; x++)
	{
		//pushback(root, sarray[x]);
		//pushfront(root, sarray[x]);
		insert(root, sarray[x]);
		walk(root);
		cout<<endl;
	}
	for (x=0; x<3 ; x++)
	{
		cout<<"popfront"<<endl;
		popfront(root);
		walk(root);
		cout<<endl;
	}
	insert(root, "zoo");
	walk(root);
	cout<<endl;	
	for (x=0; x<3 ; x++)
	{
		cout<<"popback"<<endl;
		popback(root);
		walk(root);
		cout<<endl;
	}
	pushback(root, "zzz");
	walk(root);
	cout<<endl;
	
	lfree(root);
	return 0;
}

	
