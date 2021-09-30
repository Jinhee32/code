#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool tickets(vector<int> list,int N) {
	int cnt[3] = { 0,0,0 }; //25,50,100 ī��Ʈ
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
		
		if (cnt[0] < 0 || cnt[1] < 0 || cnt[2] < 0) { // 25,50,100�ϳ��� �����Ǹ� ����
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

	cin >> N; // ��� �մ� ��

	for (int i = 0; i < N; i++) { // �մ� �� ��ŭ �Է�
		cin >> temp;
		list.push_back(temp);
	}

	T = tickets(list, N);
	if (T == true) {
		cout << "true" << endl;
	}
	else
		cout << "false" << endl; //��� ���

	return 0;
}