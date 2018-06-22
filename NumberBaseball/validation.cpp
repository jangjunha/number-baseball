#include <math.h>

bool isValidNumber(int number, int numberOfDigits) {
	bool chk[10] = { 0, };
	for (int i = 0; i < numberOfDigits; i++) {
		int digit = number / (int)pow(10, i) % 10;
		if (chk[digit]) {
			return false;
		}
		chk[digit] = true;
	}
	return true;
}
