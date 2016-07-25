#include<iostream>
#include<string>
#include<map>
using namespace std;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y) {}
};
map<string,point> cou;
string act[]={"",""," Double Kill\n"," Trible Kill\n"," Ultra Kill\n"," Penta Kill\n"};
string pla[15];
string st,kil;
int main()
{int t,m;
	cin >> t;
	while (t--)
		{cou.clear();
		for (int i = 0;i < 10; i++)
			{cin >> pla[i];
			cou[pla[i]].x = 0;
			cou[pla[i]].y = 0;
			}
		cin >> m;
		while (m--)
			{cin >> st;
			int loc = st.find('('),div;
			kil = st.substr(0,loc);
			if (++cou[kil].x > 1)
				cout << kil << act[cou[kil].x];
			if (st.find('(') != st.npos)
				{loc = st.find('(')+1;
				while (st.find(',') != st.npos)
					{div = st.find(',');
					cou[st.substr(loc,div-loc)].y++;
					loc = div+1;
					st[div]='!';
					}
				cou[st.substr(loc,st.length()-loc-1)].y++;
				//cout << st.substr(loc,st.length()-loc-1) << endl;
				}
			cin >> st;
			cin >> st;
			}
		for (int i = 0;i < 10; i++)
			cout << pla[i] << " " << cou[pla[i]].x << " " << cou[pla[i]].y << endl;
		}
	return 0;
}
