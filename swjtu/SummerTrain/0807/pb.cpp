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
int cou[10100];
int main() {
    string st;
    while (cin >> st) {
        memset(cou,0,sizeof(cou));
        for (int i = 1;i < st.size(); i++)
            if (st[i] != st[i-1]) cou[i-1]++;
        int c = 0,k = 0;
        for (int i = st.size()-1;i >= 0; i--) {
            if (cou[i]) c = 1-c;
            if ((c && st[i] == '1') || (!c && st[i] == '0')) k++;
        }
        printf("%d %d\n",k,st.size() - k);
    }
	return 0;
}
