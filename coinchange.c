#include <stdio.h>
#include <limits.h>

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the Coin Change problem
int coinChange(int coins[], int n, int amount) {
    // Create a table to store the minimum number of coins for each amount
    int dp[amount + 1];

    // Initialize all values in dp[] as maximum
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Base case
    dp[0] = 0;

    // Compute the minimum number of coins for all amounts from 1 to amount
    for (int i = 1; i <= amount; i++) {
        // Check each coin denomination
        for (int j = 0; j < n; j++) {
            // If the current coin denomination is less than or equal to the current amount
            if (coins[j] <= i) {
                // Calculate the minimum number of coins needed
                // by taking the minimum of the current value and (current value - coin value) + 1
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Return the minimum number of coins needed for the target amount
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};   // Coin denominations
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;           // Target amount

    int result = coinChange(coins, n, amount);
    printf("Minimum number of coins needed = %d\n", result);

    return 0;
}
