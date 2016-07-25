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
string s[5];
string num2str(int n) {
    stringstream s;
    s << n;
    return s.str();
}
int find(char c,int n) {
    string sav = "";
    if (n == 14) n = 1;
    sav += c;
    sav += num2str(n);
    //cout << sav << endl;
    for (int i = 0;i < 5; i++)
        if (sav == s[i])
            return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        for (int i = 0;i < 5; i++)
            cin >> s[i];
        int ans = 0;
        for (char c = 'A';c <= 'D'; c++)
            for (int i = 1;i <= 10; i++) {
                //cout << c << " " << i << endl;
                int cou = 0;
                for (int j = 0;j < 5; j++)
                    cou += find(c,i+j);
                ans = max(ans,cou);
        }
        printf("%d\n",5-ans);
    }
	return 0;
}
