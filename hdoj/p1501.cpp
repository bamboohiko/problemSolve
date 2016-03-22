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
string a,b,c;
bool f[210][210];
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Data set %d: ",ca);
        cin >> a >> b >> c;
        a = " " + a;
        b = " " + b;
        int n = a.size(),m = b.size();
        memset(f,0,sizeof(f));f[0][0] = true;
        for (int i = 0;i < n; i++)
            for (int j = 0;j < m; j++) {
                if (i > 0 && c[i+j-1] == a[i]) f[i][j] = f[i][j] || f[i-1][j];
                if (j > 0 && c[i+j-1] == b[j]) f[i][j] = f[i][j] || f[i][j-1];
            }
        if (f[n-1][m-1]) puts("yes");
        else puts("no");
    }
	return 0;
}

