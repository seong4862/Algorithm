#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,c,res;
int a[11][11], dp[11][11];

//최대값 계산하기
int calc(vector<int> &v, int n, int sum, int val)
{
    if(sum > c) return 0;
    if(n == v.size()) return val;

    return max(calc(v, n+1, sum+v[n], val + v[n]*v[n]), calc(v, n+1, sum, val));
}

//최대값 찾기
int getMaxPrice(int x, int y)
{
    vector<int> v;
    for(int i = 0; i < m; i++)
    {
        v.push_back(a[x][y+i]);
    }

    return calc(v, 0, 0, 0);
}

int dfs(int x, int y)
{
    int ans = 0;

    //같은 라인
    for(int i = y+m; i < n-m+1; i++)
    {
        ans = max(ans, dp[x][i]);
    }
    //다른 라인
    for(int i = x+1; i < n; i++)
    {
        for(int j = 0; j < n-m+1; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
int main()
{
    int test_case, T;

    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for(test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d\n", &n, &m, &c);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d ",&a[i][j]);
                dp[i][j] = 0;
            }
            scanf("\n");
        }


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n-m+1; j++)
            {
                dp[i][j] = getMaxPrice(i, j);
            }
        }

        res=0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n-m+1; j++)
            {
                res = max(res, dfs(i, j) + dp[i][j]);
            }
        }

        printf("#%d %d\n", test_case, res);
    }
    return 0;
}
