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
char st[500100];
int x[500100],y[500100];
int main() {
    int n,a,b,t;
    scanf("%d%d%d%d%*c",&n,&a,&b,&t);
    gets(st);
    x[0] = y[0] = 1 + ((st[0] == 'w')?b:0);
    for (int i = 1; i < n; i++) {
        x[i] = x[i-1]+a+1;
        if (st[i] == 'w') x[i] += b;
    }
    for (int i = n-1; i > 0; i--) {
        y[n-i] = y[n-i-1]+a+1;
        if (st[i] == 'w') y[n-i] += b;
    }
    //for (int i = 0;i < n; i++) cout << x[i] << " ";cout << endl;
    //for (int i = 0;i < n; i++) cout << y[i] << " ";cout << endl;
    int ans;
    if (t < x[0]) ans = 0;
    else {
        ans = max(upper_bound(x,x+n,t)-x,upper_bound(y,y+n,t)-y);
        //cout << ans << endl;
        for (int i = 1; i < n; i++) {
            if (t-x[i]-i*a+x[0] < 0) break;
            int loc = upper_bound(y,y+n-i,t-x[i]-i*a+x[0]) - y;
            //cout << i << " " << loc << endl;
            ans = max(ans,loc + i);
        }
        for (int i = n-1; i > 0; i--) {
            if (t-y[n-i]-(n-i)*a+y[0] < 0) break;
            int loc = upper_bound(x,x+i,t-y[n-i]-(n-i)*a+y[0]) - x;
            //cout << i << " " << loc << endl;
            ans = max(ans,loc + n-i);
        }
    }
    printf("%d\n",ans);
    return 0;
}

