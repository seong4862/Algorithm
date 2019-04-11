/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int 변수 1개 입력받는 예제
// scanf("%f %f", &b, &c);               // float 변수 2개 입력받는 예제
// scanf("%lf %lf %lf", &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf("%c", &g);                      // char 변수 1개 입력받는 예제
// scanf("%s", &var);                    // 문자열 1개 입력받는 예제
// scanf("%lld", &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int 변수 1개 출력하는 예제
// printf("%f %f", b, c);                // float 변수 2개 출력하는 예제
// printf("%lf %lf %lf", d, e, f);       // double 변수 3개 출력하는 예제
// printf("%c", g);                      // char 변수 1개 출력하는 예제
// printf("%s", var);                    // 문자열 1개 출력하는 예제
// printf("%lld", AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct sMove{
    int a;
    int b;
} movee[101];

struct sData{
    int x;
    int y;
    int d;
    int p;
} data[10];

struct sCheck{
    int check;
    int num;
};

bool compare(sCheck first, sCheck second)
{
    return first.check > second.check;
}

int n,m;
int sum = 0;
int mX[6]={0,-1,0,1,0}, mY[6] = {0,0,1,0,-1};
int main(void)
{
    int test_case;
    int T;

    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d %d\n", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d " ,&movee[i].a);
        }
        scanf("\n");
        for(int i = 1; i <= n; i++)
        {
            scanf("%d ", &movee[i].b);
        }
        scanf("\n");
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d %d\n", &data[i].y, &data[i].x, &data[i].d, &data[i].p);
        }

        //처리
        sum=0;
        int aX = 1, aY = 1, bX = 10, bY = 10;
        for(int i = 0; i <= n; i++)
        {
            aX += mX[movee[i].a];
            aY += mY[movee[i].a];
            bX += mX[movee[i].b];
            bY += mY[movee[i].b];
            int cA=0, cB=0;
            sCheck checkA[10], checkB[10];
            for(int j = 1; j <= m; j++)
            {
                int xx = (data[j].x - aX);
                int yy = (data[j].y - aY);
                if(xx < 0) xx *= (-1);
                if(yy < 0) yy *= (-1);
                int valueA = xx+yy;

                if(valueA <= data[j].d)
                {
                    checkA[cA].num = j;
                    checkA[cA++].check = data[j].p;
                }
            }

            for(int j = 1; j <= m; j++)
            {
                int xx = data[j].x - bX;
                int yy = (data[j].y - bY);
                if(xx < 0) xx *= (-1);
                if(yy < 0) yy *= (-1);
                int valueB = xx+yy;

                if(valueB <= data[j].d)
                {
                    checkB[cB].num = j;
                    checkB[cB++].check = data[j].p;
                }
            }
            sort(checkA, checkA + cA, compare);
            sort(checkB, checkB + cB, compare);

            if(checkA[0].num != checkB[0].num)
            {
                sum += checkA[0].check + checkB[0].check;
            }
            else if(checkA[1].num == checkB[1].num)
            {
                sum += checkA[0].check + checkB[1].check;
            }
            else
            {
                if(checkA[0].check + checkB[1].check > checkA[1].check + checkB[0].check)
                {
                    sum += checkA[0].check + checkB[1].check;
                }
                else sum += checkB[0].check + checkA[1].check;
            }

            memset(checkA, 0, sizeof(checkA) );
            memset(checkB, 0, sizeof(checkB) );
        }
        printf("#%d %d\n", test_case, sum);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}