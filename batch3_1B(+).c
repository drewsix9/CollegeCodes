// Ctrl + D - Deletes the line of code where the pointer is.
// Ctrl + E - Duplicates the line of code.
// Ctrl + . - Turns the line of code into a comment.
// Ctrl + . - Turns the line of comment into a code.
// Ctrl + Shift + A - Format alignment.
// Ctrl + M - Splitscreen.
// Ctrl + Tab - Switch to a different window.
// Ctrl + G - go to line n.
// Ctrl + I - Incremental Search.
// Alt + up/down - to move the line of code up or down
//--------------------------------

/*enter pila ka inputs then
if sa imu inputs naay number na mo repeat itself eh print nija
output
enter inputs: 3
num1: 56
num2: 55.34
55.34
num3: 321.862
321.862
mao rgud na
*/

#include <stdio.h>

int main(void) {
  // Read the number of float values to be entered
  int n;
  printf("Enter the number of float values: ");
  scanf("%d", &n);

  // Read each float value and check for repeating digits
  for (int i = 1; i <= n; i++) {
    // Read the float value
    float value;
    printf("Enter float value %d: ", i);
    scanf("%f", &value);

    // Convert the float value to an integer by multiplying it by a power of 10
    int int_value = (int)(value * 1000000);

    // Check if any non-zero digit appears more than once
    int digits[10] = {0};
    int repeating = 0;
    while (int_value > 0) {
      int digit = int_value % 10;
      if (digit == 0) {
        int_value /= 10;
        continue;
      }
      digits[digit]++;
      if (digits[digit] > 1) {
        repeating = 1;
        break;
      }
      int_value /= 10;
    }

    // If a repeating digit was found, print the float value
    if (repeating) {
      printf("%.6f has a repeating digit\n", value);
    }
  }

  return 0;
}
