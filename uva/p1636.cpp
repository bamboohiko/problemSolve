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
string st;
int main() {
    while (cin >> st) {
        st = st + st[0];
        int a = 0,b = 0,n = st.length()-1;
        for (int i = 0;i < n; i++) {
            if (st[i] == '0') {
                b++;
                if (st[i+1] == '0') a++;
            }
        }
        //cout << a << " " << b << endl;
        if (a*n > b*b) puts("SHOOT");
        else if (a*n < b*b) puts("ROTATE");
        else puts("EQUAL");
    }
	return 0;
}
