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
int x[1010],y[1010];
struct line{
    double k,b;int st;
    bool operator <(const line &rhs) const {
        if (st && rhs.st) return b < rhs.b;
        if (st) return true;
        if (rhs.st) return false;
        if (abs(k-rhs.k) < eps) return b < rhs.b;
        else return k < rhs.k;
    }
};
vector<line> V;
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++)
        scanf("%d%d",&x[i],&y[i]);
    for (int i = 1;i < n; i++)
        for (int j = i+1;j <= n; j++) {
            line L;
            if (x[i] == x[j]) {
                L.st = 1;L.k = 0;L.b = x[i];
            } else {
                L.st = 0;L.k = (y[j]-y[i])/(x[j]-x[i]);
                L.b = y[i] - k*x[i];
            }
            V.push_back(L);
        }
    sort(V.begin(),V.end());
    for (int i = 1;i < V.size(); i++)
	return 0;
}

