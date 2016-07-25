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
const double eps = 1e-9;
double equ[100][300];
int fri[100];
vector<double> a;
bool vis[10];
int dcmp(double x) {
    if (abs(x) < eps) return 0;
    return x > 0?1:-1;
}
long long dfs() {
    if (!a.size()) return 2;
    int ans = 0,k = a.size();
    for (int i = 0; i < (1 << k); i++) {
        int f = 0;
        for (int j = 0;j < k; j++) {
            f += a[j]*(((i >> j) & 1)?1:-1);
        }
        if (!dcmp(f)) ans++;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        int from,to;
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++)
                equ[i][j] = 0;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&from,&to);
            fri[from]++;fri[to]++;
            equ[from][i] = 1;
            equ[to][i] = 1;
        }
        bool has = true;
        for (int i = 1;i <= n; i++)
            if (fri[i]%2) {
                has = false;
                break;
            }
        if (has) {
        memset(vis,false,sizeof(vis));
        int now = 1;
        for (int cou = 1;cou < n; cou++) {
            int loc = 0,aloc,next;
            vis[now] = true;
            for (int i = 1;i <= m; i++)
                if (dcmp(equ[now][i])) {
                    loc = i;
                    aloc = equ[now][i];
                    break;
                }
            for (int i = loc+1;i <= m; i++) {
                //cout << equ[now][i] << " " << aloc << endl;
                equ[now][i] = -equ[now][i]/aloc;
            }
            for (int i = 1;i <= n; i++)
                if (!vis[i] && dcmp(equ[i][loc])) {
                    next = i;
                    break;
                }
            for (int i = 1;i <= m; i++)
                equ[next][i] += equ[now][i];
            equ[next][loc] = 0;
            now = next;
        }
        a.clear();
        long long ans = 1;
        for (int i = 1;i <= m; i++) {
            //cout << equ[now][i] << " ";
            if (dcmp(equ[now][i])) a.push_back(equ[now][i]);
        }
        //cout << endl;
        printf("%lld\n",dfs());
        } else {
            printf("0\n");
        }
    }
	return 0;
}
