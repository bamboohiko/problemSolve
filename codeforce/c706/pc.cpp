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
LL c[100100];
string la1,la2,st1,st2;
LL cmp(LL a,LL b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return min(a,b);
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++)
        scanf("%I64d",&c[i]);
    LL ans1 = 0,ans2 = 0;
    la1 = la2 = "";
    for (int i = 1;i <= n; i++) {
        cin >> st1;st2 = st1;
        reverse(st2.begin(),st2.end());
        LL now1 = -1,now2 = -1;
        if (ans1 >= 0) {
            if (st1 >= la1) now1 = cmp(now1,ans1);
            if (st2 >= la1) now2 = cmp(now2,ans1+c[i]);
        }
        if (ans2 >= 0) {
            if (st1 >= la2) now1 = cmp(now1,ans2);
            if (st2 >= la2) now2 = cmp(now2,ans2+c[i]);
        }
        la1 = st1;la2 = st2;
        ans1 = now1;ans2 = now2;
        //cout << la1 << ":" << ans1;
        //cout << la2 << ":" << ans2 << endl;
    }
    printf("%I64d\n",cmp(ans1,ans2));
	return 0;
}
