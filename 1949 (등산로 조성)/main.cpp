//
// Created by 성누리 on 2019-04-11.
//

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int n, k, ansMax=0;
int map[10][10], visit[10][10];

void dfs(int x, int y, int cnt, int doIt, int val)
{
    if(x-1 >= 1 && map[x-1][y] < val && visit[x-1][y] == 0)
    {
        visit[x-1][y] = 1;
        dfs(x-1, y, cnt+1, doIt, map[x-1][y]);
        visit[x-1][y] = 0;
    }
    if(x+1 <= n && map[x+1][y] < val && visit[x+1][y] == 0)
    {
        visit[x+1][y] = 1;
        dfs(x+1, y, cnt+1, doIt, map[x+1][y]);
        visit[x+1][y] = 0;
    }
    if(y-1 >= 1 && map[x][y-1] < val && visit[x][y-1] == 0)
    {
        visit[x][y-1] = 1;
        dfs(x, y-1, cnt+1, doIt, map[x][y-1]);
        visit[x][y-1] = 0;
    }
    if(y+1 <= n && map[x][y+1] < val && visit[x][y+1] == 0)
    {
        visit[x][y+1] = 1;
        dfs(x, y+1, cnt+1, doIt, map[x][y+1]);
        visit[x][y+1] = 0;
    }

    //깎을 경우
    if(doIt == 0) {
        for (int i = 1; i <= k; i++)
        {
            if(x-1 >= 1 && visit[x-1][y] == 0 && map[x-1][y]-i < val)
            {
                visit[x-1][y] = 1;
                dfs(x-1, y, cnt+1, 1, map[x-1][y]-i);
                visit[x-1][y] = 0;
            }
            if(x+1 <= n && visit[x+1][y] == 0 && map[x+1][y]-i < val)
            {
                visit[x+1][y] = 1;
                dfs(x+1, y, cnt+1, 1, map[x+1][y]-i);
                visit[x+1][y] = 0;
            }
            if(y-1 >= 1 && visit[x][y-1] == 0 && map[x][y-1]-i < val)
            {
                visit[x][y-1] = 1;
                dfs(x, y-1, cnt+1, 1, map[x][y-1]-i);
                visit[x][y-1] = 0;
            }
            if(y+1 <= n && visit[x][y+1] == 0 && map[x][y+1]-i < val)
            {
                visit[x][y+1] = 1;
                dfs(x, y+1, cnt+1, 1, map[x][y+1]-i);
                visit[x][y+1] = 0;
            }
        }
    }

    ansMax = max(ansMax , cnt);
}

int main()
{
    int test_case, T;
    int maxBong=0;

    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for(test_case = 1; test_case <= T; test_case++)
    {
        maxBong = 0;
        scanf("%d %d\n", &n, &k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++){
                scanf("%d ", &map[i][j]);
                maxBong = max(maxBong, map[i][j]);
            }
            scanf("\n");
        }

        ansMax = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(map[i][j] == maxBong) {
                    visit[i][j] = 1;
                    dfs(i, j, 1, 0, map[i][j]);
                    memset(visit, 0, sizeof(visit));
                }
            }
        }
        printf("#%d %d\n", test_case, ansMax);
    };
    return 0;
}