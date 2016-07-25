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
struct time{
    int h,m;
    time (int _h = 0,int _m = 0) {
        h = _h;m = _m;
    }
    bool operator <(time rhs) {
        if (h == rhs.h) return m < rhs.m;
        else return h < rhs.h;
    }
    time operator +(int dt) {
        time t = time(h,m+dt);
        while (t.m < 0) {t.h--;t.m += 60;}
        while (t.m >= 60) {t.h++;t.m -= 60;}
        return t;
    }
};
int main() {
    int a,b;
    int ta,tb;
    time t,st,ed;
    scanf("%d%d",&a,&ta);
    scanf("%d%d",&b,&tb);
    scanf("%d%*c%d",&t.h,&t.m);
    st = t + (-tb);ed = t + ta;
    int ans = 0;
    //cout << st. h << " " << st.m << endl;
    //cout << ed. h << " " << ed.m << endl;
    for (time t = time(5,0);t < time(24,0);t = t + b) {
        if (st < t && t < ed) ans++;
    }
    printf("%d\n",ans);
	return 0;
}

