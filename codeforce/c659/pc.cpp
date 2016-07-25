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
int a[100100];
vector<int> V;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cou = 1;
    for (int i = 1;i <= n; i++) {
        while (cou < a[i] && m >= cou) {
            m -= cou;
            V.push_back(cou++);
        }
        cou = a[i] + 1;
    }
    while (m >= cou) {m -= cou;V.push_back(cou++);}
    printf("%d\n",V.size());
    if (V.size() > 0) {
        printf("%d",V[0]);
        for (int i = 1;i < V.size(); i++) printf(" %d",V[i]);
        printf("\n");
    }
	return 0;
}

