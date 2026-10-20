#include<iostream>
using namespace std;

// 参数顺序改为：底数 b，指数 exp，模数 m
long long fast_pow(long long b, long long exp, long long m) {
	long long result = 1;
	b = b % m; // 底数取模
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * b) % m;
		}
		b = (b * b) % m;
		exp = exp / 2;
	}
	return result;
}

int main() {
	long long b, exp, m;
	// 输入顺序也对应改为：底数 指数 模数
	cin >> b >> exp >> m;

	// 调用时按顺序传
	cout << fast_pow(b, exp, m);
	return 0;
}