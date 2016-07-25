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
string st;
int f[110][110];
void dfs(int l,int r) {
    //cout << l << " " << r << endl;
    if (l > r) return;
    if (l == r) {
        if (st[l] == '(' || st[l] == ')') printf("()");
        else printf("[]");
        return;
    }
    if (((st[l] == '(' && st[r] == ')') || (st[l] == '[' && st[r] == ']'))
        &&  (f[l][r] == f[l+1][r-1])) {
            printf("%c",st[l]);
            dfs(l+1,r-1);
            printf("%c",st[r]);
    } else {
        for (int k = l;k < r; k++)
            if (f[l][r] == f[l][k] + f[k+1][r]) {
                dfs(l,k);
                dfs(k+1,r);
                break;
            }
    }
}
int main() {
        getline(cin,st);
        //cout << st << endl;
        int n = st.size();
        for (int i = 0;i < n; i++) f[i][i] = 1;
        for (int len = 1;len < n; len++)
            for (int l = 0;l+len < n; l++) {
                int r = l + len;
                f[l][r] = n+n;
                if (st[l] == '(' && st[r] == ')') f[l][r] = f[l+1][r-1];
                if (st[l] == '[' && st[r] == ']') f[l][r] = f[l+1][r-1];
                for (int k = l;k < r; k++)
                    f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]);
            }
        dfs(0,n-1);
        printf("\n");
	return 0;
}
