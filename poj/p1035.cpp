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
char dic[10010][20];
char st[20];
int len[10010],f[20][20],ans[10010];
int main() {
    int n = 0;
    while (true) {
        scanf("%s",dic[++n]+1);
        len[n] = strlen(dic[n]+1);
        if (dic[n][1] == '#') break;
    }
    while (true) {
        scanf("%s",st+1);
        if (st[1] == '#') break;
        bool ok = false;
        int l = strlen(st+1),m = 0;
        for (int k = 1;k < n; k++) {
            if (strcmp(st+1,dic[k]+1) == 0) {
                ok = true;
                break;
            } else if (abs(l - len[k]) <= 1) {
                if (len[k] == l) {
                    int cou = 0;
                    for (int i = 1;i <= len[k]; i++)
                        if (dic[k][i] == st[i]) cou++;
                    if (cou == len[k]-1) ans[++m] = k;
                } else {
                //cout << len[k] << " " << l << endl;
                for (int i = 1;i <= len[k]; i++)
                    for (int j = 1;j <= l; j++) {
                        f[i][j] = max(f[i-1][j],f[i][j-1]);
                        if (dic[k][i] == st[j]) f[i][j] = f[i-1][j-1]+1;
                    }
                //cout << f[len[k]][l] << endl;
                if (f[len[k]][l] == (len[k] + l - 1)/2) ans[++m] = k;
                }
            }
        }
        if (ok) printf("%s is correct\n",st+1);
        else {
            printf("%s:",st+1);
            for (int i = 1;i <= m; i++) printf(" %s",dic[ans[i]]+1);
            printf("\n");
        }
    }
	return 0;
}

