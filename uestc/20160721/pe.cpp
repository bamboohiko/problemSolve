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
char st[100];
bool vis[5][10][10];
int loc[10];
bool check() {
    memset(vis,0,sizeof(vis));
    for (int i = 0;i < 9; i++)
        for (int j = 0;j < 9; j++) {
            int num = st[i*9+j] - '0';
            if (vis[1][i][num] || vis[2][j][num] || vis[3][i/3*3+j/3][num]) return false;
            vis[1][i][num] = vis[2][j][num] = vis[3][i/3*3+j/3][num] = true;
        }
    for (int i = 1;i <= 3; i++)
        for (int j = 0;j < 9; j++)
            for (int k = 1;k <= 9; k++)
                if (!vis[i][j][k]) return false;
    return true;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        for (int i = 0;i < 9; i++)
            scanf("%s",st+i*9);
        int cou = 0;
        for (int i = 0;i < 9; i++)
            for (int j = 0;j < 9; j++)
                if (st[i*9+j] == '0') {
                    loc[cou++] = i*9+j;
                }
        bool pass = false;
        for (int i = 1;i < 100000; i++) {
            int k = i;
            for (int j = 0;j < 5; j++) {
                st[loc[j]] = k%10 + '0';
                if (st[loc[j]] == '0') {k = 1;break;}
                k /= 10;
            }
            if (k) continue;
            //for (int j = 0;j < 5; j++) putchar(st[loc[j]]);puts("");
            if (check()) {
                pass = true;
                break;
            }
        }
        if (pass) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) putchar(st[i*9+j]);
                puts("");
            }
        } else {
            puts("Could not complete this grid.");
        }
        puts("");
    }
	return 0;
}
