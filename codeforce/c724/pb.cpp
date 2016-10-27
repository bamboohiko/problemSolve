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
int n,m,a[30][30];
bool check() {
    for (int i = 1;i <= n; i++) {
        int cou = 0;
        for (int j = 1;j <= m; j++)
            if (a[i][j] != j) cou++;
        if (cou != 0 && cou != 2) return false;
    }
    return true;
}
int main() {
    bool pass = false;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= m; j++) scanf("%d",&a[i][j]);
    if (check()) pass = true;
    for (int x = 1;x <= m && !pass; x++)
        for (int y = x+1;y <= m && !pass; y++) {
            for (int i = 1;i <= n; i++) swap(a[i][x],a[i][y]);
            //cout << x << " " << y << endl;
            if (check()) pass = true;
            for (int i = 1;i <= n; i++) swap(a[i][x],a[i][y]);
        }
    if (pass) puts("YES");
    else puts("NO");
	return 0;
}
