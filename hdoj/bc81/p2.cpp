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
char st[1000100];
int cou[30];
int main() {
    int t,k;
    scanf("%d",&t);
    while (t--) {
        memset(cou,0,sizeof(cou));
        scanf("%s",st);
        scanf("%d",&k);
        int len = strlen(st),sum = 0,r = 0;
        LL ans = 0;
        for (int i = 0;i < len; i++) {
            while (r < len && sum < k) {
                if (!cou[st[r] - 'a']) sum++;
                cou[st[r++] - 'a']++;
            }
            if (sum >= k) ans += len - r+1;
            cou[st[i] - 'a']--;
            if (!cou[st[i] - 'a']) sum--;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
