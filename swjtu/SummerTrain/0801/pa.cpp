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
char a[300],b[300],c[300];
int f[310][310];
int main() {
    memset(f,-1,sizeof(f));f[0][0] = 0;
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        int n;
        scanf("%d",&n);
        a[0] = ' ';b[0] = ' ';
        scanf("%s",a+1);
        for (int i = 2;i <= n; i++) {
            scanf("%s",b+1);
            int len1 = strlen(a),len2 = strlen(b);
            for (int i = 1;i < len1; i++) {
                for (int j = 1;j < len2; j++) {
                    f[i][j] = max(f[i-1][j],f[i][j-1]);
                    if (a[i] == b[j]) f[i][j] = max(f[i][j],f[i-1][j-1]+1);
                    //cout << f[i][j] << " ";
                }
                //cout << endl;
            }
            int x = len1-1,y = len2-1;a[f[x][y]+1] = '\0';
            while (x > 0 && y > 0) {
                if (f[x][y] == f[x-1][y-1]+1) {a[f[x][y]] = b[y];x--,y--;}
                else if (f[x][y] == f[x][y-1]) y--;
                else if (f[x][y] == f[x-1][y]) x--;
            }
        }
        printf("Case #%d: ",ca);
        if (strlen(a) == 1) printf("-1\n");
        else printf("%s\n",a+1);
    }
	return 0;
}
