

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,i,j;
    int a[100001] = { 0 };
    int max=0, sum=0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        sum = sum + a[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
    cout << max ;
    return 0;
}

