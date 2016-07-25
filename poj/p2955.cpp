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
char st[110];
int f[110][110];
int main() {
    while (gets(st) && st[0] != 'e') {
        int n = strlen(st);
        memset(f,0,sizeof(f));
        for (int len = 1;len < n; len++)
            for (int i = 0;i + len < n; i++) {
                int j = i + len;
                if ((st[i] == '(' && st[j] == ')') || (st[i] == '[' && st[j] == ']')) f[i][j] = f[i+1][j-1] + 2;
                for (int k = i+1;k <= j; k++)
                    f[i][j] = max(f[i][j],f[i][k-1]+f[k][j]);
            }
        printf("%d\n",f[0][n-1]);
    }
	return 0;
}

