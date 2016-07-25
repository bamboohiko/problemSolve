#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
stack<char> ope;
stack<double> num;
map<char,int> w;
double deal(string& st)
{
    stringstream ss(st);
    double ans;
    ss >> ans;
    return ans;
}
void fig(char ch)
{
    double n2 = num.top();num.pop();
    double n1 = num.top();num.pop();
    //cout << n1 <<ch << n2;
    if (ch == '+') n1 += n2;
    if (ch == '-') n1 -= n2;
    if (ch == '*') n1 *= n2;
    if (ch == '/') n1/= n2;
    //cout <<" " << n1 << endl;
    num.push(n1);
}
int main()
{
    w['+'] = w['-'] = 1;
    w['*'] = w['/'] = 2;
    w['('] = 0;
    int t;
    scanf("%d",&t);
    while (t--)
    {
		string st,sav = "";char ch;
        ope.push('(');
        cin >> st;
        st[st.size()-1] = ')';
        for (int i = 0;i < st.size(); i++)
        {
            if ((st[i] >= '0' && st[i] <= '9') || st[i] == '.')
            {
                sav += st[i];
                continue;
            }
            else
            {
                if (sav.size()) num.push(deal(sav));
                sav = "";
            }
            if (st[i] == '(') ope.push(st[i]);
            else if (st[i] == ')')
            {
                while (ope.top() != '(')
                {
                    ch = ope.top();ope.pop();
                    fig(ch);
                }
                ope.pop();
            }
            else
            {
                while (w[st[i]] <= w[ope.top()])
                {
                    ch = ope.top();ope.pop();
                    fig(ch);
                }
                ope.push(st[i]);
            }
        }
        printf("%.2lf\n",num.top());
        num.pop();
    }
	return 0;
}
