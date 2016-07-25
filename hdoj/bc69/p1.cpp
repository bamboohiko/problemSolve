#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int main() {
    int t;
    int a,b,c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&a,&b,&c);
        int ans = -1;
        if ((c&1) == 0)  {
            c >>= 1;
            for (int i = a;i <= c; i += a) {
                if ((c - i)%b == 0)
                    if (ans == -1 || i/a + (c-i)/b < ans/a + (c-i)/b)
                        ans = i;
            }
        }
        if (ans == -1) puts("Impossible");
        else printf("%d %d\n",2*ans/a,2*(c-ans)/b);
    }
	return 0;
}

