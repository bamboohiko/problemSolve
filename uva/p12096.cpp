#include<iostream>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
typedef set<int> Set;
stack<int> s;
map<Set,int> idcache;
vector<Set> setcache;
int id(Set x)
{
	if (idcache.count(x)) return idcache[x];
	setcache.push_back(x);
	return idcache[x] = setcache.size()-1;
}
int main()
{int n;
 string op;
	cin >> n;
	for (int i = 0;i < n; i++)
		{cin >> op;
		if (op[0] == 'P') s.push(id(Set()));
		else 
			if (op[0] == 'D') s.push(s.top());
			else {
				Set x,x1,x2;
				x1=setcache[s.top()];s.pop();
				x2=setcache[s.top()];s.pop();
				if (op[0] == 'U') set_union(ALL(x1),ALL(x2),INS(x));
				if (op[0] == 'I') set_intersection(ALL(x1),ALL(x2),INS(x));
				if (op[0] == 'A') 
					{x=x2;
					x.insert(id(x1));
					}
				s.push(id(x));
			}
		cout << setcache[s.top()].size() << endl;
		}
	return 0;
}
