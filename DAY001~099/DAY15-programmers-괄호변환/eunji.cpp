#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string u) {
	//올바른 괄호문자열인지 체크해줍니다.
	int count = 0;
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') {
			count++;
		}
		else {
			count--;
			if (count < 0) {
				return false;
			}
		}
	}
	return true;
}

string solution(string p) {
	string u;
	string v;

	//빈문자일 경우 반환
	if (p.empty()) {
		return p;
	}
	else {
		//균형잡힌 괄호 문자열 u,v로 분리
		int left = 0;
		int right = 0;
		for (int i = 0; i < p.size(); i++) {


			if (p[i] == '(') {
				left++;;
			}
			else {
				right++;
			}

			//left right갯수가 같을때 균형잡힌 문자열이므로 그기까지가 u, 나머지가 v
			if (left != 0 && right != 0 && left == right) {
				u = p.substr(0, i + 1);
				v = p.substr(i + 1, p.size() - (i + 1));
				break;
			}
		}
		//u가 올바른 괄호문자열 이든 아니든 v 재귀는 둘다 필요하기 때문에 앞에 넣음.
		v = solution(v);

		//u가 올바른 괄호 문자열일때,
		if (check(u)) {
			p = u + v;
		}
		//u가 올바른 괄호 문자열이 아닐때
		else {
			string tmp;
			for (int i = 0; i < u.size(); i++) {
				if (i == 0 || i == u.size() - 1) {
					continue;
				}
				else {
					if (u[i] == '(') {
						tmp.push_back(')');
					}
					else {
						tmp.push_back('(');
					}
				}
			}
			//4번 설명대로 쭉 행함
			v = '(' + v + ')';
			p = v + tmp;
		}
	}
	return p;
}
