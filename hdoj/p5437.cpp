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
const int maxn = 150000 + 100;
struct per {
    char nam[210];int v,ord;
    bool operator <(const per& rhs) const{
        if (v != rhs.v) return v < rhs.v;
        else return ord > rhs.ord;
    }
};
struct dor {
    int t,p;
};
per p[maxn];
priority_queue<per> a;
dor d[maxn];
int loc[110];
bool cmp(dor a,dor b) {
    return a.t < b.t;
}
int main() {
    int t;
    int k,m,q;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&k,&m,&q);
        for (int i = 1;i <= k; i++) {
            scanf("%s%d",p[i].nam,&p[i].v);p[i].ord = i;
        }
        for (int i = 0;i < m; i++) scanf("%d%d",&d[i].t,&d[i].p);
        sort(d,d+m,cmp);
        for (int i = 0;i < q; i++) scanf("%d",&loc[i]);
        sort(loc,loc+q);
        int sumin = 0,sumout = 0,fr = 0;per ans;
        for (int i = 0;i < m; i++) {
            for (int j = sumin+1; j <= d[i].t; j++) a.push(p[j]);
            sumin = d[i].t;
            for (int j = 1;j <= d[i].p; j++) {
                ans = a.top();a.pop();
                //cout << sumout + j << " " << loc[fr] << endl;
                if (sumout + j == loc[fr]) {
                    if (fr == 0) printf("%s",ans.nam);
                    else printf(" %s",ans.nam);
                    fr++;
                }
            }
            sumout += d[i].p;
            //cout << sumin << " " << sumout << endl;
        }
        printf("\n");
    }
	return 0;
}

