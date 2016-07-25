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
int c[1010],r[1010];
int main() {
    int n,m,cou = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n; i++) scanf("%s",st+i*m);
    for (int i = 0;i < n; i++)
        for (int j = 0;j < m; j++)
            if (st[i*m+j] == '*') {
                r[i]++;c[j]++;cou++;
            }
    bool pass = false;
    for (int i = 0;i < n && !pass; i++)
        for (int j = 0;j < m && !pass; j++)
            if (r[i] + c[j] - ((st[i*m+j] == '*')?1:0) == cou) {
                pass = true;
                printf("YES\n%d %d\n",i+1,j+1);
            }
    if (!pass) puts("NO");
	return 0;
}
