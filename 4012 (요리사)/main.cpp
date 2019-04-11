#include <cstdio>
#include <vector>
using namespace std;
int n,sum=0, unSum=0,minn=99999;
int a[20][20],check[20];
vector <int> visit, unvisit;

void dfs(int num, int cnt)
{
    if(cnt == n/2)
    {
        sum = 0;
        unSum = 0;
        unvisit.clear();
        for(int i = 1; i <= n; i++)
        {
            if(check[i] == 0) unvisit.push_back(i);
        }

        for(int i = 0; i < n/2; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                if(i != j)
                {
                    sum += a[visit[i]][visit[j]];
                    unSum += a[unvisit[i]][unvisit[j]];
                }
            }
        }
        int minus = sum-unSum;
        if(minus < 0) minus *= (-1);
        if(minn > minus) minn = minus;

        return;
    }
    else
    {
        for(int i=num+1; i<=n; i++)
        {
            if(check[i] == 0) {
                check[i] = 1;
                visit.push_back(i);
                dfs(i, cnt + 1);
                visit.pop_back();
                check[i] = 0;
            }
        }
    }
}
int main(void)
{
    int test_case;
    int T;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d\n", &n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d ",&a[i][j]);
            }
            scanf("\n");
        }

        minn = 99999;

        check[1] = 1;
        visit.push_back(1);
        dfs(1, 1);

        printf("#%d %d\n", test_case, minn);
        visit.clear();
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}