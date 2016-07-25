#include<iostream>
using namespace std;
struct point{
	int x,y,z;
};
bool check (point p,point p1,point p2,point p3)
{
	p1.x-=p.x;p1.y-=p.y;p1.z-=p.z;
	p2.x-=p.x;p2.y-=p.y;p2.z-=p.z;
	p3.x-=p.x;p3.y-=p.y;p3.z-=p.z;
	cout << p1.x*p2.y*p3.z+p2.x*p3.y*p1.z+p3.x*p1.y*p2.z-p3.x*p2.y*p1.z-p1.x*p3.y*p2.z-p2.x*p1.y*p3.z << endl;
	return (p1.x*p2.y*p3.z+p2.x*p3.y*p1.z+p3.x*p1.y*p2.z-p3.x*p2.y*p1.z-p1.x*p3.y*p2.z-p2.x*p1.y*p3.z);
}
int main()
{int n;
	while (cin >> n)
		{point p1,p2,p3,p;
		if (n <= 3) {
			cout << "Yes" << endl;
			for (int i = 1;i <= n; i++)
				cin >> p1.x >> p1.y >> p1.z;
			continue;
			}
		cin >> p1.x >> p1.y >> p1.z;
		cin >> p2.x >> p2.y >> p2.z;
		cin >> p3.x >> p3.y >> p3.z;
		int ok = 1;
		for (int i = 4;i <= n; i++)
			{cin >> p.x >> p.y >> p.z;
			if (!check(p,p1,p2,p3)) 
				{ok = 0;
				break;
				}
			}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
		}
}
