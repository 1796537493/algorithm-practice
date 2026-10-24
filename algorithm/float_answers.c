#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// 按题目约定：阶码4位(2位阶符+2位数值)，尾数8位(2位数符+6位数值)，均变形补码
// 这里用 double 独立验算每一步的真实数学值，交叉检查手算答案

void show_double(const char *label, double v) {
    printf("%-28s = %.10g\n", label, v);
}

int main(void) {
    // 题目1: -6.25
    printf("=== 题1: -6.25 ===\n");
    show_double("-6.25", -6.25);

    // 题目2: 0.15625  (= 0.00101b = 0.101 * 2^-2)
    printf("\n=== 题2: 0.15625 ===\n");
    show_double("0.15625", 0.15625);

    // 题目3: x+y  1.5 + 0.25
    printf("\n=== 题3: 1.5 + 0.25 ===\n");
    show_double("1.5 + 0.25", 1.5 + 0.25);

    // 题目3b: 对阶损失 1e20 + 1 - 1e20 (用float演示)
    printf("\n=== 题3b: 对阶损失演示 ===\n");
    float big = 1e8f;
    printf("1e8f + 1.0f - 1e8f = %.1f  (期望1，实际看结果)\n", (big + 1.0f) - big);
    printf("1e8f + 1.0f        = %.1f\n", big + 1.0f);

    // 题目4: 溢出  x+y  最大值
    printf("\n=== 题4: 溢出判断 ===\n");
    printf("float 最大 = %.6g\n", 3.402823466e38f);
    float z = 1e38f;
    printf("1e38f + 1e38f      = %.6g  (inf = 溢出)\n", z + z);

    // 题目5: 0.1 的表示
    printf("\n=== 题5: 0.1 的误差 ===\n");
    printf("0.1f 实际存储 = %.20f\n", 0.1f);
    printf("0.1f - 0.1   = %.20e\n", (double)0.1f - 0.1);

    // 题目6: 1/3
    printf("\n=== 题6: 1/3 ===\n");
    printf("1.0f/3.0f = %.20f\n", 1.0f / 3.0f);

    return 0;
}
