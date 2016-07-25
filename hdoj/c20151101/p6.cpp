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
const int maxn = 1e5 + 10;
int f[maxn],a[maxn];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++)
            scanf("%d",&a[i]);
        int s1 = 1,s2 = 1;
        memset(f,0,sizeof(f));f[0] = a[1];
        for (int i = 2;i <= n; i++) {
            int loc = upper_bound(f,f+s1,a[i]) - f;
            f[loc] = a[i];
            s1 = max(s1,loc+1);
        }
        memset(f,0,sizeof(f));f[0] = a[n];
        for (int i = n-1;i >= 1; i--) {
            int loc = upper_bound(f,f+s2,a[i]) - f;
            f[loc] = a[i];
            s2 = max(s2,loc+1);
        }
        //cout << s1 << " " <<  s2 << endl;
        if (s1 >= n-1 || s2 >= n-1) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}

