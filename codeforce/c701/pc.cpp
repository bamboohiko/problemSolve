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
bool vis[200];
int cou[200];
char st[100100];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",st+1);
    int m = 0;
    for (int i = 1;i <= n; i++)
        if (!vis[st[i]]) {vis[st[i]] = true;m++;}
    int kid = 0,l = 1,ans = n;
    for (int i = 1;i <= n; i++) {
        if (cou[st[i]] == 0) kid++;cou[st[i]]++;
        while (kid > m || cou[st[l]] > 1) {
            if (cou[st[l]] == 1) kid--;cou[st[l]]--;l++;
        }
        if (kid == m) ans = min(ans,i-l+1);
        //cout << l << " " << cou[st[l]] << endl;
    }
    printf("%d\n",ans);
	return 0;
}
