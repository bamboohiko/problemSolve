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
char st[2010],ans[2010];
int main() {
    int n;
    //while (scanf("%d%*c",&n) != EOF) {
    scanf("%d%*c",&n);
        for (int i = 1; i <= n; i++) scanf("%c%*c",&st[i]);
        int l = 1,r = n,cou = 0;
        while (l <= r) {
            //cout << l << " " << r << endl;
            int i = l,j = r;
            while (i+1 < j && st[i] == st[j]) {i++;j--;}
            if (st[i] < st[j]) ans[++cou] = st[l++];
            else ans[++cou] = st[r--];
        }
        for (int i = 1;i <= n; i++) {
            printf("%c",ans[i]);
            if (i%80 == 0) puts("");
        }
        if (n%80 != 0) puts("");
    //}
    return 0;
}

