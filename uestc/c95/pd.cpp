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
const int maxn = 1e5 + 100;
struct point{
    int x,y,num;
    point(int _x = 0,int _y = 0,int _z = 0) {
        x = _x;y = _y;num = _z;
    }
    bool operator <(const point &rhs) const {
        return num > rhs.num;
    }
};
int a[maxn],b[maxn];
priority_queue<point> Q;
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n; i++) scanf("%d",&a[i]);
    for (int i = 0;i < n; i++) scanf("%d",&b[i]);
    sort(a,a+n);sort(b,b+n);
    for (int i = 0;i < n; i++) Q.push(point(i,0,a[i]+b[0]));
    for (int i = 1;i <= n; i++) {
        point p = Q.top();Q.pop();
        printf("%d\n",p.num);
        if (p.y < n-1) Q.push(point(p.x,p.y+1,a[p.x]+b[p.y+1]));
    }
	return 0;
}

