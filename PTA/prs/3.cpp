#include<bits/stdc++.h>
void printHourglass() {
    int x;
    char t;
    std::cin >> x >> t; // 输入字符数量和要使用的字符
    int total = 1; // 已使用的字符数量，初始化为1（中心点）
    int sum = 1; // 当前层的字符数量，初始化为1（中心点）
    int cen = 0; // 中心行所在的行数，初始化为0
    while (total < x) { // 查找中心点所在的行数和沙漏的总行数
        int temp = total;
        sum += 2; // 字符数量加2，计算下一层的字符数量
        temp += sum * 2; // 总字符数量加上下一层的字符数量之和
        if (x < temp) break; // 如果总字符数量已经大于等于输入数量，退出循环
        cen++; // 中心行的行数加1
        total = temp; // 更新已使用的字符数量
    }
    int i = cen;
    int m = 1; // 初始化要输出的空格数量
    int cnt = 0; // 记录输出的行数，用于计算下半部分的空格数量
    for (i; i > 0; i--) { // 循环输出上半部分
        for (int k = i * 2 + 1; k > 0; k--) // 输出一整行的字符
            std::cout << t;
        for (int j = 1; j < m; j++) // 输出该行前面的空格
            std::cout << " ";
        std::cout << std::endl;
        for (int j = 1; j <= m; j++) // 输出该行前面的空格，为下一行做准备
            std::cout << " ";
        m++; // 下一行的空格数量加1
        cnt++; // 行数加1
    }
    std::cout << t << std::endl; // 输出中心行
    int j = 1;
    for (j; j <= cen; j++) { // 循环输出下半部分
        int n = cnt - 1; // 计算要输出的空格数量
        for (n; n > 0; n--) 
            std::cout << " ";
        for (int k = 1; k <= j * 2 + 1; k++)
            std::cout << t;
        std::cout << std::endl;
        cnt--; // 行数减1
    }
    std::cout << x - total; // 输出剩余字符数
}

int main(){
    printHourglass();
    return 0;
}