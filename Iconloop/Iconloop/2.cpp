#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool tickets(vector<int> list,int N) {
	int cnt[3] = { 0,0,0 }; //25,50,100 카운트
	bool flag = true;
	int i = 0;

	do {
		if (list[i] == 25) {
			cnt[0]++;
		}
		else if (list[i] == 50) {
			cnt[1]++;
			cnt[0]--;
		}
		else if (list[i] == 100) {
			cnt[2]++;
			if (cnt[1] > 0 && cnt[0] > 0) {
				cnt[1]--;
				cnt[0]--;
			}
			else
				cnt[0] = cnt[0] - 3;
		}
		
		if (cnt[0] < 0 || cnt[1] < 0 || cnt[2] < 0) { // 25,50,100하나라도 음수되면 종료
			flag = false;
			break;
		}
		i++;
		N--;
	} while (N>0);

	return flag;
}

int main() {
	vector<int> list;
	int temp;
	int N;
	bool T;

	cin >> N; // 대기 손님 수

	for (int i = 0; i < N; i++) { // 손님 수 만큼 입력
		cin >> temp;
		list.push_back(temp);
	}

	T = tickets(list, N);
	if (T == true) {
		cout << "true" << endl;
	}
	else
		cout << "false" << endl; //결과 출력

	return 0;
}