//
// Created by 성누리 on 2019-04-11.
//

#include <cstdio>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

queue< pair<int, int> > q, copy_q;
int n,m,k;
int way_x[5] = {0, -1, 1, 0, 0}, way_y[5] = {0, 0, 0, -1, 1}, way[5]={0, 2, 1, 4, 3};

struct sMap{
    int cnt;
    int direction;
    int cntMax;
} map[101][101], copy_map[101][101];
void bfs()
{

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int d = map[x][y].direction;
        int c = map[x][y].cnt;
        q.pop();

        if(x+way_x[d] >= 0 && x+way_x[d] < n && y+way_y[d] >= 0 && y+way_y[d] < n) {
            //겹치지 않는 경우
            if (copy_map[x + way_x[d]][y + way_y[d]].cnt == 0) {
                copy_q.push({x + way_x[d], y + way_y[d]});

                //가장자리에 도착했을 경우
                if (x + way_x[d] == 0 || x + way_x[d] == n - 1 || y + way_y[d] == 0 || y + way_y[d] == n - 1) {
                    copy_map[x + way_x[d]][y + way_y[d]].cnt = c / 2;
                    copy_map[x + way_x[d]][y + way_y[d]].direction = way[d];
                    copy_map[x + way_x[d]][y + way_y[d]].cntMax = c / 2;
                }
                    //그렇지 않은 경우
                else {
                    copy_map[x + way_x[d]][y + way_y[d]].cnt = c;
                    copy_map[x + way_x[d]][y + way_y[d]].direction = d;
                    copy_map[x + way_x[d]][y + way_y[d]].cntMax = c;
                }
            }
                //겹치는 경우
            else {

                //가장자리에 도착했을 경우
                if (x + way_x[d] == 0 || x + way_x[d] == n - 1 || y + way_y[d] == 0 || y + way_y[d] == n - 1) {
                    int dr = copy_map[x + way_x[d]][y + way_y[d]].cntMax > c / 2 ? copy_map[x + way_x[d]][y +
                                                                                                       way_y[d]].direction
                                                                              : way[d];
                    if(copy_map[x + way_x[d]][y + way_y[d]].direction != dr)
                    {
                        copy_map[x + way_x[d]][y + way_y[d]].cntMax = c/2;
                    }
                    copy_map[x + way_x[d]][y + way_y[d]].direction = dr;
                    copy_map[x + way_x[d]][y + way_y[d]].cnt += c / 2;
                }
                    //그렇지 않은 경우
                else {
                    int dr = copy_map[x + way_x[d]][y + way_y[d]].cntMax > c ? copy_map[x + way_x[d]][y +
                                                                                                   way_y[d]].direction
                                                                          : d;
                    if(copy_map[x + way_x[d]][y + way_y[d]].direction != dr)
                    {
                        copy_map[x + way_x[d]][y + way_y[d]].cntMax = c;
                    }
                    copy_map[x + way_x[d]][y + way_y[d]].direction = dr;
                    copy_map[x + way_x[d]][y + way_y[d]].cnt += c;
                }
            }
        }
    }
    swap(map,copy_map);
}

int main()
{
    int test_case, T;
    int x,y,c,d;

    scanf("%d\n", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d\n", &n, &m, &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d %d %d %d\n", &x, &y, &c, &d);
            map[x][y].cnt = c;
            map[x][y].direction = d;
            q.push({x, y});
        }

        int sum = 0;

        for (int i = 1; i <= m; i++) {
            bfs();
            swap(q,copy_q);
            queue< pair<int, int> > cq;
            swap(copy_q, cq);
            memset(copy_map,0, sizeof(copy_map));
        }

        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(map[i][j].cnt != 0) sum += map[i][j].cnt;
            }
        }
        printf("#%d %d\n", test_case, sum);
        queue< pair<int, int> > cq;
        swap(q, copy_q);
        swap(copy_q, cq);
        memset(map,0,sizeof(map));
    }
    return 0;
}