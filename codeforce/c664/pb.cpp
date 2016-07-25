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
int opt[110];
int main() {
    char ch;
    int n,ed = 1,add = 1,sub = 0;
    opt[1] = 1;
    while (true) {
        ch = getchar();
        if (ch == '=') {
            scanf("%d",&n);
            break;
        } else {
            if (ch == '+') {opt[++ed] = 1;add++;}
            if (ch == '-') {opt[++ed] = -1;sub++;}
        }
    }
    if (add*n < n+sub || add > n + sub*n) puts("Impossible");
    else {
        int k ,loc = 0, sum = 0;
        if (n + sub <= add*n && add*n <= n + sub*n) sum = add*n;
        if (n + sub <= add && add <= n + sub*n) sum = add;
        if (sum) {
            if (sub > 0) {k = (sum - n)/sub;loc = sum - n - sub*k;}
            for (int i = 1;i <= ed; i++)
                if (opt[i] > 0) opt[i] *= sum/add;
                else {
                    if (loc) {opt[i] *= k+1;loc--;}
                    else opt[i] *= k;
                }
        } else {
            sum = n + sub;
            k = sum/add;loc = sum - k*add;
            for (int i = 1;i <= ed; i++)
                if (opt[i] > 0) {
                    if (loc) {opt[i] *= k+1;loc--;}
                    else opt[i] *= k;
                }
        }
        puts("Possible");
        printf("%d ",opt[1]);
        for (int i = 2;i <= ed; i++)
            if (opt[i] > 0) printf("+ %d ",opt[i]);
            else printf("- %d ",-opt[i]);
        printf("= %d\n",n);
    }
	return 0;
}

