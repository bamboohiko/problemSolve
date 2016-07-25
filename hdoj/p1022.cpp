#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
const string act[2]={"in","out"};
int main()
{int n;
	while (cin >> n)
		{char a[20];
		char b[20];
		cin >> a >> b;
		//cout << a << endl;
		//cout << b << endl;
		stack<char>	s;
		vector<int> rec;
		int ok=1,j=0;
		for (int i = 0;i < n; i++)
			{while ((j < n) && ((s.empty()) || (s.top() != b[i]))) 
				{s.push(a[j++]);
				rec.push_back(0);
				}
			if (s.top() == b[i]) 
				{s.pop();
				rec.push_back(1);
				}
			else 
				{ok=0;
				break;
				}
			}
		if (ok) 
			{cout << "Yes." << endl;
			for (vector<int>::iterator i = rec.begin();i != rec.end(); i++)
				cout << act[*i] << endl;
			}
		else cout << "No." << endl;
		cout << "FINISH\n";	
		}
	return 0;
}
