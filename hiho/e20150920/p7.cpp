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
const int seven_ans = 56;
struct point {
    int t,step,la;
};
bool vis[20001000];
int bit(int k) {
    return (k-1)*3;
}
bool pass(int nloc,int nk,int t) {
    for (int k = 1;k < nk; k++) {
        int loc = (t >> bit(k))%8;
        if (nloc == loc) return false;
    }
    return true;
}
map<int,int> dic;
int a[10],b[10];
point Q[10000000];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(vis,0,sizeof(vis));
        int n,k,ed = 0,ans = -1;
        scanf("%d",&n);
        dic.clear();
        for (int i = 0;i < n; i++) {scanf("%d",&a[i]);b[i] = a[i];}
        sort(a,a+n);
        for (int i = 0;i < n; i++) dic[a[i]] = i+1;
        point p;
        p.t = 0;p.step = 0,p.la = -1;
        for (int i = 0;i < n; i++) {
            k = dic[b[i]];
            p.t += i << bit(k);
            ed += i << bit(i+1);
        }
        printf("%d\n",p.t);
        if (p.t == ed) ans = 0;
        else {
        Q[0] = p;vis[p.t] = true;
        int ps = 0,pd = 1;
        while (ps < pd) {
            point p = Q[ps++];
            //printf("%o %d\n",p.t,p.step);
            int visloc = (1 << n) - 1;
            for (int k = 1;k <= n; k++) {
                int loc = (p.t >> bit(k))%8;
                if (visloc & (1 << loc)) {
                    visloc -= (1 << loc);
                    int nt;
                    if (loc > 0) {
                        nt = p.t - (1 << bit(k));
                        if (!vis[nt] && pass(loc-1,k,nt)) {
                            Q[pd++] = (point){nt,p.step+1,ps-1};vis[nt] = true;
                            if (nt == ed) {ans = p.step+1;goto lambel;}
                        }
                    }
                    if (loc < n-1) {
                        nt = p.t + (1 << bit(k));
                        if (!vis[nt] && pass(loc+1,k,nt)) {
                            Q[pd++] = (point){nt,p.step+1,ps-1};vis[nt] = true;
                            if (nt == ed) {ans = p.step+1;goto lambel;}
                        }
                    }
                }
            }
        }
        }
        lambel:
        printf("%d\n",ans);
    }
	return 0;
}

