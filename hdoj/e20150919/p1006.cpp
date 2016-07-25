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
const int maxn = 1e6 + 100;
char st[maxn];
int loc[maxn];
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        scanf("%s",st);
        int cou = 0,n = strlen(st);
        for (int i = 0;i < n; i++) {
            if (st[i] == 'c') {
                loc[cou] = i;
                if (cou > 0 && loc[cou] - loc[cou-1] < 3) {cou = - 1;break;}
                cou++;
            }
            if (st[i] != 'c' && st[i] != 'f') {
                cou = -1;
                break;
            }
        }
        if (cou == 0) cou = (n+1)/2;
        else if (cou == 1) {cou = (n <= 2)?-1:cou;}
        else if (cou > 1) {if (n-loc[cou-1] + loc[0] <= 2) cou = -1;}
        printf("Case #%d: %d\n",ca,cou);
    }
	return 0;
}

