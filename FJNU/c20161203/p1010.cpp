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
const int a[10] = {6,2,5,5,4,5,6,3,7,6};
string st;
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int sum = 0;
        cin >> st;
        for (int i = 0;i < st.size(); i++)
            sum += a[st[i] - '0'];
        int num = 0,cnt = sum/4,rec = 0;
        if (sum%4 == 1)
            if (cnt >= 2) {num = 7;cnt -= 2;rec = 1;}
            else {num = 5;cnt--;}
        if (sum%4 == 2) num = 1;
        if (sum%4 == 3) num = 7;
        if (rec) printf("7");
        for (int i = 1;i <= cnt; i++) printf("1");
        if (num) printf("%d",num);
        for (int i = 1;i <= cnt; i++) printf("1");
        if (rec) printf("7");
        puts("");
    }
	return 0;
}
