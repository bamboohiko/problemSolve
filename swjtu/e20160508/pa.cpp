#include <cstdio>
using namespace std;
const int maxn = 1e5 +10;
double a[maxn];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    double p, d;
    int n;
    while(scanf("%lf %lf %d", &p, &d, &n) != EOF)
    {
        int i;
        double minn = 1e9 + 10;
        int index;

        for(i = 1; i <= n ; i++)
        {
            scanf("%lf", &a[i]);
            double money = p * ( 1 - a[i] );
            if( money < minn )
            {
               minn  = money;
               index = i;
            }
        }

        double app = p - d;

        if( app <= minn )
        {
            printf("APP %.2lf\n",app );
        }

        else
        {
            printf("%d %.2lf\n", index, minn);
        }

    }
    return 0;
}
