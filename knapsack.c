#include <stdio.h>

#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int knapSack(int weights[], int values[], int select_bool[])
{
    int i, w;
    int K[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= MAX_ITEMS; i++)
    {
        for (w = 0; w <= MAX_WEIGHT; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = (values[i - 1] + K[i - 1][w - weights[i - 1]] > K[i - 1][w]) ? values[i - 1] + K[i - 1][w - weights[i - 1]] : K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Get the items selected
    int max_profit = K[MAX_ITEMS][MAX_WEIGHT];
    int temp = K[MAX_ITEMS][MAX_WEIGHT];
    w = MAX_WEIGHT;

    for (i = MAX_ITEMS; i > 0 && max_profit > 0; i--)
    {
        if (max_profit == K[i - 1][w])
            continue;
        else
        {
            select_bool[i - 1] = 1;
            max_profit -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return temp;
}

void my_knapsack(int weights[], int values[])
{
    int select_bool[MAX_ITEMS] = {0};
    int max_profit = knapSack(weights, values, select_bool);

    printf("Maximum profit: %d\n", max_profit);

    printf("Items that give the maximum profit: ");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (select_bool[i])
            printf("%c ", 'A' + i); // Adjust for 0-indexed array and char item names
    }
    printf("\n");
}

int main()
{
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter weights and values for each item:\n");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        printf("Enter weight for item %c: ", 'A' + i); // Using 'A' + i to print char item names
        scanf("%d", &weights[i]);
        printf("Enter value for item %c: ", 'A' + i);
        scanf("%d", &values[i]);
    }

    my_knapsack(weights, values);

    return 0;
}
