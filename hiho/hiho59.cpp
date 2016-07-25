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
struct Time{
    int h,m,s;
    operator <(const Time& rhs) {
        if (h != rhs.h) return h < rhs.h;
        if (m != rhs.m) return m
    }
};
map<string,int> dic;
stack<Time> T;
stack<int> S;
int main() {
    string name,dem;
    int n;
    scanf("%d",&n);
    bool w = true;
    for (int i = 1;i <= n; i++) {
        cin >> st;
        if (!dic.count(st)) dic[st] = dic.size();
        Time nt;
        scanf("%d:%d:%d",nt.h,nt.m,nt.s);
        if (!T.empty() && T.top() < nt)
        cin >> dem;
    }
	return 0;
}
