#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>

#define forn(i,n) 	 for(int i=0; i<n; i++)
#define fornd(i,n) 	 for(int i=n; i>0; i--)
#define fornx(i,x,n) for(int i=x; i<n; i++)
#define forall(it,X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) 
{
    return a.first < b.first;
}

int main(int argc, char** argv)
{
	ifstream entrada("A-large.in");
	ofstream salida("A-large.out");
	
	int casos;
	entrada >> casos;
	
	forn(i, casos)
	{
		int n;		
		entrada >> n;
		
		vector<pair<int, int> > ventanas;
		
		forn(j, n)
		{
			int a, b;
			entrada >> a >> b;
			ventanas.push_back(make_pair(a, b));
		}		
			
		/* Ordenar por la primera componente. */
		sort(ventanas.begin(), ventanas.end(), comp);
		
		long long int res = 0;
		
		/* Se corta el cable si la segunda componente del otro
		 * es más chica que la nuestra. */
		forn(j, n)
		{
			fornx(k, j+1, n)
			{
				if (ventanas[k].second < ventanas[j].second)
					res++;
			}
		}
		
		salida << "Case #" << i+1 << ": " << res << endl;
	}
	
	return 0;	
}
