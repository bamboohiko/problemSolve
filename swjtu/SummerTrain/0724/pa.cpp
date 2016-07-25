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
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n,x,cou = 1;
        scanf("%d",&n);
        a[0] = -(1e9 + 7);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            int loc = lower_bound(a,a+cou,x) - a;
            a[loc] = x;
            if (loc == cou) cou++;
        }
        printf("Case %d: %d\n",ca,n-(cou-1));
    }
	return 0;
}
