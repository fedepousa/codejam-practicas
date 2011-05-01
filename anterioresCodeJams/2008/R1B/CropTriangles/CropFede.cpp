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

int main(){
	ifstream entrada("A-large.in");
    ofstream salida("A-large.out");
	int Casos;
	entrada >> Casos;
	for(int caso=1;caso<=Casos;++caso){
		long long int res = 0;
		long long int n, A, B, C, D, x0, y0, M, X, Y;
		long long int mod[3][3];
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				mod[i][j] = 0;
			}
		}
		entrada >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		X = x0;
		Y = y0;
		mod[X%3][Y%3]++;
		for(int i=0;i<n-1;i++){
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			mod[X%3][Y%3]++;
		}
		
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				if(mod[i][j] > 2){
					res += (mod[i][j] * (mod[i][j]-1) * (mod[i][j]-2)) / 6;
				}
			}
		}
		
		
		
		
		res += mod[0][0] * mod[1][1] * mod[2][2];
		res += mod[0][0] * mod[1][2] * mod[2][1];
		res += mod[0][0] * mod[1][0] * mod[2][0];
		res += mod[0][1] * mod[1][0] * mod[2][2];
		res += mod[0][1] * mod[1][2] * mod[2][0];
		res += mod[0][1] * mod[1][1] * mod[2][1];
		res += mod[0][2] * mod[1][2] * mod[2][2];
		res += mod[0][2] * mod[1][0] * mod[2][1];
		res += mod[0][2] * mod[1][1] * mod[2][0];
		res += mod[0][0] * mod[0][1] * mod[0][2];
		res += mod[1][0] * mod[1][1] * mod[1][2];
		res += mod[2][0] * mod[2][1] * mod[2][2];
		
		salida << "Case #" << caso << ": " << res << endl;
	}	
	return 0;
}
