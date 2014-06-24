/*典型的一道迷宫搜索题，

很容易想到BFS，但是难点在于在迷宫的状态改变后如何处理的问题，

起初，我的想法是先从起点开始DFS,然后当改变迷宫的时候先不做处理，而是将改变后的迷宫状态入队列，当处理完当然迷宫的时候，再出队列一张变化后的地图。即BFS+DFS的暴力方法，地图的状态采用二进制压缩，保存改变的位置，然后由于状态太多，MLE和TLE都不可避免。

后来，经大牛点拨，想法如下：

直接BFS，然后直接从二进制压缩迷宫的状态，包括对墙壁和炸药的处理信息，在对每个状态进行BFS的时候同时传递当然迷宫的状态，包括对墙壁和炸药的处理信息！然后用三维的hash进行状态判重，hash[x][y][炸药数]！

31MS ac了，效率上排名第三，还算不错！
*/
#include <iostream>
#include <queue>
using namespace std;

struct node
{
    __int64 x, y, step;
    __int64 bomb, flag;
}in, out;

char map[10][10];
__int64 hash[10][10][10];
__int64 r, c;
__int64 finish;

queue<node> all;

int main()
{
    bool find;
    __int64 i, j;
    while (scanf("%I64d %I64d", &r, &c) == 2)
    {
        if (r == 0 && c == 0)
        {
            break;
        }
        memset (hash, 0, sizeof(hash));

        find = false;
        finish = 0x7fffffffff;

        for (i = 0; i < r; i++)
        {
            scanf("%s", map[i]);
            for (j = 0; j < c && !find; j++)
            {
                if (map[i][j] == 'S')
                { 
                    in.x = i;
                    in.y = j;
                    find = true;
                }
            }
        }

        in.step = 0;
        in.bomb = 0;
        in.flag = 0;
        all.push(in);
        while (!all.empty())
        {
            out = all.front();
            all.pop();
            if (out.x < 0 || out.x >= r || out.y < 0 || out.y >= c)
            {
                continue;
            }

            if (hash[out.x][out.y][out.bomb] != 0 && hash[out.x][out.y][out.bomb] < out.step)
            {
                continue;
            }

            hash[out.x][out.y][out.bomb] = out.step;

            if (map[out.x][out.y] == 'D')
            {
                if (out.step < finish)
                {
                    finish = out.step;
                }
                continue;
            }
            else if (map[out.x][out.y] == 'X')
            {
                __int64 pos = __int64(1) << (out.x * c + out.y);
                if ((out.flag & pos) == 0)
                {
                    if (out.bomb == 0)
                    {
                        continue;
                    }
                    out.bomb --;
                    out.step ++;
                    out.flag += pos;
                }
            }
            else if (map[out.x][out.y] > '0' && map[out.x][out.y] <= '9')
            {
                __int64 pos = __int64(1) << (out.x * c + out.y);
                if ((out.flag & pos) == 0)
                {
                    out.bomb += map[out.x][out.y] - '0';
                    out.flag += pos;
                }
            }
            in = out;
            in.x = out.x + 1;
            in.step++;
            all.push(in);

            in = out;
            in.x = out.x - 1;
            in.step++;
            all.push(in);

            in = out;
            in.y = out.y + 1;
            in.step++;
            all.push(in);

            in = out;
            in.y = out.y - 1;
            in.step++;
            all.push(in);
        }
        if (finish == 0x7fffffffff)
        {
            printf("-1\n");
        }
        else
        {
            printf("%I64d\n", finish);
        }
    }    
    return 0;
}
 
