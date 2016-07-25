#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct point{
	int l,r,w,d;
	char ch;
	point(char ch=' ',int w=0,int l=-1,int r=-1,int d=0):ch(ch),w(w),l(l),r(r),d(d) {} 
}; 
map<char,int> f;	//Îª×Ö·û±àºÅ 
vector<point> huffman; //huffmanÊ÷
map<char,string> id;	//huffman±àÂë 
bool cmp(point a,point b)
{
	return a.w < b.w;
}
int usemin(int& k1,int n1,int& k2,int n2)
{
	if (k1 > n1) return k2++;
	if (k2 > n2) return k1++;
	if (huffman[k1].w < huffman[k2].w) return k1++;
	else return k2++;
}
void dfs(int k,string st,int deep)
{
	huffman[k].d = deep;
	//printf("%d %c %d %d\n",k,huffman[k].ch,huffman[k].l,huffman[k].r); 
	if (huffman[k].l >= 0) dfs(huffman[k].l,st+"0",deep+1);
	if (huffman[k].r >= 0) dfs(huffman[k].r,st+"1",deep+1);
	if (huffman[k].ch != ' ') 
		{
			id[huffman[k].ch] = st;
			//cout << huffman[k].ch << " " << st << endl;
		}
}
void build_huffman()
{int k1 = 0,n1 = huffman.size()-1,k2 = n1+1,n2 = n1;
	for (int i = 1;i <= n1; i++)
		{int a = usemin(k1,n1,k2,n2);
		int b = usemin(k1,n1,k2,n2);
		point p(' ',huffman[a].w+huffman[b].w,a,b);
		huffman.push_back(p);
		n2++;
		}
	dfs(huffman.size()-1,"",0);
}
int main()
{string st1,st2; 
	cin >> st1;
	for (int i = 0;i < st1.length(); i++)
		if (!f.count(st1[i])) 
			{f[st1[i]] = huffman.size();
			point p(st1[i],1);
			huffman.push_back(p);
			}
		else huffman[f[st1[i]]].w++;
	sort(huffman.begin(),huffman.end(),cmp);
	/*
	for (int i = 0;i < huffman.size(); i++)
		cout << huffman[i].ch << " " << huffman[i].w << endl;
	*/
	build_huffman();	

	cin >> st2;
	for (int i = 0;i < st2.length(); i++)
		cout << id[st2[i]];
	cout << endl;
	
	return 0;
}
