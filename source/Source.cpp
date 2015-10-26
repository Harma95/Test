#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(void){
	string tocke;
	int N, h, w, n1, n2, br_krev, visina, sirina, br = 0, kreveti[10][10] = {0}, br1 = 0,ker,zastavica=1;
	cin >> N;
	cin >> w;
	cin >> h;
	n1 = N / h;
	n2 = N / w;
	br_krev = n1*n2;
	visina = (N / h)*h;
	sirina = (N / w)*w;
	//fflush(stdin);
	ker = w;

	for (int i = 0; i < N; i++){
		getline(cin, tocke);
		if (i%h == 0)
			br1++;
		for (int j = 0; j < sirina; j++){
			if (j%w == 0)
				br++;
			if ((tocke[j] == 'D' || tocke[j] == '#')&&i<visina)
				kreveti[br1][br]++;
		}
		br = 0;
	}
//	for (int i = 0; i < 10; i++){
//		for (int j = 0; j < 10; j++){
//			cout << kreveti[i][j];
//		}
//		cout << endl;
//	}
	for (int i = 0; i < visina; i++){
		for (int j = 0; j < sirina; j++){
			ker--;
			if (kreveti[i][j] != 0 && zastavica == 1){
				br_krev--;
				zastavica = 0;
			}
			if (ker == 0){
				zastavica = 1;
				ker = w;
			}
		}
	}
	cout << br_krev;
	return 0;
}