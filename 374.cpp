/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		long long hi = n, lo = 1, mid = (hi + lo) / 2;
		for(int ret; ret = guess(mid); mid = (hi + lo) / 2)
			if(ret == -1)
				hi = mid - 1;
			else
				lo = mid + 1;
		return mid;
	}
};