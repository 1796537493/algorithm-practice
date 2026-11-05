//用笨方法实现稀疏矩阵的转置
#include <iostream>
using namespace std;

const int MAXSIZE = 12500;

// 定义三元组结构体
struct Triple {
	int i;   // 行号
	int j;   // 列号
	int val; // 值
};

// 定义稀疏矩阵结构体
struct TSMatrix {
	Triple data[MAXSIZE + 1];
	int mu; // 矩阵的行数
	int nu; // 矩阵的列数
	int tu; // 非零元素的个数
};

int main() {
	TSMatrix M, T;

	// 1. 初始化原矩阵 M 的信息 (对应 PPT 里的 5 行 6 列，6 个非零元)
	M.mu = 5;
	M.nu = 6;
	M.tu = 6;

	// 直接手动填入 M 的三元组数据（为了方便测试，不用手敲输入了）
	// 这里使用从 0 开始的下标，依次存入
	M.data[0] = { 1, 3, 9 };
	M.data[1] = { 1, 5, -7 };
	M.data[2] = { 3, 4, 8 };
	M.data[3] = { 4, 1, 5 };
	M.data[4] = { 4, 6, 2 };
	M.data[5] = { 5, 5, 16 };

	// 2. 初始化转置矩阵 T 的基础信息
	T.mu = M.nu; // 行数变列数 (6)
	T.nu = M.mu; // 列数变行数 (5)
	T.tu = M.tu; // 非零元个数不变 (6)

	// 3. 开始“笨方法”转置 (双重 for 循环)
	int q = 0; // q 是 T.data 的存储指针，从下标 0 开始

	// 外层循环：按 M 的列号枚举 (从第 1 列到第 6 列)
	for (int col = 1; col <= M.nu; col++) {

		// 内层循环：遍历 M 的所有非零元素
		for (int p = 0; p < M.tu; p++) {

			// 如果当前元素的列号，刚好等于我们正在找的列 (col)
			if (M.data[p].j == col) {
				// 进行转置：行列互换，值不变
				T.data[q].i = M.data[p].j;
				T.data[q].j = M.data[p].i;
				T.data[q].val = M.data[p].val;

				q++; // 找到一个，存好后，指针 q 往后挪一格
			}
		}
	}

	// 4. 打印输出结果
	cout << "原矩阵 M 的三元组表：" << endl;
	for (int k = 0; k < M.tu; k++) {
		cout << "(" << M.data[k].i << ", " << M.data[k].j << ", " << M.data[k].val << ")" << endl;
	}

	cout << "\n转置后矩阵 T 的三元组表 (按行优先)：" << endl;
	for (int k = 0; k < T.tu; k++) {
		cout << "(" << T.data[k].i << ", " << T.data[k].j << ", " << T.data[k].val << ")" << endl;
	}

	return 0;
}