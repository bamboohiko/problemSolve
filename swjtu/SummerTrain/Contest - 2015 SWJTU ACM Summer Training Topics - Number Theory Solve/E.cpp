#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string elem[110] ={ "",
					"H","He","Li","Be","B","C","N","O","F","Ne",
					"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
					"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu",
					"Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr",
					"Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag",
					"Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba",
					"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd",
					"Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta",
					"W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb",
					"Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
					"U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm" };
int  had[100];
int  res[100];
int  N, M;
int  sum[100];
int  next[100];
bool used[100];
char in[100];
string t;

bool dfs(int curElem, int needLen, int curPos)
{
	if (curElem == M) return true;
	if (needLen == 0) return dfs(curElem+1, res[curElem+1], 0);
	for ( int i =curPos; i < N && had[i] <= needLen; )
		if (used[i] == false)
		{
			used[i] = true;
			if (dfs(curElem, needLen-had[i], curPos+1)) return true;
			used[i] = false;
			i = next[i];
		}
		else i++;
	return false;
}

void Sort(int *arr, int N)
{
	for ( int i =0; i < N; i++)
		for ( int j =i+1; j < N; j++)
			if (arr[i] > arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
	//for ( int i =0; i < N; i++)
	//	cout << arr[i] << " " ;
	///cout << endl;
}

void getNext()
{
	Sort(had, N);
	had[N] = -1;
	for ( int i =0, j; i < N; i =j)
	{
		for ( j =i+1; had[j]==had[i]; j++);
		for ( ; i < j; i++) next[i] = j;
	}
	//for ( int i =0; i < N; i++)
	//	cout << elem[had[i]] << ": " << had[i] << "--->" << next[i] << endl;
}

void getSum()
{
	sum[N-1] = had[N-1];
	for ( int i =N-2; i >= 0; i--)
		sum[i] = sum[i+1]+had[i];
	//for ( int i =0; i < N; i++)
	//	cout << "sum:" << i << ": " << sum[i] << endl;
}

int main()
{
	int T, i, j, ncase =0;
	for ( scanf("%d", &T); T--; )
	{
		scanf("%d%d", &N, &M);
		for ( i =0; i < N; i++)
		{
			scanf("%s", in);
			t = in;
			for ( j =1; j <= 100; j++)
				if (elem[j] == t) { had[i] = j; break; }
			//cout << t << ": " << had[i] << endl;
		}

		for ( i =0; i < M; i++)
		{
			scanf("%s", in);
			t = in;
			for ( j =1; j <= 100; j++)
				if (elem[j] == t) { res[i] = j; break; }
			//cout << t << ": " << res[i] << endl;
		}
		getNext();
		Sort(res, M);
		memset(used, 0, sizeof(used));
		printf("Case #%d: %s\n", ++ncase, dfs(0, res[0], 0) ? "YES" : "NO");
	}return 0;
}