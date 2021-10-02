
#include <iostream>
#include <cstdio>
using namespace std;
const int maxsize = 100;
struct node
{
    char Data=' ';
    int left;
    int right;
}T1[maxsize],T2[maxsize];
typedef struct node Tree;

int BuildTree(Tree T[]);

bool istonggou(int r1,int r2);

int main()
{
    int r1, r2;
    r1 = BuildTree(T1);
    r2 = BuildTree(T2);
    if (istonggou(r1, r2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

int BuildTree(Tree T[])
{
    int n, i, j, check[maxsize] = {0},root;
    char cl, cr;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%c %c %c", &T[i].Data, &cl, &cr);
        if (cl != '-')
        {
            T[i].left = cl - '0';
            check[T[i].left] = 1;
        }
        if (cr != '-')
        {
            T[i].right = cr - '0';
            check[T[i].right] = 1;
        }
    }
    for (i = 0; i < n; i++)
        if (check[i]==0)
            break;
    root = i;
    return root;
}

bool istonggou(int r1, int r2)
{
    //两棵都是空树
    if (T1[r1].Data == ' ' && T2[r2].Data == ' ')
        return true;
    //一空一不空
    if ((T1[r1].Data == ' ' && T2[r2].Data != ' ') || (T1[r1].Data != ' ' && T2[r2].Data == ' '))
        return false;
    //都不空但是值不相等
    if ((T1[r1].Data != ' ' && T2[r2].Data != ' ') && (T1[r1].Data != T2[r2].Data))
        return false;
    //剩下的情况就是根节点都不空且相等，但此时仍无法判断，故向下延深
    //左儿子都不空且相等
    if ((T1[T1[r1].left].Data != ' ' && T2[T2[r2].left].Data != ' ') && (T1[T1[r1].left].Data == T2[T2[r2].left].Data))
        return istonggou(T1[r1].right, T2[r2].right);
    else
        return istonggou(T1[r1].right, T2[r2].left) && istonggou(T1[r1].left, T2[r2].right);
}