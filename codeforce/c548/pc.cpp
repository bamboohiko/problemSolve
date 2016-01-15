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
typedef long long LL;
const LL INF = 1e12 + 10;
int vis[1000100];
vector<int> a,b;
LL hcd(LL a,LL b) {
    LL x = a,y = b;
    while (y) {
        LL t = x;x = y;y = t%y;
    }
    return a*b/x;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {x = 1;y = 0;return a;}
    LL d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
LL modequ(LL a, LL n, LL b){
    LL x, y;
    LL d = exgcd(a,n,x,y);
    while (d < 0) d += n;
    if (b % d == 0){
        x = (x* (b/d)) % n ;       //模方程的一个解
        x = (x + n) % (n/d);       //模方程的最小整数解
        return x;
    }
    return -1;
}
int main()
{
    LL m;
    LL h1,a1,x1,y1;int Ta,Da = -1;
    LL h2,a2,x2,y2;int Tb,Db = -1;
    scanf("%I64d",&m);
    scanf("%I64d%I64d%I64d%I64d",&h1,&a1,&x1,&y1);
        memset(vis,-1,sizeof(vis));
        vis[h1] = 0;
        int turn = 1;
        while (true) {
            h1 = (x1*h1 + y1)%m;
            if (vis[h1] != -1) {Ta = turn - vis[h1];break;}
            if (h1 == a1) Da = turn;
            vis[h1] = turn;
            turn++;
        }
    scanf("%I64d%I64d%I64d%I64d",&h2,&a2,&x2,&y2);
        memset(vis,-1,sizeof(vis));
        vis[h2] = 0;
        turn = 1;
        while (true) {
            h2 = (x2*h2 + y2)%m;
            //cout << h2 << endl;
            if (vis[h2] != -1) {Tb = turn - vis[h2];break;}
            if (h2 == a2) Db = turn;
            vis[h2] = turn;
            turn++;
        }
    cout << Ta << " " << Da << endl;
    cout << Tb << " " << Db << endl;
    //cout << a.size() << " " << b.size() << endl;
    if (Da == -1 || Db == -1) {
        printf("-1\n");
    } else if (Tb == 1) {
        while (Da < Db) Da += Ta;
        printf("%d\n",Da);
    } else if (Ta == Tb && Da != Db){
        printf("-1\n");
    } else {
        LL k = modequ(Ta,Tb,Db-Da);
        if (k == -1) printf("%I64d\n",k);
        else printf("%I64d\n",Ta*k+Da);
    }
	return 0;
}
