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
int b[100];
int num[100],cou[100];
int ans[100],anscou = 0;
int n;
bool vis;
void print() {
    vis = true;
    printf("%d",ans[0]);
    for (int i = 1;i < anscou; i++)
        printf("+%d",ans[i]);
    printf("\n");
}
void dfs(int k,int sum) {
    //cout << k << " " << sum << endl;
    if (sum == 0) {
        print();
        return;
    }
    if (k >= n) return;
    for (int i = cou[k];i >= 0; i--) {
        if (sum - i*num[k] < 0) continue;
        for (int j = 1;j <= i; j++) ans[anscou++] = num[k];
        dfs(k+1,sum - i*num[k]);
        anscou -= i;
    }
}
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int s,nk;
        scanf("%d%d",&s,&nk);
        printf("Sums of %d:\n",s);
        for (int i = 0;i < nk; i++) scanf("%d",&b[i]);
        sort(b,b+nk,cmp);
        int numcou = 1;n = 0;
        for (int i = 1;i < nk; i++) {
            if (b[i] != b[i-1]) {
                num[n] = b[i-1];
                cou[n++] = numcou;
                numcou = 1;
            } else numcou++;
        }
        num[n] = b[nk-1];
        cou[n++] = numcou;
        vis = false;
        dfs(0,s);
        if (!vis) printf("NONE\n");
    }
	return 0;
}
