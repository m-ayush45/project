
#include <stdio.h>

int main() {
    int units;
    float rate, total;

    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    // Define your electricity rate per unit
    rate = 5.0; // Change this value according to your electricity provider's rate

    if (units <= 50) {
        total = units * rate;
    } else if (units <= 100) {
        total = 50 * rate + (units - 50) * (rate * 1.5);
    } else if (units <= 200) {
        total = 50 * rate + 50 * (rate * 1.5) + (units - 100) * (rate * 2);
    } else {
        total = 50 * rate + 50 * (rate * 1.5) + 100 * (rate * 2) + (units - 200) * (rate * 2.5);
    }

    // Add additional charges or taxes if applicable
    total = total + (total * 0.1); // Example: 10% tax

    printf("Electricity Bill: %.2f\n", total);

    return 0;
}