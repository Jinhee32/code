#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pick_peaks(vector<int> Peak) {
	int pos[100][2] = { 0 };
	char PM[100];
	int i = 0;
	int k = 0;

	
	for (i = 0; i < Peak.size() - 1 && Peak.size() > 0; i++) { // 다음 높이와 비교하여 +,-,= 저장
		if (Peak[i] < Peak[i + 1])
			PM[i] = '+';
		else if (Peak[i] == Peak[i + 1])
			PM[i] = '=';
		else if (Peak[i] > Peak[i + 1])
			PM[i] = '-';
	}

	for (int j = 1; j < i; j++) { // + -> - 되는 경우만 peak
		if (PM[j - 1] == '+' && PM[j] == '-') {
			pos[k][0] = j;
			pos[k][1] = Peak[j];
			k++;
		}
	}

	cout << "pos : "; //pos 출력
	for (int l = 0; l < k; l++) {
		cout << pos[l][0] << " ";
	}
	cout << endl;


	cout << "peaks : "; //peak 출력
	for (int l = 0; l < k; l++) {
		cout << pos[l][1] << " ";
	}
	cout <<endl;

}

int main() {
	vector<int> Peak;
	char PM[100];
	int N;
	int temp;

	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> temp;
		Peak.push_back(temp);
	}

	pick_peaks(Peak);

	return 0;
}