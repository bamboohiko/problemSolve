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
char st[300100];
bool ischar(char ch) {
    return ch >= 'a' && ch <= 'z';
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",st+1);st[0] = 'a';st[n+1] = 'a';
    int cou = 0,sum = 0;
    for (int i = 1;i <= n; i++) {
        if (st[i] == '.') {
            cou++;
            if (st[i-1] != '.') sum++;
        }
    }
    int loc;char ch;
    for (int i = 1;i <= m; i++) {
        scanf("%d %c",&loc,&ch);
        if ((ch == '.' && st[loc] == '.') || (ischar(ch) && ischar(st[loc]))) ;
        else {
            if (ch == '.') {
                cou++;
                if (ischar(st[loc-1]) && ischar(st[loc+1])) sum++;
                if (st[loc-1] == '.' && st[loc+1] == '.') sum--;
            } else {
                cou--;
                if (ischar(st[loc-1]) && ischar(st[loc+1])) sum--;
                if (st[loc-1] == '.' && st[loc+1] == '.') sum++;
            }
        }
        st[loc] = ch;
        //cout << cou << " " << sum << endl;
        printf("%d\n",cou-sum);
    }
	return 0;
}

