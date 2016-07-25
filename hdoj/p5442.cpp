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
struct data{
    string st;
    int loc,dir;
};
data a,b;
string rev(string st) {
    string ans = st;
    int n = st.length();
    for (int i = 0;i < n; i++)
        ans[i] = st[n-1-i];
    return ans;
}
bool cmp(data a,data b) {
    if (a.st != b.st) return a.st > b.st;
    if (a.loc != b.loc) return a.loc < b.loc;
    return a.dir < b.dir;
}
int main() {
    int t,n;
    string st;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        cin >> st;
        a.st = st;a.loc = 1;a.dir = 0;
        for (int i = 0;i < n; i++) {
            b.st = st.substr(i,n) + st.substr(0,i);
            b.loc = i+1;b.dir = 0;
            if (cmp(b,a)) a = b;
        }
        st = rev(st);
        for (int i = 0;i < n; i++) {
            b.st = st.substr(i,n) + st.substr(0,i);
            b.loc = n-i;b.dir = 1;
            if (cmp(b,a)) a = b;
        }
//        for (int i = 0; i < n+n; i++)
//            cout << a[i].st << " " << a[i].loc << " " << a[i].dir << endl;
        printf("%d %d\n",a.loc,a.dir);
    }
	return 0;
}

