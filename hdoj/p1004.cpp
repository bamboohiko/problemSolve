#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map<string,int> cou;
int main()
{int n;
	while ((cin >> n) && (n))
		{cou.clear();
		string rec,s;
		int ans=0;
		for (int i = 1;i <= n; i++)
			{cin >> s;
			if (!cou.count(s)) cou[s]=1;
			else cou[s]++;
			if (cou[s] > ans)
				{ans = cou[s];
				rec = s;
				}  
			}
		cout << rec << endl;
		}
	return 0;
}

