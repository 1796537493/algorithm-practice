//二叉树的层序遍历，它挺特别的，和前序，中序，后续都不一样
#include<iostream>
#include<queue>
using namespace std;
struct treenode{
    int val;
    treenode *left;
    treenode *right;
    treenode(int x):val(x),left(nullptr),right(nullptr){}
    treenode(){}
};
void levelorder(treenode *A){
    if(A==nullptr){return;}
    queue<treenode*>q;
    q.push(A);
    while(!q.empty()){
        treenode *node=q.front();
        q.pop();
        if(node==nullptr){
            cout<<"#"<<endl;
        }
        else{
            cout<<node->val<<endl;
            q.push(node->left);
            q.push(node->right);
        }
    }
}
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    treenode *A=new treenode(z);
    treenode *B=new treenode(x);
    treenode *C=new treenode(y);
    A->left=B;
    A->right=C;
    levelorder(A);
}