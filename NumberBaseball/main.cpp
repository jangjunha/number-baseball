#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "validation.h"
#include "score.h"

int main() {
	int numberOfDigits = 3;
	int answer, input;

	srand(time(NULL));
	do {
		answer = rand() % (int)pow(10, numberOfDigits);
	} while (!isValidNumber(answer, numberOfDigits));

	printf("Bulls and Cows !\n");

	while (true) {
		printf("> Guess number: ");
		scanf_s("%d", &input);
		if (input == -1) {
			return 0;
		}
		if (!isValidNumber(input, numberOfDigits)) {
			printf("Wrong Number.\n");
			continue;
		}

		Result res = getScore(input, answer, numberOfDigits);

		if (res.strike == 0 && res.ball == 0) {
			printf("  => OUT!\n");
		}
		else {
			printf("  => %dS %dB\n", res.strike, res.ball);

			if (res.strike == numberOfDigits) {
				printf("Game Over!\nWINNER WINNER CHICKEN DINNER!\n");
				break;
			}
		}
	}

	system("pause");
	return 0;
}
