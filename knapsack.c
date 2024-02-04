#include <stdio.h>

void selectItems(float weights[], float values[], char *items[], int numItems);

int main() {
    char *items[] = {"A", "B", "C", "D", "E"};
    float values[] = {35, 60, 100, 120, 130};
    float weights[] = {2, 5, 6, 9, 10};
    int numItems = 5;

    // Call the function to select items
    selectItems(weights, values, items, numItems);

    return 0;
}

void selectItems(float weights[], float values[], char *items[], int numItems) {
    float W = 20;
    int i, w;
    float K[numItems + 1][W + 1];

    // Initialize the K matrix
    for (i = 0; i <= numItems; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = fmax(values[i - 1] + K[i - 1][w - (int)weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Find the items included in the knapsack
    int resultWeight = W;
    int resultValue = K[numItems][(int)W];
    printf("Maximum profit: %d\n", (int)resultValue);

    printf("Items that give the maximum profit: [");
    for (i = numItems; i > 0 && resultValue > 0; i--) {
        if (resultValue != K[i - 1][resultWeight]) {
            printf("%s, ", items[i - 1]);
            resultValue -= values[i - 1];
            resultWeight -= weights[i - 1];
        }
    }
    printf("]\n");
}
