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
char st[10001000];
int main() {
    //freopen("in.txt","r",stdin);
    int ca = 0;
    while (scanf("%s",st) != EOF) {
        int cou1 = 0,cou2 = 0;
        for (char* ch = st;(*ch) != '\0'; ch++) {
            cou1 = (cou1*10 + (*ch) - '0')%73;
            cou2 = (cou2*10 + (*ch) - '0')%137;
        }
        printf("Case #%d: ",++ca);
        if (cou1 == 0 && cou2 == 0) puts("YES");
        else puts("NO");
    }
	return 0;
}
