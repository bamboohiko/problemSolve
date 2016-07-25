#include<cstdio>
using namespace std;
const int M = 1000000007;
const int MAX = 10000000;
int ans[10000010];
int main()
{int n;
long long mul,sav;
    sav = 1;mul = 1;
    for (int i = 1;i <= MAX; i++)
        {mul = mul*i%M;
        sav = mul*sav%M;
        ans[i] = sav;
        }
    while (scanf("%d",&n) != EOF)
        printf("%d\n",ans[n]);
    return 0;
}
