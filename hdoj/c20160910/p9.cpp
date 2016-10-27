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
    LL n,k;
    while (cin >> n >> k) {
        LL c = n/2;
        if (c > 1e6) puts("F");
        else {
        LL ans = (c+1)*c;
        if (n%2 == 0) ans -= c;
        //cout << ans << endl;
        if (ans <= k) puts("T");
        else puts("F");
        }
    }
	return 0;
}
