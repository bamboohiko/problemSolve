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
    scanf("%d",&t);
    while (t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        int ans = (n-1)/k+1;
        printf("%d %d\n",ans,n-(ans-1)*k);
    }
	return 0;
}
