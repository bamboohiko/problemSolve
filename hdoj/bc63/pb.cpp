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
int a[110],f[110][110];
int main() {
    int n;
    //map<int,int> rec;
    while (scanf("%d",&n) != EOF) {
        int len;
        scanf("%d",&len);
        for (int i = 1;i <= n; i++)
            scanf("%d",&a[i]);
        a[0] = -1;a[n+1] = INF;
        memset(f,0,sizeof(f));
        f[0][0] = 1;
        for (int i = 1;i <= n+1; i++)
            for (int j = 1;j <= i && j <= len+1; j++) {
                /*
                rec.clear();
                for (int k = 0;k < i; k++)
                    if (a[k] < a[i]) {
                        if (!rec.count(a[k])) rec[a[k]] = f[k][j-1];
                        else rec[a[k]] = max(rec[a[k]],f[k][j-1]);
                    }
                for (int k = 0;k < i; k++)
                    if (rec.count(a[k])) {
                        f[i][j] += rec[a[k]];
                        rec[a[k]] = 0;
                    }
                */
                for (int k = 0;k < i; k++)
                    if (a[k] < a[i]) f[i][j] += f[k][j-1];
            }
        printf("%d\n",f[n+1][len+1]);
    }
	return 0;
}
