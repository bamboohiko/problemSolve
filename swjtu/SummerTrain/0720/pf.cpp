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
struct point {
    double x,y;
};
    point operator -(point &a,point &b) {
        point ans;
        ans.x = a.x - b.x;
        ans.y = a.y - b.y;
        return ans;
    }
    double cross(point a,point b) {
        return (double)a.x*b.y - a.y*b.x;
    }
    double dot(point a,point b) {
        return (double)a.x*b.x + a.y*b.y;
    }
    double dcmp(double k) {
        double eps = 1e-6;
        if (abs(k) < eps) return 0;
        return k > 0?1:-1;
    }
double str2num(string st) {
    //cout << st << "->";
    if (st.size() == 0) return 1;
    int ans = 0;
    for (int i = (st[0] == '-' || st[0] == '+')?1:0;i < st.size(); i++) {
        ans = ans*10 + (st[i] - '0');
    }
    if (ans == 0 && st.size() == 1) ans = 1;
    if (st[0] == '-') ans *= -1;
    //cout << ans << endl;
    return ans;
}
point deal(string st) {
    point ans;
    if (st.find("i") == -1) {
        if (st.size() == 1 && st[0] == '0') ans.x = 0;
        else ans.x = str2num(st);
        ans.y = 0;
    } else {
            int loc = st.find("+");
            if (loc == -1) {
                if (st[0] == '-') loc = st.substr(1).find("-")+1;
                else loc = st.find("-");
            }
            if (loc == -1) {
                ans.x = 0;
                ans.y = str2num(st.substr(0,st.size()-1));
            } else {
                ans.x = str2num(st.substr(0,loc));
                ans.y = str2num(st.substr(loc,st.size() - loc -1));
            }
    }
    return ans;
}
bool onseg(point p,point a1,point a2) {

    return dcmp(cross(a1 - p,a2 - p)) == 0 && dcmp(dot(a1 - p,a2 - p)) < 0;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        string st;
        cin >> st;point a1 = deal(st);
        //cout << a1.x << ":" << a1.y << endl;
        cin >> st;point a2 = deal(st);
        //cout << a2.x << ":" << a2.y << endl;
        cin >> st;point b1 = deal(st);
        //cout << b1.x << ":" << b1.y << endl;
        cin >> st;point b2 = deal(st);
        //cout << b2.x << ":" << b2.y << endl;
        double c1 = cross(a2 - a1,b1 - a1),c2 = cross(a2 - a1,b2 - a1),
        c3 = cross(b2 - b1,a2 - b1),c4 = cross(b2 - b1,a1 - b1);
        //printf("%lf %lf %lf %lf\n",c1,c2,c3,c4);
        printf("Case #%d: ",ca);
        if (dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0 ||
            ((c1 || c2) && onseg(a1,b1,b2) || onseg(a2,b1,b2) || onseg(b1,a1,a2) || onseg(b2,a1,a2))) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
