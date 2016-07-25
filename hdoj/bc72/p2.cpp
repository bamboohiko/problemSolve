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
struct node{
    int k,next[2];
    int from,to;
};
vector<node> a;
int root;
int f[300100];
int newnode() {
    node n;
    n.k = n.next[0] = n.next[1] = 0;
    n.from = n.to = 0;
    a.push_back(n);
    //cout << cnt << endl;
    return a.size()-1;
}
void ins(int from,int to,int x) {
    int p = root,k;
    for (int i = 30;i >= 0; i--) {
        k = x&(1 << i)?1:0;
        if (!a[p].next[k]) {
            int sav = newnode();
            a[p].next[k] = sav;
        }
        p = a[p].next[k];
    }
    a[p].from = from;a[p].to = to;
}
int query(int x) {
    int p = root,k;
    for (int i = 30;i >= 0; i--) {
        k = x&(1 << i)?0:1;
        if (!a[p].next[k]) k = 1 - k;
        if (k) ans += (1 << i);
        p = a[p].next[k];
    }
    return ans;
}
int main() {
    int t,n,m;
    int from,to,x;
    for (int i = 1;i <= m; i++) {
        scanf("%d%d%d",&from,&to,&x);
        ins(from,to,x);
    }
    for (int i = 1;i <= n; i++) f[i] = i;
    ans = (1 << 31)-1;
    for (int i = 2;i <= n; i++) {
        ans = query(ans);
        if (!ans) break;
    }
    printf("%d\n",ans);
	return 0;
}

