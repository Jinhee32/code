#include <iostream>
#include <cstring>

using namespace std;

void int_to_hex(int N) {
	char str[255] = { 0 };
	int i = 0;
	int temp = N;
	char C='+';

	if (N < 0) { //음수면 - 저장
		C = '-';
		N = N * -1;
	}

	do {
		temp = N % 16; // 최소비트 
		N = N / 16; // 다음비트
		
		if (temp < 10)
			str[i++] = temp + '0'; // 0~9 저장
		else
			str[i++] = temp + 'W'; // a~f 저장


	} while (N > 0);

	if (C == '-') { //0x 표현
		str[i++] = 'x';
		str[i++] = '0';
		str[i++] = '-';
	}
	else {
		str[i++] = 'x';
		str[i++] = '0';
	}
	
	
	for (int j = (i-1); j >= 0; j--) { // 뒤에서부터 출력
		cout << str[j];
	}
}

int main() {
	int N;
	cin >> N;

	int_to_hex(N);


	return 0;
}