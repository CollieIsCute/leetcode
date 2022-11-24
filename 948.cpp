#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
public:
	int bagOfTokensScore(vector<int>& tokens, int power = 0) {
		// 兩個指標把 sort 過的 vector 切成三個部分，最左邊最小的是 face up,
		// 中間待處理（或者不動），右邊是要 face down 換 power.
		int score = 0, face_up = 0, face_down = tokens.size() - 1;
		auto use_power = [&score, &tokens, &power, &face_up,
						  &face_down]() -> void {
			while(face_up <= face_down && power >= tokens.at(face_up)) {
				power -= tokens.at(face_up);
				face_up++;
				score++;
			}
		};
		auto get_power = [&score, &tokens, &power, &face_up,
						  &face_down]() -> bool {
			if(face_down <= face_up || score <= 0)
				return false;
			power += tokens.at(face_down);
			face_down--;
			score--;
			return true;
		};

		std::sort(tokens.begin(), tokens.end());
		use_power();
		while(get_power())
			use_power();
		return score;
	}
};
