#include<iostream>
#include<string>
using namespace std;
string st;
int main()
{
	while (getline(cin,st))
		{while (st.find("you") != st.npos)
			{int loc = st.find("you");
			st.replace(loc,3,"we");
			}
		cout << st << endl;
		}
	return 0;
}
