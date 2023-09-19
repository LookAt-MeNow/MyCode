#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0}; // 左上右下
int dy[4] = {0, -1, 0, 1};

struct point
{
    int x=0;
    int y=0;
    int step=0;
};
queue<point> r; // 定义一个队列，用来保存当前的坐标步数信息

int main()
{
    int n = 0, m = 0;
    int max = 0;
    int a[n][m];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            point start; // 定义刚开始位置的结构体
            start.x = i;
            start.y = j;
            start.step = 0;
            r.push(start); // 将第一个点入队

            while (!r.empty())
            {
                // 开始试探四个方向
                for (int k = 0; k < 4; k++)
                {
                    int x, y;
                    x = r.front().x + dx[k];
                    y = r.front().y + dy[k];
                    if (a[x][y] < a[r.front().x][r.front().x])
                    {
                        point tmpe;
                        tmpe.x = x;
                        tmpe.y = y;
                        tmpe.step = r.front().step + 1;
                        // 将数据保存在临时结构体并入队
                        r.push(tmpe);
                    }
                }
                if (max < r.front().step)
                {
                    max = r.front().step;
                }
                r.pop();
            }
           
        }
    }
    cout <<max;
        return 0;
}