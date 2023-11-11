#include <stdio.h>

float CalculateTotalTaxiFare(int minutes, int Kilometers);

int main(){
    // Input for minutes and kilometers
    int Minutes, kilometers;
    printf("Estimated Time of Travel in Minutes:");
    scanf("%d", &Minutes);
    printf("Estimated Distance of Travel in Kilometers:");
    scanf("%d",&kilometers);
    CalculateTotalTaxiFare(Minutes,kilometers);
    
}
//total fare calculation.
float CalculateTotalTaxiFare(int minutes, int Kilometers){
    float Fare;
    Fare = 40 + (2*minutes)+(13.50*Kilometers);
    printf("Your Total Taxi Fare is : %.2f",Fare);
    return 0;
}
