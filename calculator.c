#include <stdio.h>

#define RATE 5.0          // Base rate per unit
#define TAX_PERCENT 10.0  // Tax percentage

// Function to calculate the electricity bill
float calculateBill(int units) {
    float total = 0;

    if (units <= 50) {
        total = units * RATE;
    } else if (units <= 100) {
        total = 50 * RATE + (units - 50) * (RATE * 1.5);
    } else if (units <= 200) {
        total = 50 * RATE + 50 * (RATE * 1.5) + (units - 100) * (RATE * 2);
    } else {
        total = 50 * RATE + 50 * (RATE * 1.5) + 100 * (RATE * 2) + (units - 200) * (RATE * 2.5);
    }

    // Adding tax
    total += total * (TAX_PERCENT / 100.0);

    return total;
}

int main() {
    int units;
    float totalBill;

    // Input and validation
    do {
        printf("Enter the number of units consumed: ");
        if (scanf("%d", &units) != 1 || units < 0) {
            printf("Invalid input! Please enter a valid number of units.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    } while (1);

    // Calculate bill
    totalBill = calculateBill(units);

    // Display result
    printf("\nElectricity Bill Summary\n");
    printf("------------------------\n");
    printf("Units Consumed: %d\n", units);
    printf("Total Bill (incl. %.0f%% tax): ₹%.2f\n", TAX_PERCENT, totalBill);

    return 0;
}
