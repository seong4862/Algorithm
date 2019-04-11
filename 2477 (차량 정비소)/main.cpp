//
// Created by 성누리 on 2019-04-11.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,k,a,b;
int ai[10], bi[10], tk[1001];

int main()
{
    int test_case, T;

    setbuf(stdout, NULL);
    scanf("%d\n", &T);

    for(test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d ", &ai[i]);
        }
        scanf("\n");
        for(int i = 1; i <= m; i++)
        {
            scanf("%d ", &bi[i]);
        }
        scanf("\n");
        for(int i = 1; i <= k; i++)
        {
            scanf("%d ", &tk[i]);
        }
        scanf("\n");

        sort(tk+1, tk+a+1);

    }
    return  0;
}
/*
 * <접수 창구>
 * 1. 고객의 번호가 낮은 순
 * 2. 창구 번가 작은 곳
 *
 * <정비 창구>
 * 1. 먼저 기다리를 고객 우선 (창구 번호가 작은 고객)
 * 2. 창구 번호가 작은 곳
 * */