//
// Created by 성누리 on 2019-04-11.
//

#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int n,w,h,ansMax=0,numCnt=0, to = 0;
int map[20][20], check[20][20];

void copy(int (*a)[20], int (*b)[20])
{
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void bfs(int xx, int yy, int (*map)[20])
{
    queue < pair<int, int> > q;
    q.push( {xx, yy} );

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        to++;

        for(int i = 1; i < map[x][y]; i++)
        {
            if(x-i >= 1 && check[x-i][y] == 0 && map[x-i][y] > 0) {
                q.push({x - i, y});
                check[x-i][y] = 1;
            }
            if(x+i <= h && check[x+i][y] == 0 && map[x+i][y] > 0) {
                q.push({x + i, y});
                check[x+i][y] = 1;
            }
            if(y-i >= 1 && check[x][y-i] == 0 && map[x][y-i] > 0) {
                q.push({x, y - i});
                check[x][y - i] = 1;
            }
            if(y+i <= w && check[x][y+i] == 0 && map[x][y+i] > 0) {
                q.push({x, y + i});
                check[x][y + i] = 1;
            }
        }
        map[x][y] = 0;
    }
}

void dfs(int cnt, int (*map)[20], int boom)
{
    int copyMap[20][20];

    if(cnt == n+1)
    {
        ansMax = max(ansMax, boom);
        return;
    }
    else if(boom == numCnt)
    {
        ansMax = boom;
        return;
    }

    for(int i = 1; i <= w; i++)
    {
        for(int j = 1; j <= h; j++)
        {
            if(map[j][i] > 0)
            {
                to = 0;
                copy(copyMap, map);
                memset(check, 0, sizeof(check));
                check[j][i] = 1;
                bfs(j, i, map);
                for(int s = 1; s <= w; s++)
                {
                    for(int k = h; k >= 1; k--)
                    {
                        if(map[k][s] == 0)
                        {
                            for(int sk = k-1; sk >= 1; sk--)
                            {
                                if(map[sk][s] > 0)
                                {
                                    map[k][s] = map[sk][s];
                                    map[sk][s] = 0;
                                    break;
                                }
                            }
                        }
                    }
                }

                dfs(cnt+1, map, boom+to);
                copy(map, copyMap);
                break;
            }
        }
    }
}

int main()
{
    int test_case, T;


    setbuf(stdout, NULL);
    scanf("%d\n", &T);

    for(test_case = 1; test_case <= T; test_case++)
    {
        numCnt = 0;

        scanf("%d %d %d\n", &n, &w, &h);
        for(int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++)
            {
                scanf("%d ", &map[i][j]);
                if(map[i][j] > 0) numCnt++;
            }
            scanf("\n");
        }

        ansMax = 0;
        dfs(1, map, 0);
        printf("#%d %d\n", test_case, numCnt-ansMax);
    }
    return 0;
}