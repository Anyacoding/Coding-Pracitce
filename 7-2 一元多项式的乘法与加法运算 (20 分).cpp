

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, m, i, j,k=0,h=0;
    int xishu1[4000] = { 0 }, xishu2[4000] = { 0 }, zhishu1[4000] = { 0 }, zhishu2[4000] = { 0 };
    int a[4000] = {0};
    int flag = 1;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> xishu1[i] >> zhishu1[i];
    }
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> xishu2[i] >> zhishu2[i];
    }
    
    /*乘法部分实现*/
    for (j = 1; j <= m; j++)
        for (i = 1; i <= n; i++)
        {
            a[zhishu1[i] + zhishu2[j]] += xishu1[i] * xishu2[j]; 
        }
    for (i = zhishu1[1] + zhishu2[1]; i >= 0; i--)
    {
        if (a[i])
        {
            if (flag)
            {
                printf("%d %d", a[i], i);
                flag = 0;
            }
            else
                printf(" %d %d", a[i], i);
        }
    }
    if (flag) printf("0 0");
    printf("\n");
    /*加法部分实现*/
    i = 1;
    j = 1;
    flag = 1;
    while (i<=n||j<=m)
    {
        if (zhishu1[i] > zhishu2[j])
        {
            if (flag)
            {
                printf("%d %d", xishu1[i], zhishu1[i]);
                flag = 0;
            }
            else
                printf(" %d %d", xishu1[i], zhishu1[i]);
            i++;
        }
        else if (zhishu1[i] < zhishu2[j])
        {
            if (flag)
            {
                printf("%d %d", xishu2[j], zhishu2[j]);
                flag = 0;
            }
            else
                printf(" %d %d", xishu2[j], zhishu2[j]);
            j++;
        }
        else
        {
            if (xishu2[j] + xishu1[i])
            {
                if (flag)
                {
                    printf("%d %d", xishu2[j] + xishu1[i], zhishu2[j]);
                    flag = 0;
                }
                else
                    printf(" %d %d", xishu2[j] + xishu1[i], zhishu2[j]);
            }
            
            j++;
            i++;
        }
        
    }
    if (flag) printf("0 0");
    return 0;
}

