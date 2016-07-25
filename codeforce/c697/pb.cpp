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
string a,d;
stringstream ss;
int main() {
    cin >> st;
    int locp = st.find('.'),loce = st.find('e'),b;
    a = st.substr(0,locp);
    d = st.substr(locp+1,loce-1-locp);
    ss << st.substr(loce+1);
    ss >> b;
    while (d.length() < b) d += '0';
    bool fi = false;
    if (a == "0") fi = true;
    if (d != "0") {
    d = a + d;b += a.length();
    for (int i = 0;i < d.length(); i++) {
        if (i == b) cout << '.';
        if (i < (b-1) && fi) {
            if (d[i] != '0') {
                cout << d[i];
                fi = false;
            }
        } else cout << d[i];
    }
    } else {
        cout << a;
    }
    cout << endl;
	return 0;
};
