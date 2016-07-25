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
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
const int inf = 1e7 + 7;
int f[23][23][23][23][2],a[30],b[30];
/*
int dfs(int al,int ar,int bl,int br,int p) {
    if (al > ar && bl > br) return 0;
    if (vis[al][ar][bl][br][p]) return f[al][ar][bl][br][p];
    if (p == 0) {

    } else {
        f[al][ar][bl][br][p] = inf;
        if (al <= ar) f[al][ar][bl][br][p] = min(f[al][ar][bl][br][p],min(dfs(al+1,ar,bl,br,0),dfs(al,ar-1,bl,br,0)));
        if (bl <= br) f[al][ar][bl][br][p] = min(f[al][ar][bl][br][p],min(dfs(al,ar,bl+1,br,0),dfs(al,ar,bl,br-1,0)));
    }
    //printf("%d %d %d %d %d %d\n",al,ar,bl,br,p,f[al][ar][bl][br][p]);
    vis[al][ar][bl][br][p] = true;
    return  f[al][ar][bl][br][p];
}
*/
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1;i <= n; i++) scanf("%d",&b[i]);
        for (int alen = -1;alen < n;alen++)
            for (int al = 1;al + alen <= n; al++)
                for (int blen = -1;blen < n;blen++)
                    for (int bl = 1;bl + blen <= n; bl++) {
                        int ar = al + alen,br = bl + blen;
                        //printf("%d %d %d %d\n",al,ar,bl,br);
                        f[al][ar][bl][br][0] = 0;
                        if (al <= ar) f[al][ar][bl][br][0] = max(f[al][ar][bl][br][0],max(f[al+1][ar][bl][br][1]+a[al],f[al][ar-1][bl][br][1]+a[ar]));
                        if (bl <= br) f[al][ar][bl][br][0] = max(f[al][ar][bl][br][0],max(f[al][ar][bl+1][br][1]+b[bl],f[al][ar][bl][br-1][1]+b[br]));
                        f[al][ar][bl][br][1] = inf;
                        if (al <= ar) f[al][ar][bl][br][1] = min(f[al][ar][bl][br][1],min(f[al+1][ar][bl][br][0],f[al][ar-1][bl][br][0]));
                        if (bl <= br) f[al][ar][bl][br][1] = min(f[al][ar][bl][br][1],min(f[al][ar][bl+1][br][0],f[al][ar][bl][br-1][0]));
                    }
        printf("%d\n",f[1][n][1][n][0]);
    }
	return 0;
}

