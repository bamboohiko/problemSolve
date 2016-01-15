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
const int mod = 1e4;
int a[10010];
int main() {
    string st,ans = "1";
    int n,z = 0;
    scanf("%d",&n);
    while (n--) {
        bool check = true;
        int cou = 0;
        cin >> st;
        if (st.size() == 1 && st[0] == '0') {
            z = 0;ans = "0";
            break;
        }
        if (st[0] != '1') check = false;
        else {
            for (int i = 1;i < st.size(); i++)
                if (st[i] == '0') cou++;
                else {
                    check = false;
                    break;
                }
            if (check) z += cou;
        }
        if (!check) ans = st;
    }
    cout << ans;
    while (z--) putchar('0');
    puts("");
    return 0;
}
