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
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int main() {
    double dl,dr,dp = 1;
    LL l,r,k,p = 1;
    cin >> l >> r >> k;
    dl = l;dr = r;
    while (p < l && dp < dl + eps) {dp *= k;p *= k;}
    bool fir = true;
    while (p <= r && dp <= dr + eps) {
        if (fir) {
            cout << p;
            fir = false;
        } else cout << " " << p;
        dp *= k;p *= k;
    }
    if (fir) puts("-1");
    else puts("");
    return 0;
}
