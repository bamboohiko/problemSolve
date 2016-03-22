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
int a[100100],b[100100];
int main() {
    int ans = 1,len = 0;
    char ch;
    while ((ch = getchar()) != '\n') a[len++] = ch - '0';
    for (int i = 0,j = len-1;i < j;i++,j--) {
        if (a[i] != a[j]) {
            if (a[i] - a[j] == 1) {a[i]--;a[i+1] += 10;}
            else if (a[i] - a[j] == 10) {a[j] += 10;a[j-1]--;}
            else {ans = 0;break;}
        }
    }
    if (!ans || (len == 1 && a[0]&1 == 1)) puts("0");
    else {
        for (int i = 0;i < len; i++) {
            if (b[i]) break;
            b[i] = a[i] >> 1;
            b[len-1 - i] = a[i] - b[i];
        }
        for (int i = len-1;i >= 0; i--)
            if (b[i])printf("%d",b[i]);
        puts("");
    }
	return 0;
}

