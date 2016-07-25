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
int main() {
    int t,n,ans;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        if (n == 1) ans = 0;
        else ans = n-2;
        printf("%d\n",ans);
    }
	return 0;
}
