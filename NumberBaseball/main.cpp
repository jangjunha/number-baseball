#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main() {
	int numberOfDigits = 3;
	int answer, input;

	srand(time(NULL));
	do {
		answer = rand() % (int)pow(10, numberOfDigits);
	} while (!isValidNumber(answer, numberOfDigits));

	printf("Welcome to number baseball\n");

	while (true) {
		printf("> Guess number: ");
		scanf_s("%d", &input);
		if (!isValidNumber(input, numberOfDigits)) {
			printf("Wrong Number.\n");
			continue;
		}

		int strike = 0, ball = 0;
		for (int i = 0; i < numberOfDigits; i++) {
			for (int j = 0; j < numberOfDigits; j++) {
				int answerDigit = answer / (int)pow(10, i) % 10;
				int inputDigit = input / (int)pow(10, j) % 10;
				if (answerDigit == inputDigit) {
					if (i == j) {
						strike += 1;
					}
					else {
						ball -= 1;
					}
				}
			}
		}

		if (strike == 0 && ball == 0) {
			printf("  => OUT!\n");
		}
		else {
			printf("  => %dS %dB\n", strike, ball);

			if (strike == numberOfDigits) {
				printf("WINNER WINNER CHICKEN DINNER!\n");
				break;
			}
		}
	}

	system("pause");
	return 0;
}
