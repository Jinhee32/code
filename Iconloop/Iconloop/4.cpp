#include <iostream>
#include <cstring>
#include <stack>

using namespace std;


string decodeString(string S) {
    stack<string> temp_c;
    stack<int> nums;
    string res;
    int temp = 0;

    for(int i =0 ; i<S.size();i++){
        if (S[i]>='0' && S[i] <= '9') { //��� ����
            temp = temp * 10 + (S[i] - '0'); 
        }


        else if (S[i] >='a' && S[i] <= 'z') { //�ܼ� ������ ��� ����
            res.push_back(S[i]); 
        }


        else if (S[i] == '[') { // [ ������ ���ÿ� ����
            temp_c.push(res);
            nums.push(temp);
            res = "";
            temp = 0;
        }


        else if (S[i] == ']') { // ] ������ pop
            string tmp = res;
            for (int i = 0; i < nums.top() - 1; ++i) {
                res += tmp;
            }
            res = temp_c.top() + res;
            temp_c.pop(); nums.pop();
        }
    }
    return res;
}


int main() {
	string S;
    string res;
	
	cin >> S;

	res = decodeString(S);

    cout << res;
	return 0;
}