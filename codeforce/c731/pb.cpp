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
    int n;
    scanf("%d",&n);
    int res = 0,k;
    bool pass = true;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        if (k >= res) k -= res;
        else {
            pass = false;
            break;
        }
        res = k&1;
    }
    if (res || !pass) puts("NO");
    else puts("YES");
	return 0;
}

