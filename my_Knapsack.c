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
        { // Initialize first row and column with zeros
            if (i == 0 || w == 0)
                K[i][w] = 0;
            // Fill the table based on the values and weights of items
            else if (weights[i - 1] <= w)
            {
                int newValue = values[i - 1] + K[i - 1][w - weights[i - 1]];
                if (newValue > K[i - 1][w])
                    K[i][w] = newValue;
                else
                    K[i][w] = K[i - 1][w];
            }
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

void my_knapsack(int values[], int weights[], int result[], char items[])
{

    int max_profit = knapSack(weights, values, result);

    printf("Maximum profit: %d\n", max_profit);

    printf("Selected items: ");
    int last_selected = -1; // Index of the last selected item
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (result[i])
        {
            if (last_selected != -1)
            {
                printf(" ");
            }
            printf("%c", items[i]); // Adjust for 0-indexed array and char item names
            last_selected = i;
        }
    }
}

int main()
{
    int weights[MAX_ITEMS], values[MAX_ITEMS], result[MAX_ITEMS] = {0};
    char items[MAX_ITEMS];

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        char item;
        scanf(" %c %d %d", &items[i], &values[i], &weights[i]);
    }

    my_knapsack(values, weights, result, items);

    return 0;
}
