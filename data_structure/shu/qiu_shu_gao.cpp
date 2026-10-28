#include<iostream>
#include<algorithm>
using namespace std;
struct treenode{
    int val;
    treenode *left;
    treenode *right;
    treenode(int x):val(x),left(nullptr),right(nullptr){}
    treenode(){}
};
int high(treenode *A){
    if(A==nullptr){
        return 0;
    }
    int lefthigh=high(A->left);
    int righthigh=high(A->right);
    return max(lefthigh,righthigh)+1;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    treenode *A=new treenode(c);
    treenode *B=new treenode(a);
    treenode *C=new treenode(b);
    A->left=B;
    A->right=C;
    cout<<high(A);
}