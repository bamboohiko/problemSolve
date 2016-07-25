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
struct point {
    int x,y;
    point(int _x = 0,int _y = 0):x(_x),y(_y) {}
    point operator -(point rhs) {
        return point(x-rhs.x,y-rhs.y);
    }
    bool operator ==(point rhs) {
        return ((x == rhs.x) && (y == rhs.y)) || ((x == -rhs.x) && (y == -rhs.y));
    }
    int operator *(point rhs) {
        return x*rhs.x + y*rhs.y;
    }
    void print() {
        cout << x << ":" << y << endl;
    }
};
bool check(point a,point b,point c,point d) {
    //a.print(),b.print(),c.print(),d.print();
    if (a*b == 0 && b*c == 0 && c*d == 0 && d*a == 0 && a == c) return true;
    return false;
}
point a[110];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i<= n; i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        if (n != 4) printf("NO\n");
        else {
            bool ans = false;
            int f[] = {1,2,3,4};
            for (int i = 0;i < 24; i++) {
                if (check(a[f[1]]-a[f[0]],a[f[2]]-a[f[1]],a[f[3]]-a[f[2]],a[f[0]]-a[f[3]])) {
                    ans = true;
                    break;
                }
                next_permutation(f,f+4);
                //for (int i = 0;i < 4;i++) cout <<f[i] << " ";cout << endl;
            }
            if (ans) printf("YES\n");
            else printf("NO\n");
        }
    }
	return 0;
}

