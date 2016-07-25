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
int f[10][10];
vector<int> V;
int dp() {
    f[0][0] = 1;
    for (int i = 1;i <= 7; i++)
        for (int j = 0;j < 10; j++) {
            if (j == 4) continue;
            for (int k = 0;k < 10; k++)
                if (j*10+k != 62) f[i][j] += f[i-1][k];
        }
}
int fig(int k) {
    V.clear();
    V.push_back(0);
    while (k) {
        V.push_back(k%10);
        k /= 10;
    }
    V.push_back(0);
    int ans = 0;
    for (int i = V.size()-2;i > 0; i--) {
        for (int j = 0;j < V[i]; j++)
            if (j != 4 && V[i+1]*10+j != 62) ans += f[i][j];
        if (V[i] == 4 || V[i+1]*10+V[i] == 62) break;
    }
    return ans;
}
int main() {
    int l,r;
    dp();
    while (scanf("%d%d",&l,&r) != EOF) {
        if (l == 0 && r == 0) break;
        printf("%d\n",fig(r+1)-fig(l));
    }
	return 0;
}

