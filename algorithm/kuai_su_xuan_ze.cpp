//今天来写一个快速选择算法
//快速选择算法和快速排序算法其实是一样,只是目的不同
//花了我一个下午，┭┮﹏┭┮呜呜呜
#include<iostream>
#include<vector>
using namespace std;
void quickselect(vector<int>& v,int left,int right,int k) {
	int pivot = v[left];
	int i = left;
	int j = right;
	while (i < j) {
		while (i < j && v[j] >= pivot) { j--;}
		v[i] = v[j];
		while (i<j&&v[i] <= pivot) { i++; }
		v[j] = v[i];
	}
	v[i] = pivot;
	if (k == i) { cout << "找到第" << k << "小的数" << endl; return; }
	if (k < i) { right = i-1; quickselect(v, left, right, k); }
	if (k > i) { left = i + 1; quickselect(v, left, right, k);}
}
int main() {
	vector<int>v;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int left = 0;
	int right = n - 1;
	quickselect(v, left, right, k);
	cout << v[k];
}
//感觉我写了这些算法之后，过来一段时间还是很容易忘记呀