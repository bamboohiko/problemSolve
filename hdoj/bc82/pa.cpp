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
char st[30],ss[30];
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",st+2);st[0] = st[1] = '0';
        int n = strlen(st),len = n-2,cnt4 = 0,cnt7 = 0,big = 0;
        ss[0] = ss[1] = '0';
        if (n%2 == 1) {ss[1] = '4';cnt4++;len++;big = 1;}
        for (int i = 2;i < n; i++) {
            if (!big) {
                if (st[i] <= '4' && cnt4 < len/2) {ss[i] = '4';cnt4++;}
                else if (st[i] <= '7' && cnt7 < len/2) {ss[i] = '7';cnt7++;}
                else {
                    int it = i-1;
                    while (ss[it] == '7') it--;
                    if (ss[it] == '0') {ss[it] = ss[it-1] = '4';cnt4+=2;len+=2;}
                    else {ss[it] = '7';cnt4--;}
                    i = it;
                }
                if (ss[i] > st[i]) big = 1;
            } else {
                if (cnt4 < len/2) {ss[i] = '4';cnt4++;}
                else ss[i] = '7';
            }
        }
        ss[n] = '\0';
        if (ss[1] == '0') printf("%s\n",ss+2);
        else if (ss[0] == '0') printf("%s\n",ss+1);
        else printf("%s\n",ss);
    }
	return 0;
}

