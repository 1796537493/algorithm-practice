#include<iostream>
using namespace std;
struct Qnode {
	int val;
	Qnode *next;
	Qnode(int x):val(x),next(nullptr){}
	Qnode(){}
};
struct Queuelist {
	Qnode *front;
	Qnode *rear;
	Queuelist() {
		front = rear = new Qnode;
	}
};
void push(Queuelist &q,int x) {
	Qnode *temp = new Qnode(x);
	q.rear->next = temp;
	q.rear = temp;
}
void pop(Queuelist &q, int &e) {
	Qnode *temp = q.front->next;
	q.front->next = temp->next;
	e = temp->val;
	delete temp;
}
int getlength(Queuelist &q) {
	Qnode *temp = q.front->next;
	int num = 0;
	while (temp != nullptr) {
		num++;
		temp = temp->next;
	}
	return num;
}
void destroy(Queuelist &q) {
	Qnode *temp = q.front;
	while (temp != nullptr) {
		q.front = temp->next;
		delete temp;
		temp = q.front;
	}
}
int main() {
	Queuelist q;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		push(q, x);
	}
	int e;
	pop(q, e);
	cout << e<<endl;
	cout << getlength(q);
	destroy(q);
}
