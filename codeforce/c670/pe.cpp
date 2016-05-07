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
int fr[500100],la[500100],st[500100];
int main() {
    //std::ios::sync_with_stdio(false);
    int n,m,p;char ch;
    scanf("%d%d%d%*c",&n,&m,&p);
    la[0] = 1;fr[n+1] = n;
    for (int i = 1;i <= n; i++) {
        ch = getchar();
        if (ch == '(') st[i] = 1;
        else st[i] = -1;
        fr[i] = i-1;la[i] = i+1;
    }
    getchar();
    for (int i = 1;i <= m; i++) {
        ch = getchar();
        if (ch == 'L') p = fr[p];
        if (ch == 'R') p = la[p];
        if (ch == 'D') {
            int cnt = 0,add,ed = p;
            if (st[p] == 1) {
                for (ed = p;ed < n+1;ed = la[ed]) {
                    cnt += st[ed];
                    if (cnt == 0) break;
                }
                swap(p,ed);
            } else {
                for (ed = p;ed > 0;ed = fr[ed]) {
                    cnt += st[ed];
                    if (cnt == 0) break;
                }
            }
            p = la[p];ed = fr[ed];
            fr[p] = ed;la[ed] = p;
            if (p == n+1) p = fr[p];

        }
    }
    for (int i = la[0];i != n+1; i = la[i])
        if (st[i] == 1) putchar('(');
        else putchar(')');
    printf("\n");
	return 0;
}

