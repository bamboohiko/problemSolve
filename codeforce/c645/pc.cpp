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
vector<int> V;
int f[100100];
string st;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    cin >> st;st = " " + st;
    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (st[i] == '0') {
            f[i] = f[i-1]+1;
            V.push_back(i);
            if (f[i] > m) {
                int l = upper_bound(f,f+i,f[i]-1-m) - f;
                int mid = lower_bound(V.begin(),V.end(),(l+i)/2) - V.begin();
                ans = min(ans,max(V[mid]-l,i-V[mid]));
                ans = min(ans,max(V[mid-1]-l,i-V[mid-1]));
                ans = min(ans,max(V[mid+1]-l,i-V[mid+1]));
            }
        } else f[i] = f[i-1];
    }
    printf("%d\n",ans);
    return 0;
}

