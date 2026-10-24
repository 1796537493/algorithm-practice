#include<iostream>
using namespace std;
#define MAX_SIZE 6
struct SeqQueue {
	int data[MAX_SIZE];
	int front = 0;
	int rear = 0;
};
void push(SeqQueue &S,int x) {
	if ((S.rear + 1) % MAX_SIZE == S.front) {
		cout << "队列满了，入队失败" << endl;
		return;
	}
	S.data[S.rear] = x;
	S.rear = (S.rear + 1) % MAX_SIZE;
}
void pop(SeqQueue &S,int &e) {
	if (S.rear == S.front) { cout << "队列为空" << endl; return; }
	e = S.data[S.front];
	cout << S.data[S.front] << endl;
	S.front = (S.front + 1) % MAX_SIZE;
}
int getlength(SeqQueue &S) {
	return (S.rear - S.front + MAX_SIZE) % MAX_SIZE;
}
int main() {
	SeqQueue S;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		push(S, x);
	}
	int e;
	pop(S, e);
	cout<<getlength(S)<<endl;
}