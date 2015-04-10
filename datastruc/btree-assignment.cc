#include <iostream>
using namespace std;

struct node{
	int c;
	node* left;
	node* right;
	
	//bool operator<(conc node &rhs) conc{
	//	return ( c < rhs.c );
	//}
};

void prewalk(node* nd){



}
void postwalk(node* nd){




}
void inwalk(node* nd){




}

node* NewNode(int c){
	node* np = new node;
	np->c = c;
	np->left = 0;
	np->right = 0;
	return np;
}

/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, int c){  // inserts with order





}

	
void lfree(node* root){ //must be post order for deleting
	if (root->left != 0)
		lfree(root->left);
	if (root->right != 0)
		lfree(root->right);
	delete root;
}



int main(){
	
	const int iarray[7] = {4,2,6,1,3,5,7};
	node* root=0;
	
	int x;
	for (x=0; x < 7 ; x++)
	{
		insert(root, iarray[x]);
		//walk(root);
		//cout<<endl;
	}
	
	prewalk(root);
	cout<<endl;
	
	postwalk(root);
	cout<<endl;
	
	inwalk(root);
	cout<<endl;
	
	lfree(root);
	return (0);
}

