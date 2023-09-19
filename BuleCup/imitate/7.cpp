/* 小蓝有一个 n * m 大小的矩形水域，小蓝将这个水域划分为 n 行 m 列，行数从 1 到 n 标号，列数从 1 到 m 标号。每行和每列的宽度都是单位 1 。
现在，这个水域长满了水草，小蓝要清理水草。每次，小蓝可以清理一块矩形的区域，从第 r1 行（含）到第 r2 行（含）的第 c1 列（含）到 c2 列（含）。
经过一段时间清理后，请问还有多少地方没有被清理过。 　　 输入第一行包含两个整数 n, m，用一个空格分隔。 第二行包含一个整数 t ，表示清理的次数。 
接下来 t 行，每行四个整数 r1, c1, r2, c2，相邻整数之间用一个空格分隔，表示一次清理。请注意输入的顺序。

输出一行包含一个整数，表示没有被清理过的面积。 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int num[105][105] = {0};
int main() {
    int W, H, n;cin >> W >> H >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                if (num[j][k] == 0) {
                    num[j][k] = 1;count++;
                }
            }
        }
    }
    cout << W * H - count << endl;
    return 0;
}