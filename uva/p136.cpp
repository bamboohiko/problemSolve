#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int d[]={2,3,5};
set<long long> s;
priority_queue<long long,vector<long long>,greater<long long> > line;
int main()
{
	s.insert(1);
	line.push(1);
	for (int i = 1;; i++)
		{long long x=line.top();line.pop();
		if (i == 1500) 
			{cout << "The 1500'th ugly number is " << x << endl; 
			break;
			}
		for (int j = 0;j < 3;j++)
			{long long x1=x*d[j];
			if (!s.count(x1)) 
				{s.insert(x1);
				line.push(x1);
				}
			}
		}
		
	return 0;
}
