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
int main() {
    int t;
    LL n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld%lld",&m,&n);
        V.clear();
        while (n) {
            V.push_back(n%3);
            n /= 3;
            if (V.size() >= m) break;
        }
        while (V.size() < m) V.push_back(0);
        for (int i = V.size()-1;i >= 0; i--) {
            if (V[i] == 0) putchar('R');
            if (V[i] == 1) putchar('G');
            if (V[i] == 2) putchar('B');
        }
        printf("\n");
    }
	return 0;
}

