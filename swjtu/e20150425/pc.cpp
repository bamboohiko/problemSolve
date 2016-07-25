#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
stack<char> ope;
stack<double> num;
map<char,int> w; 
void str2num(string& st) {
	stringstream ss(st);
	double ans;
	ss >> ans;
	num.push(ans);
}
void fig(char ch) {
	double n2 = num.top();num.pop();
	double n1 = num.top();num.pop();
	if (ch == '+') n1 += n2;
	if (ch == '-') n1 -= n2;
	if (ch == '*') n1 *= n2;
	if (ch == '/') n1 /= n2;
	num.push(n1);
}
int main()
{
	w['+'] = 1;w['-'] = 1;
	w['*'] = 2;w['/'] = 2;
	w['('] = 0;
	string st,sav;
	int t;
	char ch;
	scanf("%d",&t);
	while (t--) {
		cin >> st;
		st = '(' + st;
		st[st.size()-1] = ')';
		for (int i = 0;i < st.size(); i++) {
			if (st[i] == '.' || (st[i] >= '0' && st[i] <= '9')) {
				sav += st[i];
			} else {
				if (sav.size()) {
					str2num(sav);
					sav = "";
				}
				if (st[i] == '(') {
					ope.push('(');
					continue;
				}
				if (st[i] == ')') {
					while (!ope.empty() && ope.top() != '(') {
						ch = ope.top();ope.pop();
						fig(ch);
					}
					ope.pop();
				} else {
					while (!ope.empty() && w[st[i]] <= w[ope.top()]) {
						ch = ope.top(); ope.pop();
						fig(ch);
					}
					ope.push(st[i]);
				}
 			}
		}
		printf("%.2lf\n",num.top());
		num.pop();
	}
	return 0;
}
