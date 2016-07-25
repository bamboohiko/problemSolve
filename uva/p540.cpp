#include<queue>
#include<iostream>
#include<map>
using namespace std;
int main()
{freopen("test.in","r",stdin);
 freopen("test.out","w",stdout);
 int t,n,x,c=0; 
 string op;
	while ((cin >> t) && (t))
		{map<int,int> team;
		for (int i = 0;i < t; i++)
			{cin >> n;
			for (int j = 0;j < n; j++)
				{cin >> x;
				team[x]=i;}
			}
		//for (int i = 1;i < 7;i++) cout << i << " " << team[i] << endl;
		queue<int> s[1010];
		queue<int> l;
		while ((cin >> op) && (op[0] != 'S'))
			{if (op[0] == 'E')
				{cin >> x;
				if (s[team[x]].empty()) l.push(team[x]);
				s[team[x]].push(x); 
				}
			else 
				{//cout << l.front() << endl;
				cout << s[l.front()].front() << endl;
				s[l.front()].pop();
				if (s[l.front()].empty()) l.pop();
				}
			}
		}
	return 0;
}
