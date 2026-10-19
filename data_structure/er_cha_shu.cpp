#include<iostream>
using namespace std;
struct treenode {
	int val;
	treenode *left;
	treenode *right;
	treenode(int x):val(x),left(nullptr),right(nullptr){}
	treenode(){}
};
void preorder(treenode *root) {
	if (root == nullptr) { return; }
	cout << root->val << endl;
	preorder(root->left);
	preorder(root->right);
}
int main() {
	treenode *A = new treenode(1);
	treenode *B = new treenode(2);
	treenode *D = new treenode(3);
	treenode *E = new treenode(4);
	treenode *F = new treenode(5);
	treenode *C = new treenode(6);
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	C->right = F;
	preorder(A);
}//1 2 3 4 6 5