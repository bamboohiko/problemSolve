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
int n,m,a[30][30];
int vis[30],d[30],q[30];
int tpsort() {
    queue<int> Q;
    for (int i = 0;i < n; i++)
        if (d[i] == 0) Q.push(i);
    int sz = Q.size();
    if (sz == 0) return -1;
    for (int i = 0;i < n; i++) vis[i] = d[i];
    int cou = 0;
    while (!Q.empty()) {
        int s = Q.front();Q.pop();
        for (int i = 0;i < n; i++)
            if (a[s][i]) {
                if (--vis[i] == 0) {
                    Q.push(i);
                    sz = max(sz,(int)Q.size());
                }
            }
        q[++cou] = s;
    }
    if (cou == n) return ((sz == 1)?1:0);
    else return -1;
}
int main() {
    while (scanf("%d%d%*c",&n,&m) != EOF) {
        if (n == 0 && m == 0) break;
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        int ans = 0;char from,to;
        for (int i = 1;i <= m; i++) {
            scanf("%c%*c%c%*c",&from,&to);
            a[from - 'A'][to - 'A'] = 1;d[to - 'A']++;
            if (ans == 0) ans = tpsort()*i;
        }
        if (ans > 0) {
            printf("Sorted sequence determined after %d relations: ",ans);
            for (int i = 1;i <= n; i++) printf("%c",q[i] + 'A');
            printf(".\n");
        } else if (ans < 0) {
            printf("Inconsistency found after %d relations.\n",-ans);
        } else {
            puts("Sorted sequence cannot be determined.");
        }
    }
	return 0;
}

