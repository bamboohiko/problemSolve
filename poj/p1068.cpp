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
string st;
int p[30],w[30];
stack<int> S;
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        int x = 0;st = "";
        for (int i = 1;i <= n; i++) {
            scanf("%d",&p[i]);
            while (x < p[i]) {st += "(";x++;}
            st += ")";
        }
        int l = 0,r = 0;
        for (int i = 0;i < st.size(); i++) {
            if (st[i] == '(') S.push(++l);
            else {
                w[++r] = l - S.top() + 1;
                S.pop();
            }
        }
        for (int i = 1;i < n; i++) printf("%d ",w[i]);
        printf("%d\n",w[n]);
    }
	return 0;
}

