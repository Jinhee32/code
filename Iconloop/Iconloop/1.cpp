#include <iostream>
#include <cstring>

using namespace std;

void int_to_hex(int N) {
	char str[255] = { 0 };
	int i = 0;
	int temp = N;
	char C='+';

	if (N < 0) { //������ - ����
		C = '-';
		N = N * -1;
	}

	do {
		temp = N % 16; // �ּҺ�Ʈ 
		N = N / 16; // ������Ʈ
		
		if (temp < 10)
			str[i++] = temp + '0'; // 0~9 ����
		else
			str[i++] = temp + 'W'; // a~f ����


	} while (N > 0);

	if (C == '-') { //0x ǥ��
		str[i++] = 'x';
		str[i++] = '0';
		str[i++] = '-';
	}
	else {
		str[i++] = 'x';
		str[i++] = '0';
	}
	
	
	for (int j = (i-1); j >= 0; j--) { // �ڿ������� ���
		cout << str[j];
	}
}

int main() {
	int N;
	cin >> N;

	int_to_hex(N);


	return 0;
}