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
char a[10],b[10];
string s1,s2;
int main() {
    s1 = "";s2 = "";
    scanf("%c%c%*c%c%c%*c",&a[0],&a[1],&a[3],&a[2]);
    scanf("%c%c%*c%c%c%*c",&b[0],&b[1],&b[3],&b[2]);
    for (int i = 0;i < 4; i++)
        if (a[i] == 'A') {
            for (int j = 0;j < 4; j++)
                if (a[(i+j)%4] != 'X') s1 += a[(i+j)%4];
        }
    for (int i = 0;i < 4; i++)
        if (b[i] == 'A') {
            for (int j = 0;j < 4; j++)
                if (b[(i+j)%4] != 'X') s2 += b[(i+j)%4];
        }
    if (s1 == s2) puts("YES");
    else puts("NO");
	return 0;
}

