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
int f[110],g[110][110];
int main() {
    string a,b;
    while (cin >> a >> b) {
        int n = a.size();
        a = " " + a;b = " " + b;
        for (int i = 1;i <= n; i++)
            for (int j = i;j <= n; j++) {
                g[i][j] = j-i+1;
            }
        for (int len = 0;len < n; len++)
            for (int i = 1;i+len <= n; i++) {
                int j = i + len,loc;
                for (loc = j;loc >= i && b[loc-1] == b[j]; loc--) ;
                g[i][j] = min(g[i][j],g[i][loc-1] + 1);
                for (int k = loc-1;k >= i;k--)
                    if (b[k] == b[j])
                        g[i][j] = min(g[i][j],g[i][k] + g[k+1][loc-1]);
                //printf("%d %d %d\n",i,j,f[i][j]);
            }
        for (int i = 1;i <= n; i++) {
            f[i] = g[1][i];
            if (a[i] == b[i]) f[i] = f[i-1];
            else {
                for (int j = 0;j < i; j++)
                    f[i] = min(f[i],f[j]+g[j+1][i]);
            }
        }
        printf("%d\n",f[n]);
    }
	return 0;
}

