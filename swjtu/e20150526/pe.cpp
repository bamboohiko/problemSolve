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
double const pi = acos(-1);
struct point {
    double x,y;
};
struct line {
    double k,b;
    bool v;
};
double dis(point p1,point p2) {
    double dx = p1.x-p2.x,dy = p1.y-p2.y;
    return sqrt(dx*dx+ dy*dy);
}
point mid(point p1, point p2){
    point ans;
    ans.x = (p1.x + p2.x )/2;
    ans.y = (p1.y + p2.y )/2;
    return ans;
}
line creat(point p1,point p2){
    line ans;
    if (p1.x == p2.x) {
        ans.v = true;
        ans.b = p1.x;
        return ans;
    }
    ans.k = (p1.y - p2.y)/ (p1.x -p2.x);
    ans.b = p1.y - p1.x * ans.k ;
    ans.v = false;
    return ans;
}
point crosspoint(line l1,line l2){
    point ans;
    if (l1.v){
        ans.x = l1.b;
        ans.y = l2.k * ans.x + l2.b;
        return ans;
    }
    if (l2.v) {
        ans.x = l2.b;
        ans.y = l1.k * ans.x + l1.b;
        return ans;
    }
    ans.x = (l2.b-l1.b ) / (l1.k - l2.k);
    ans.y = (l1.k*l2.b-l2.k*l1.b)/(l1.k-l2.k);
    return ans;
}
line linepoint(point p,line lt) {
    line ans;
    if (lt.v) {
        ans.k = 0;
        ans.b = p.y;
        ans.v = false;
        return ans;
    }
    if (!lt.k) {
        ans.v = true;
        ans.b = p.x;
        return ans;
    }
    ans.k = tan(atan(lt.k)+pi/2);
    ans.b = p.y -  ans.k * p.x ;
    ans.v = false;
    return ans;
}
point p1,p2,p3,pt,m1,m2,po;
line l1,l2,lm1,lm2;
double r;
int main(int argc, char* argv[]){
    int t;
    scanf("%d",&t);
    for (int turn = 1;turn <= t; turn++){
        scanf("%lf%lf",&p1.x,&p1.y);
        scanf("%lf%lf",&p2.x,&p2.y);
        scanf("%lf%lf",&p3.x,&p3.y);
        scanf("%lf%lf",&pt.x,&pt.y);
        line l1 = linepoint(mid(p1,p2),creat(p1,p2));
        line l2 = linepoint(mid(p1,p3),creat(p1,p3));
        po = crosspoint(l1,l2);
        cout << po.x << " " << po.y << endl;
        if (dis(po,pt) <= dis(po,p1)) printf("Case #%d: Danger\n",turn);
        else printf("Case #%d: Safe\n",turn);
    }
    return 0;
}
