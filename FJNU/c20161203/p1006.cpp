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
    int x,y;
    point(int x = 0,int y = 0):x(x),y(y) {};
    point operator +(const point &rhs) {
        return point(x+rhs.x,y+rhs.y);
    }
    point operator -(const point &rhs) {
        return point(x-rhs.x,y-rhs.y);
    }
};
int gcd(int a,int b) {
    if (a == 0 || b == 0) return max(a+b,1);
    while (b) {
        int t = a;a = b;b = t%b;
    }
    return a;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        point p,p1,sum;
        scanf("%d%d",&p.x,&p.y);
        int n;
        scanf("%d",&n);
        for (int i = 0;i < n; i++) {
            scanf("%d%d",&p1.x,&p1.y);
            sum = sum + (p1 - p);
        }
        int g = gcd(abs(sum.x),abs(sum.y));
        printf("%d %d\n",sum.x/g,sum.y/g);
    }
	return 0;
}
