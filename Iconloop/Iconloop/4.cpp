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
        if (S[i]>='0' && S[i] <= '9') { //배수 저장
            temp = temp * 10 + (S[i] - '0'); 
        }


        else if (S[i] >='a' && S[i] <= 'z') { //단순 문자인 경우 저장
            res.push_back(S[i]); 
        }


        else if (S[i] == '[') { // [ 만나면 스택에 저장
            temp_c.push(res);
            nums.push(temp);
            res = "";
            temp = 0;
        }


        else if (S[i] == ']') { // ] 만나면 pop
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