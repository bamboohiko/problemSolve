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
struct node {
    int val,s[2];
};
vector<node> V;
int newnode() {
    node n;
    n.val = n.s[0] = n.s[1] = 0;
    V.push_back(n);
    return (int)(V.size()-1);
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) {
        scanf("%d",k);
        ins(k);
    }
    for (int i = 1;i <= m; i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1,greater<int>);
    int u = 0,c = 0;
    for (int i = m;i >= 1; i--) {
        int sav = _find(i,a[i]);
        u += sav;c++;
    }
    printf("%d %d\n",c,u);
    for (int i = 1;i < n; i++)
	return 0;
}
