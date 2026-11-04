//用优先队列的方式创建哈夫曼树，并输出树的带权路径长度
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    //这东西我也是第一次写，感觉挺有意思的，优先队列的用法也很巧妙
    priority_queue<int,vector<int>,greater<int>>pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    int wpl=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int sum=a+b;
        wpl+=sum;
        pq.push(sum);
    }
    cout<<wpl<<endl;
}