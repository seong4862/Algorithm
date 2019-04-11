//
// Created by 성누리 on 2019-04-10.
//

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct sMoney{
    int day;
    int one;
    int three;
    int year;
} money;

int data[15];
int res=9999999;
priority_queue<int, vector<int>, greater<int> > pq;

void dfs(int num, int value)
{
    //경우에 따라 값 정하기
    for(int i = num+1; i <= 12; i++)
    {
        if(data[i] > 0)
        {
            //1일
            dfs(i, value + money.day*data[i]);
            //1달
            dfs(i, value + money.one);
            //3달
            dfs(i+2, value + money.three);
            return;
        }
    }

    pq.push(value);
}

int main()
{
    int test_case, T;

    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for(test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d %d %d\n", &money.day, &money.one, &money.three, &money.year);
        for(int i = 1; i <= 12; i++)
        {
            scanf("%d ", &data[i]);
        }
        scanf("\n");

        priority_queue<int, vector<int>, greater<int> > empty;
        swap(pq,empty);
        dfs(0, 0);
        if(pq.top() < money.year) printf("#%d %d\n", test_case, pq.top());
        else printf("#%d %d\n", test_case, money.year);
    }
    return 0;
}