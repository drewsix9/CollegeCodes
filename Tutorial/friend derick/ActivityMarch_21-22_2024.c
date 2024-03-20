#include <stdio.h>

float getPrice(int n) {
  float price[] = {56.79, 105.69, 93.49, 155.99, 87.49, 73.99};
  return price[n];
}

void printPrice() {
  printf("%-4s %-22s %s\n", "No.", "#######################", "Price");
  printf("%-4s %-22s %s\n", "====", "=======================", "=====");
  for (int i = 0; i < 6; i++) {
    printf("%-4s %-22s %.2f\n", "1.", "City ------------------", getPrice(i));
  }
}

float calculatePrice(float price, int n) {
  return price * n;
}

int main() {
  int choice;
  int n;
  while (1) {
    printPrice();
    printf("Enter the city number: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 6) {
      printf("\n[WARNING] Invalid choice\n\n");
      continue;
    }
    printf("Enter how many tickets: ");
    scanf("%d", &n);
    float price = calculatePrice(getPrice(choice - 1), n);
    printf("\nTotal price: PHP%.2f\n\n", price);
  }
}