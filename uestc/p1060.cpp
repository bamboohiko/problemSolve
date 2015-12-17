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
struct node{
    int k,next[2];
};
vector<node> a;
int cnt,root;
int newnode() {
    node n;
    n.k = n.next[0] = n.next[1] = 0;
    a.push_back(n);
    //cout << cnt << endl;
    return a.size()-1;
}
void ins(int x) {
    int p = root,k;
    for (int i = 21;i >= 0; i--) {
        k = x&(1 << i)?1:0;

        //cout << k << endl;
        if (!a[p].next[k]) {
            int sav = newnode();
            a[p].next[k] = sav;
            //cout << a[p].next[k] << endl;
        }
        //printf("%d %d %d\n",p,a[p].next[0],a[p].next[1]);
        p = a[p].next[k];
    }
}
int query(int x) {
    int p = root,k,ans = 0;
    for (int i = 21;i >= 0; i--) {
        k = x&(1 << i)?0:1;
        if (!a[p].next[k]) k = 1 - k;
        if (k) ans += (1 << i);
        p = a[p].next[k];
    }
    return ans;
}
int main() {
    int n,m,x,y;
    while (scanf("%d",&n) != EOF) {
        a.clear();cnt = 0;
        root = newnode();
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            ins(x);
        }
        scanf("%d",&m);
        while (m--) {
            scanf("%d%d",&x,&y);
            if (!x) ins(y);
            else printf("%d\n",query(y));
        }
    }
	return 0;
}
