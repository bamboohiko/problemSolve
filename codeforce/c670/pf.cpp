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
int cnt[20];
char st[1000100];
int main() {
    int n = 0;
    char ch;
    while ((ch = getchar()) != '\n') {n++;cnt[ch - '0']++;}
    gets(st);
    int k = 1;
    for (int i = 1;i <= 8; i++,k *= 10) {
        if (k <= n-i && n-i < 10*k) {
            k = n-i;
            break;
        }
    }
    for (int s = 1;s <= k; s *= 10) cnt[k/s%10]--;
    int len = strlen(st),fr = 1,zero = 1;
    for (int i = 0;i < len; i++) cnt[st[i] - '0']--;
    for (int i = 1;i < len; i++) {
        if (st[i] > st[0]) {
            fr = 0;
            break;
        } else if (st[i] < st[0]) {
            break;
        }
    }
    for (int i = 1;i < len; i++)
        if (st[i] == '0') zero++;
        else break;
    for (int i = 1;i <= 9; i++) {
        if (cnt[i]) {
            if (st[0] != '0' && '0' + i >= st[0] && fr == 1 && zero >= cnt[0]) {printf("%s",st);fr = 2;break;}
            if (st[0] != '0' && '0' + i > st[0] && fr == 0 && zero >= cnt[0]) {printf("%s",st);fr = 2;break;}
            putchar('0' + i);
            cnt[i]--;k--;
            break;
        }
        if (st[0] != '0' && '0' + i >= st[0] && fr == 1) {printf("%s",st);fr = 2;break;}
        if (st[0] != '0' && '0' + i > st[0] && fr == 0) {printf("%s",st);fr = 2;break;}
    }
    int num = 0;
    for (int i = 1;i <= k-len; i++) {
        while (!cnt[num]) num++;
        if ('0' + num >= st[0] && fr == 1) {printf("%s",st);fr = 2;}
        if ('0' + num > st[0] && fr == 0) {printf("%s",st);fr = 2;}
        putchar('0' + num);
        cnt[num]--;
    }
    if (fr == 1 || fr == 0) printf("%s",st);
    printf("\n");
	return 0;
}
