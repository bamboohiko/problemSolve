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
const int maxw = 1e5;
struct point {
    int x,y;
    bool operator <(point rhs) {
        if (rhs.x <= x && rhs.y <= y) return false;
        return true;
    }
};
point p[100100];
vector<int> a[200100];
int ans[100100],loc[200100];
bool cmp(int a,int b) {
    return (p[a] < p[b]);
}
int main() {
    int n,w;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d%d",&p[i].x,&p[i].y);
        a[p[i].y-p[i].x+maxw].push_back(i);
    }
    for (int i = 0;i <= maxw << 1; i++) {
        if (a[i].size() > 0) sort(a[i].begin(),a[i].end(),cmp);
    }
    bool ok = true;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&w);
        //printf("%d %d\n",loc[w+maxw], a[w+maxw].size());
        if (!ok) continue;
        if (loc[w+maxw] == a[w+maxw].size()) {
            ok = false;
        } else {
            ans[i] = a[w+maxw][loc[w+maxw]++];
            //printf("%d %d\n",p[ans[i]].x,p[ans[i]].y);
            if (i > 1 && !(p[ans[i-1]] < p[ans[i]])) ok = false;
        }
        //cout <<ok << endl;
    }
    if (ok) {
        printf("YES\n");
        for (int i = 1;i <= n; i++) {
            printf("%d %d\n",p[ans[i]].x,p[ans[i]].y);
        }
    } else {
        printf("NO\n");
    }
	return 0;
}
