//
// Created by 성누리 on 2019-04-04.
//

#include <cstdio>
#include <string.h>
using namespace std;
int n,maxx=-1,xx,yy;
int a[21][21],check[101];

void dfs(int x, int y, int cnt, int direction)
{
    if(cnt > 1 && x == xx && y == yy)
    {
        if(maxx < cnt-1) maxx = cnt-1;
        return;
    }

    if(direction == 0)
    {
        if(x+1 <= n && y-1 >= 1)
        {
            if(check[a[x+1][y-1]] == 0) {
                check[a[x+1][y-1]] = 1;
                dfs(x + 1, y - 1, cnt + 1, 1);
                check[a[x+1][y-1]] = 0;
            }
        }
    }
    else if(direction == 1)
    {
        if(x+1 <= n && y-1 >= 1)
        {
            if(check[a[x+1][y-1]] == 0) {
                check[a[x+1][y-1]] = 1;
                dfs(x + 1, y - 1, cnt + 1, 1);
                check[a[x+1][y-1]] = 0;
            }
        }
        if(x+1 <= n && y+1 <= n)
        {
            if(check[a[x+1][y+1]] == 0)
            {
                check[a[x+1][y+1]] = 1;
                dfs(x+1, y+1, cnt+1, 2);
                check[a[x+1][y+1]] = 0;
            }
        }
    }
    else if(direction == 2)
    {
        if(x+1 <= n && y+1 <= n)
        {
            if(check[a[x+1][y+1]] == 0)
            {
                check[a[x+1][y+1]] = 1;
                dfs(x+1, y+1, cnt+1, 2);
                check[a[x+1][y+1]] = 0;
            }
        }
        if(x-1 >= 1 && y+1 <= n)
        {
            if(check[a[x-1][y+1]] == 0)
            {
                check[a[x-1][y+1]] = 1;
                dfs(x-1, y+1, cnt+1, 3);
                check[a[x-1][y+1]] = 0;
            }
        }
    }
    else if(direction == 3)
    {
        if(x-1 >= 1 && y+1 <= n)
        {
            if(check[a[x-1][y+1]] == 0)
            {
                check[a[x-1][y+1]] = 1;
                dfs(x-1, y+1, cnt+1, 3);
                check[a[x-1][y+1]] = 0;
            }
        }
        if(x-1 >= 1 && y-1 >= 1)
        {
            if(check[a[x-1][y-1]] == 0)
            {
                check[a[x-1][y-1]] = 1;
                dfs(x-1, y-1, cnt+1, 4);
                check[a[x-1][y-1]] = 0;
            }
            else if(x-1 == xx && y-1 == yy) dfs(x-1,y-1,cnt+1,4);
        }
    }
    else{
        if(x-1 >= 1 && y-1 >= 1)
        {
            if(check[a[x-1][y-1]] == 0)
            {
                check[a[x-1][y-1]] = 1;
                dfs(x-1, y-1, cnt+1, 4);
                check[a[x-1][y-1]] = 0;
            }
            else if(x-1 == xx && y-1 == yy) dfs(x-1,y-1,cnt+1,4);
        }
    }
}

int main() {
    int test_case, T;

    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for (test_case = 1; test_case <= T; test_case++) {
        scanf("%d\n", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d ", &a[i][j]);
            }
            scanf("\n");
        }

        maxx = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                check[a[i][j]] = 1;
                xx = i;
                yy = j;
                dfs(i, j, 1, 0);
                memset(check, 0, sizeof(check));
            }
        }

        printf("#%d %d\n", test_case, maxx);
    }
    return 0;
}

/*
 9  7 13  9 31 15  7  1 13 33 11 24  7 36
21 22  6 19 23  4  6 21 14 36  9  4 30 21
17  2 30 13 26 36  2 13 32 27 36  5 28 16
 8 20 12 16 31 10 32 15 19 24 34 20  1 16
17 18 22  3 10  2 30 26 27 29 10 16 24 12
25 32 31 20 10 29 19 11 32 23 28 20 33 24
 9 13 19  4  6 27 24  5 16  2  8 34  2  7
21  5  5 26  2 35  7 36 21 22 23 33  2  6
16 21 15 21 12 11 13 28  3  3 14 23 16  4
 1 31 35 33 23 29 12 18 24 25 19 33 17 13
29  6 30 19 33 14 35 14  6 23 27 16 12 24
26 31 30 10 16 21  7  4 16 25 31 19 21  8
12  5  2  4  4 27 29  2 18 20 19 26 32 31
 */