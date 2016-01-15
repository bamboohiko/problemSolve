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
string st;
bool check(int l,int r) {
    //cout << l << " " << r << endl;
    while (l < r) {
        if (st[l] != st[r]) return false;
        l++;r--;
    }
    return true;
}
int main()
{
    int k;
    cin >> st >> k;
    int len = st.size()/k;
    if (st.size()%k) cout << "NO" << endl;
    else {
        bool ans = true;
        for (int i = 1;i <= k; i++)
            if (!check((i-1)*len,i*len-1)) {
                ans = false;
                break;
            }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
