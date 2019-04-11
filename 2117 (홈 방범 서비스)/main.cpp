//
// Created by 성누리 on 2019-04-11.
//
/*
 * 운영 비용 : K*K + (K-1)*(K-1)
 */

#include <cstdio>
#include <algorithm>
using namespace std;

int n,m, ansMax=0;
bool check=false;
int map[21][21];

void find(int num)
{
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {

            if(i == 11)
            {
                i = i;
            }
            int info = 0;
            int cnt = 0;
            for(int s = 1; s <= num; s++) {
                if(s == 1)
                {
                    info++;
                    if(map[i][j] == 1) cnt++;
                    for(int k = 1; k <= num-s; k++)
                    {
                        if(j-k >= 1 && map[i][j-k] == 1) cnt++; info++;
                        if(j+k <= n && map[i][j+k] == 1) cnt++; info++;
                    }
                }
                else
                {
                    if(i-s+1 >= 1)
                    {
                        info++;
                        if(map[i-s+1][j] == 1) cnt++;
                        for(int k = 1; k <= num-s; k++)
                        {
                            if(j-k >= 1 && map[i-s+1][j-k] == 1) cnt++; info++;
                            if(j+k <= n && map[i-s+1][j+k] == 1) cnt++; info++;
                        }
                    }
                    if(i+s-1 <= n)
                    {
                        info++;
                        if(map[i+s-1][j] == 1) cnt++;
                        for(int k = 1; k <= num-s; k++)
                        {
                            if(j-k >= 1 && map[i+s-1][j-k] == 1) cnt++; info++;
                            if(j+k <= n && map[i+s-1][j+k] == 1) cnt++; info++;
                        }
                    }
                }
            }

            if(info >= n*n) check = true;
            int val = (m*cnt) - ((num*num) + ((num-1)*(num-1)));
            if(val >= 0) ansMax = max(ansMax, cnt);
        }
    }
};

int main()
{
    int test_case, T;

    setbuf(stdout, NULL);
    scanf("%d\n", &T);

    for(test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d\n", &n, &m);

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d ",&map[i][j]);
            }
        }

        ansMax = 0;
        for(int i = 1; i <= n*2; i++)
        {
            find(i);
        }
        printf("#%d %d\n", test_case, ansMax);
    }
    return  0;
}