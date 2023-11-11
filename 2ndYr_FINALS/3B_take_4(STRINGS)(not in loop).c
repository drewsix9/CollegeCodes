#include <stdio.h>
#include <math.h>

int main() {
	char str[20];
	int whole_num, decimal_num, reversed_decimal = 0;

	printf("Enter float value: ");
	scanf("%s", str);

	int i = 0, decimal_point_pos = -1, decimal_digits = 0;
	while (str[i] != '\0') {
		if (str[i] == '.') {
			decimal_point_pos = i;
		}
		i++;
	}

	if (decimal_point_pos == -1) {
		sscanf(str, "%d", &whole_num);
		decimal_num = 0;
		decimal_digits = 0;
	} else {
		str[decimal_point_pos] = '\0';
		sscanf(str, "%d", &whole_num);
		sscanf(&str[decimal_point_pos + 1], "%d", &decimal_num);
		decimal_digits = i - decimal_point_pos - 1;
	}

	int temp = decimal_num;
	while (temp > 0) {
		int last_digit = temp % 10;
		reversed_decimal = reversed_decimal * 10 + last_digit;
		temp /= 10;
	}

	float final = whole_num + (float)reversed_decimal / pow(10, decimal_digits);
	printf("\n\nfinal = %f", final);
	return 0;
}
