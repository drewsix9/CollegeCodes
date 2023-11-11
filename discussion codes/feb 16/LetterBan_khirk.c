#include <stdio.h>
#include <stdlib.h>

void oBan(int arr[], int size) {
  int isBanned, temp, digit;
  printf("O-banned : ");
  for (int i = 0; i < size; i++) {
    isBanned = 0;
    temp = arr[i];
    digit = 1;
    for (;;) {
      if (temp % 10 == 4 || (temp % 10 == 2 && digit != 2 && arr[i] != 12) || (temp % 10 == 1 && digit != 2) || arr[i] > 999 || arr[i] == 0) {
        isBanned++;
        break;
      }
      temp = temp / 10;
      if (temp == 0) {
        break;
      }
      digit++;
    }
    if (isBanned == 0) {
      printf("%d ", arr[i]);
    }
  }
}

void uBan(int arr[], int size) {
  printf("U-banned : ");
  int isBanned, digit, temp;
  for (int i = 0; i < size; i++) {
    isBanned = 0;
    digit = 1;
    temp = arr[i];
    for (;;) {
      if ((temp % 10 == 4 && digit != 2) || (temp % 10 != 0 && digit > 2 && digit < 7) || (temp % 10 != 0 && digit == 9)) {
        isBanned++;
        break;
      }
      temp = temp / 10;
      if (temp == 0) {
        break;
      }
      digit++;
    }
    if (isBanned == 0) {
      printf("%d ", arr[i]);
    }
  }
}
void eBan(int arr[], int size) {
  int isBanned = 0, temp, digit;
  printf("E-banned : ");
  for (int i = 0; i < size; i++) {
    isBanned = 0;
    temp = arr[i];
    digit = 1;
    for (;;) {
      if ((arr[i] / 10) % 10 == 2 || temp % 10 == 1 || (temp % 10 == 3 && digit != 2) || (temp % 10 == 5 && digit != 2) || temp % 10 == 7 || temp % 10 == 8 || temp % 10 == 9 || (temp % 10 != 0 && digit > 2 && digit < 4) || (temp % 10 != 0 && digit == 6)) {
        isBanned++;
        break;
      }
      temp = temp / 10;
      if (temp == 0) {
        break;
      }
      digit++;
    }
    if (isBanned == 0) {
      printf("%d ", arr[i]);
    }
  }
}

int main() {
  int exit = 0, option, num[999], max;
  while (exit == 0) {
    /*Empty array after every use*/
    for (int z = 0; num[z] != NULL; z++) {
      num[z] = NULL;
    }
    /*Print Option Menu*/
    printf("\n------|OPTIONS|------\n| [1] = O-Ban       |\n| [2] = U-Ban       |\n| [3] = E-Ban       |\n| [0] = Exit        |\n---------------------\nOption # : ");
    scanf("%d", &option);

    /*Main Logic*/
    if (option == 1) { /*O-Ban*/
      system("cls");
      printf("\n------| O - Ban |------\n");
      printf("Number of Inputs : ");
      scanf("%d", &max);
      printf("Inputs: ");
      for (int i = 0; i < max; i++) {
        scanf("%d", &num[i]);
      }
      oBan(num, max);
    } else if (option == 2) { /*U-Ban*/
      system("cls");
      printf("Number of Inputs : ");
      scanf("%d", &max);
      printf("Inputs: ");
      for (int i = 0; i < max; i++) {
        scanf("%d", &num[i]);
      }
      uBan(num, max);
    } else if (option == 3) { /*E-Ban*/
      system("cls");
      printf("Number of Inputs : ");
      scanf("%d", &max);
      printf("Inputs: ");
      for (int i = 0; i < max; i++) {
        scanf("%d", &num[i]);
      }
      eBan(num, max);
    } else if (option == 0) {
      printf("\n------|DONE!!!|------");
      exit = 1;
    }
  }
  return 0;
}