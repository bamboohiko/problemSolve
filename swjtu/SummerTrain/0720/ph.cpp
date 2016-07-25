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
const int INF = 1e9 + 7;
int a[100],num,n;
int sav[100],cou = 0,ans;
void fig() {
    int sum = 0;
    int pos = num+1,neg = 1;
    for (int i = 1;i <= n; i++) {
        bool is = false;
        for (int j = 0;j < cou; j++)
            if (i == sav[j]) {
                is = true;
                break;
            }
        if (is) sum += a[neg++] + i;
        else sum += a[pos++]*i;
    }
    ans = max(sum,ans);
}
void dfs(int k,int loc) {
    if (loc >= num) fig();
    else {
        for (int i = k;i <= n; i++) {
            sav[cou++] = i;
            dfs(i+1,loc+1);
            cou--;
        }
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for (int i = 1;i <= n; i++)
            if (a[i] > 0) {
                num = i-1;
                break;
            }
        ans = -INF;
        dfs(1,0);
        printf("%d\n",ans);
    }
	return 0;
}
