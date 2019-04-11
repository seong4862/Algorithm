//
// Created by 성누리 on 2019-04-10.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int n, ansMax, ansMin;
int way[5], num[15];

void copy(int(*arr), int(*arr2)) {
    for (int i = 1; i <= 4; i++) {
            arr[i] = arr2[i];
    }
}

void dfs(int cnt, int val, int *way) {

    int a[5];

    if(cnt == n+1)
    {
        ansMax = max(ansMax, val);
        ansMin = min(ansMin, val);
        return;
    }

    for(int i = 1; i <= 4; i++)
    {
        if(way[i] > 0)
        {
            int v;

            if(i == 1) v = val + num[cnt];
            else if(i == 2) v = val - num[cnt];
            else if(i == 3) v = val * num[cnt];
            else if(i == 4) v = val / num[cnt];

            copy(a, way);
            way[i]--;
            dfs(cnt+1, v, way);
            copy(way, a);
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
        scanf("%d\n", &n);
        for(int i = 1; i <= 4; i++)
        {
            scanf("%d ", &way[i]);
        }
        scanf("\n");
        for(int i = 1; i <= n; i++)
        {
            scanf("%d ", &num[i]);
        }
        scanf("\n");

        ansMax = -999999999;
        ansMin = 999999999;
        dfs(2, num[1], way);

        printf("#%d %d\n", test_case, ansMax-ansMin);
    }
    return 0;
}