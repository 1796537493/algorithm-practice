//快速转置稀疏矩阵
#include <iostream>
using namespace std;

const int MAXSIZE = 12500;

struct Triple {
    int i;   // 行号
    int j;   // 列号
    int val; // 值
};

struct TSMatrix {
    Triple data[MAXSIZE + 1];
    int mu; // 行数
    int nu; // 列数
    int tu; // 非零元个数
};

// 快速转置函数
void FastTranspose(TSMatrix M, TSMatrix &T) {
    // 1. 初始化 T 的基础信息
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;

    if (T.tu == 0) return; // 如果没有非零元，直接返回

    // 2. 准备两个辅助数组（注意：为了和教材一致，下标从 1 开始用）
    int num[MAXSIZE + 1] = {0};  // num[col] 记录 M 中第 col 列有多少个非零元
    int cpot[MAXSIZE + 1] = {0}; // cpot[col] 记录 M 中第 col 列的第一个非零元在 T.data 中的起始位置

    // 3. 扫描一遍 M，统计每一列有多少个非零元（填满 num 数组）
    for (int t = 1; t <= M.tu; t++) {
        num[M.data[t].j]++; // M 的列号，就是统计的索引
    }

    // 4. 计算 cpot 数组（核心！）
    cpot[1] = 1; // 第 1 列的第一个元素，肯定放在 T 的第 1 个位置
    for (int col = 2; col <= M.nu; col++) {
        // 当前列的起始位置 = 前一列的起始位置 + 前一列的元素个数
        cpot[col] = cpot[col - 1] + num[col - 1];
    }

    // 5. 再次扫描 M，把元素精准放入 T（只扫这一遍！）
    for (int p = 1; p <= M.tu; p++) {
        int col = M.data[p].j;     // 看看这个元素属于哪一列
        int q = cpot[col];         // 查表，这一列该放到 T 的哪个位置？

        // 放入 T 中
        T.data[q].i = M.data[p].j;
        T.data[q].j = M.data[p].i;
        T.data[q].val = M.data[p].val;

        // ⚠️ 极其关键的一步：这个位置被占了，这一列的下一个元素要往后排
        cpot[col]++; 
    }
}

int main() {
    TSMatrix M, T;
    
    // 初始化 M (为了和 PPT 一致，这里我们手动填数据，且下标从 1 开始)
    M.mu = 5; M.nu = 6; M.tu = 6;
    M.data[1] = {1, 3, 9};
    M.data[2] = {1, 5, -7};
    M.data[3] = {3, 4, 8};
    M.data[4] = {4, 1, 5};
    M.data[5] = {4, 6, 2};
    M.data[6] = {5, 5, 16};

    FastTranspose(M, T);

    cout << "快速转置后矩阵 T 的三元组表 (按行优先)：" << endl;
    for (int k = 1; k <= T.tu; k++) {
        cout << "(" << T.data[k].i << ", " << T.data[k].j << ", " << T.data[k].val << ")" << endl;
    }

    return 0;
}