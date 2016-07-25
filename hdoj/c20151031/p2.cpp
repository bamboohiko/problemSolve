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
#define max(a,b) ((a>b)?a:b)
char st[510][2010];
int len[510],nt[2010],loc[510],ans;
bool cmp(int a,int b) {
    if (len[a] == len[b]) {
        ans = max(ans,max(a,b));
        return strcmp(st[a],st[b]);
    } else return len[a] < len[b];
}
bool kmp(int a,int b)  {
    memset(nt,0,sizeof(nt));
    for (int i = 1;i < len[b]; i++) {
        int j = i;
        while (j > 0) {
            j = nt[j];
            if (st[b][j] == st[b][i]) {
                nt[i + 1] = j+1;
                break;
            }
        }
    }
    for (int i = 0,j = 0;i < len[a]; i++) {
        if (j < len[a] && st[a][i] == st[b][j]) j++;
        else {
            while (j > 0) {
                j = nt[j];
                if (st[a][i] == st[b][j]) {
                    j++;
                    break;
                }
            }
        }
        if (j == len[b]) return true;
    }
    return false;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n;
        scanf("%d%*c",&n);
        for (int i = 1;i <= n; i++) {
            gets(st[i]);len[i] = strlen(st[i]);
            loc[i] = i;
        }
        ans = -1;
        sort(loc+1,loc+n+1,cmp);
        //for (int i = 1;i <= n; i++) cout << i << " " << loc[i] << endl;
        for (int i = n;i > 1;i--) {
            if (i <= ans) break;
            if (loc[i] != i) continue;
            for (int j = 1;j <= i-1;j++)
                if (!kmp(loc[i],loc[j])) {
                    ans = i;
                    goto lambel;
                } //else cout << i << ":" << j << endl;
        }
        lambel:
            printf("Case #%d: %d\n",ca ,ans);
    }
	return 0;
}

