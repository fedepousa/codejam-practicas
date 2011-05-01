#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

long long int ali2dec(string ori, string alfa1){
	long long int res = 0;
	for(int i=0;i<ori.size();++i){
		int pos;
		for(int j=0;j<alfa1.size();++j){
			if(alfa1[j] == ori[i]){
				pos = j;
				break;
			}
		}
		int aux = pos;
		for(int j=1;j<=ori.size()-i-1;++j){
			aux *= alfa1.size();
		}
		res += aux;
	}
	return res;
}

string dec2ali(long long int inter, string alfa2){
	string res;
	string aux;
	while(inter){
		int mod = inter % (alfa2.size());
		inter /= alfa2.size();
		aux.push_back(alfa2[mod]);
	}
	for(int i=aux.size()-1;i>=0;i--){
		res.push_back(aux[i]);
	}
	return res;
}

int main(){
	
	ifstream entrada("A-large-practice.in");
	ofstream salida("A-large-practice.out");
	
	int Casos;
	entrada >> Casos;
	
	//cout << ali2dec("Foo", "oF8") << endl;
	//cout << dec2ali(9, "oF8") << endl;
	
	for(int caso=1;caso<=Casos;++caso){
		string ori, alfa1, alfa2;
		entrada >> ori >> alfa1 >> alfa2;
		long long int inter = ali2dec(ori, alfa1);
		string res = dec2ali(inter, alfa2);
		salida << "Case #" << caso << ": " << res << endl;
	}
	
	return 0;
}
