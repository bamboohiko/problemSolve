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
string dir = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main()
{
    string st;
    char ch;
    scanf("%c",&ch);
    cin >> st;
    for (int i = 0;i < st.size(); i++) {
        for (int j = 0;j < dir.size(); j++)
            if (st[i] == dir[j]) {
                if (ch == 'L') cout << dir[j+1];
                if (ch == 'R') cout << dir[j-1];
                break;
            }
    }
    cout << endl;
	return 0;
}
