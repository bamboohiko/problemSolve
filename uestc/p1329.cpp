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
struct point{
    int x,y,val;
    bool operator <(const point& rhs) const {
        return val > rhs.val;
    }
};
priority_queue<point> Q;
int a[100100],b[100100];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1;i <= n; i++) scanf("%d",&b[i]);
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    for (int i = 1;i <= n; i++)
        Q.push((point){i,1,a[i]+b[1]});
    for (int i = 1;i <= n; i++) {
        point p = Q.top();Q.pop();
        printf("%d\n",p.val);
        Q.push((point){p.x,p.y+1,a[p.x]+b[p.y+1]});
    }
	return 0;
}
