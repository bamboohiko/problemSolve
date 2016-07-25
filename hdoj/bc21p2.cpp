#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const long long M = 1000000007;
vector<int> v;
int main()
{int n,t = 0;
	while (scanf("%d",&n) != EOF)
		v.push_back(n);
	sort(v.begin(),v.end());
	int MAX = v.back(); 
	long long mul = 1,sav = 1;
	for (int i = 1;i <= MAX; i++)
		{mul = mul*i%M;
		sav = mul*sav%M;
		if (v[t] == i) 
			{printf("%d\n",sav);
			t++;
			}
 		}
	return 0;
}
