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
const int maxn = 44722;
int prime[maxn + 10],vis[maxn + 10],m;
int cou[maxn + 10];
vector<int> sav;
void init() {
    memset(vis,0,sizeof(vis));
    for (int i = 2;i <= maxn; i++)
        if (!vis[i]) {
            vis[i] = true;
            prime[m++] = i;
            for (int j = i << 1;j <= maxn; j += i) vis[j] = true;
        }
}
int main() {
    int t;
    init();
    scanf("%d",&t);
    while (t--) {
        int n,k;
        memset(cou,0,sizeof(cou));
        sav.clear();
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&k);
            for (int j = 0;j < m; j++) {
                while (!(k%prime[j])) {k /= prime[j]; cou[j]++;}
                if (k == 1) break;
            }
            if (k != 1) sav.push_back(k);
        }
        sort(sav.begin(),sav.end());
        long long s1 = -1,s2 = -1;
        for (int j = 0;j < m; j++) {
            if (cou[j] && s1 == -1) {s1 = prime[j];cou[j]--;}
            if (cou[j] && s2 == -1) {s2 = prime[j];cou[j]--;}
            if (s1 != -1 && s2 != -1) break;
        }
        if (s2 == -1)
            if (s1 == -1) {
                if (sav.size() > 1) s1 = sav[0],s2 = sav[1];
            } else {
                if (sav.size() > 0) s2 = sav[0];
            }
        if (s1 == -1 && s2 == -1) printf("-1\n");
        else printf("%lld\n",s1*s2);
    }
	return 0;
}

