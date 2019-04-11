//
// Created by 성누리 on 2019-04-10.
//

#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int n,m,r,c,l,cnt=0;
int map[51][51], check[51][51];

void bfs()
{
    queue < pair< pair<int, int>, int> > q;
    //q.push( make_pair(make_pair(r,c), 1) );
    q.push( make_pair(make_pair(r,c), 1) );
    check[r][c] = -1;

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int moveCnt = q.front().second;

        if(moveCnt == l)
        {
            cnt += q.size();
            break;
        }

        cnt++;
        q.pop();

        if(map[x][y] == 1)
        {
            if(x-1 >= 0 && (map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6) && check[x-1][y] != -1) {
                q.push({{x - 1, y}, moveCnt + 1});
                check[x-1][y] = -1;
            }
            if(x+1 < n && (map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) && check[x+1][y] != -1) {
                q.push({{x + 1, y}, moveCnt + 1});
                check[x+1][y] = -1;
            }
            if(y-1 >= 0 && (map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5) && check[x][y-1] != -1) {
                q.push({{x, y - 1}, moveCnt + 1});
                check[x][y-1] = -1;
            }
            if(y+1 < m && (map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7) && check[x][y+1] != -1) {
                q.push({{x, y + 1}, moveCnt + 1});
                check[x][y+1] = -1;
            }
        }
        else if(map[x][y] == 2)
        {
            if(x-1 >= 0 && (map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6) && check[x-1][y] != -1) {
                q.push({{x - 1, y}, moveCnt + 1});
                check[x-1][y] = -1;
            }
            if(x+1 < n && (map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) && check[x+1][y] != -1) {
                q.push({{x + 1, y}, moveCnt + 1});
                check[x+1][y] = -1;
            }
        }
        else if(map[x][y] == 3)
        {
            if(y-1 >= 0 && (map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5) && check[x][y-1] != -1) {
                q.push({{x, y - 1}, moveCnt + 1});
                check[x][y-1] = -1;
            }
            if(y+1 < m && (map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7) && check[x][y+1] != -1) {
                q.push({{x, y + 1}, moveCnt + 1});
                check[x][y+1] = -1;
            }
        }
        else if(map[x][y] == 4)
        {
            if(x-1 >= 0 && (map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6) && check[x-1][y] != -1) {
                q.push({{x - 1, y}, moveCnt + 1});
                check[x-1][y] = -1;
            }
            if(y+1 < m && (map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7) && check[x][y+1] != -1) {
                q.push({{x, y + 1}, moveCnt + 1});
                check[x][y+1] = -1;
            }
        }
        else if(map[x][y] == 5)
        {
            if(y+1 < m && (map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7) && check[x][y+1] != -1) {
                q.push({{x, y + 1}, moveCnt + 1});
                check[x][y+1] = -1;
            }
            if(x+1 < n && (map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) && check[x+1][y] != -1) {
                q.push({{x + 1, y}, moveCnt + 1});
                check[x+1][y] = -1;
            }
        }
        else if(map[x][y] == 6)
        {
            if(x+1 < n && (map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) && check[x+1][y] != -1) {
                q.push({{x + 1, y}, moveCnt + 1});
                check[x+1][y] = -1;
            }
            if(y-1 >= 0 && (map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5) && check[x][y-1] != -1) {
                q.push({{x, y - 1}, moveCnt + 1});
                check[x][y-1] = -1;
            }
        }
        else if(map[x][y] == 7)
        {
            if(x-1 >= 0 && (map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6) && check[x-1][y] != -1) {
                q.push({{x - 1, y}, moveCnt + 1});
                check[x-1][y] = -1;
            }
            if(y-1 >= 0 && (map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5) && check[x][y-1] != -1) {
                q.push({{x, y - 1}, moveCnt + 1});
                check[x][y-1] = -1;
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
        scanf("%d %d %d %d %d\n", &n, &m, &r, &c, &l);
        for(int i = 0; i< n; i++) {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &map[i][j]);
            }
            scanf("\n");
        }

        cnt = 0;
        memset(check,0,sizeof(check));
        bfs();
        printf("#%d %d\n", test_case, cnt);
    }

    return 0;
}