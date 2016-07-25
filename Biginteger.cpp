#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Biginteger{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;
	
	Biginteger(long long num = 0) {*this = num;}
	Biginteger operator = (long long num)	
		{s.clear();
		while (num > 0)
			{s.push_back(num%BASE);
			num /= BASE;
			}
		return *this;
		}
	Biginteger operator = (const string& st)
		{s.clear();
		int x,len = (st.length() - 1) / WIDTH +1;
		for (int i = 0;i < len; i++)
			{int end = st.length() -i*WIDTH;
			int start = max(end - WIDTH,0);
			sscanf(st.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
			}
		return *this;	
		}
	ostream& operator << (ostream &out,const Biginteger& x)
		{out << x.s.back()
		for (int i = x.s.size()-2;i >= 0; i--)
			{char buf[20];
			sprintf(buf,"%08d",x.s[i]);
			for (int j = 0;j < strlen(buf); j++) out << buf[j];
			}
		return out;
		}
	ostream operator >> (istream &in,Biginteger& x)
		{string s;
		if (!(in >> s)) return in;
		x = s;
		return in;
		}
	Biginteger operator + (const Biginteger& b) const
		{Biginteger c;
		c.s.clear();
		for (int i = 0, g = 0;; i++)
			{if (!(g) && (i >= s.size()) && (i >= b.s.size())) break;
			int x = g;
			if (i < s.size()) x+=s[i];
			if (i < b.s.size()) x+=b.s[i];
			c.s.push_back(x%BASE);
			g = x/BASE;
			}	
		return c;
		}
	Biginteger operator += (const Biginteger& b)
		{*this = *this + b;
		return *this;
		}
};
int main()
{Biginteger a,b;
	while (cin >> a >> b)
		cout << a+b << endl;
	return 0;	
}
