#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	ifstream entrada("A-large.in");
	ofstream salida("A-large.out");
	
	int Casos;
	entrada >> Casos;
	for(int caso=1;caso<=Casos;++caso){
		int P, K, L;
		entrada >> P >> K >> L;
		vector<int> freq;
		for(int i=0;i<L;++i){
			int aux;
			entrada >> aux;
			freq.push_back(aux);
		}
		long long int res = 0;
		sort(freq.begin(),freq.end());
		int actual = 1;
		int used = 0;
		for(int i=L-1;i>=0;i--){
			res += freq[i]*actual;
			used++;
			if(used==K){
				actual++;
				used = 0;
			}
		}
		
	
		salida << "Case #" << caso << ": " << res << endl;
	}
	return 0;
}
