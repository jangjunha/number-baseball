#include <math.h>
#include "score.h"

Result getScore(int input, int answer, int numberOfDigits) {
	Result res;
	for (int i = 0; i < numberOfDigits; i++) {
		for (int j = 0; j < numberOfDigits; j++) {
			int answerDigit = answer / (int)pow(10, i) % 10;
			int inputDigit = input / (int)pow(10, j) % 10;
			if (answerDigit == inputDigit) {
				if (i == j) {
					res.strike += 1;
				}
				else {
					res.ball += 1;
				}
			}
		}
	}
	return res;
}
