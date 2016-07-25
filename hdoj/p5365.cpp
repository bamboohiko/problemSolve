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
const double eps = 1e-7;
struct point {
    int x,y;
    point() {}
    point(int _x,int _y) {x = _x;y = _y;}
    point operator -(point rhs) {
        return point(x-rhs.x,y-rhs.y);
    }
    bool operator ==(point rhs) {
        return (x == rhs.x && y == rhs.y) || (-x == rhs.x && -y == rhs.y);
    }
    int operator *(point rhs) {
        return x*rhs.x + y*rhs.y;
    }
};
point p[21];
double val(point a) {
    return sqrt(a.x*a.x + a.y*a.y);
}
bool rec(int a,int b,int c,int d) {
    point p1 = p[b] - p[a],p2 = p[c] - p[a];
    if (p1*p2 == 0) && (abs(val(p1) - val(p2)) < eps)
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int i = 1;i <= n; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        int ans = 0;
        for (int i = 1;i <= n; i++)
            for (int j = i+1;j <= n; j++)
                for (int k = j+1;k <= n; k++)
                    for (int s = k+1;s <= n; s++)
                        if (rec(i,j,k,s)) {
                            ans++;
                            printf("%d %d %d %d\n",i,j,k,s);
                        }
        printf("%d\n",ans);
    }
	return 0;
}

