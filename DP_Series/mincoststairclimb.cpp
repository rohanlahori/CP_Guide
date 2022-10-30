#include <iostream>
#include <math.h>
using namespace std;

int minCostClimbingStairs(int *cost, int n)
{
    int dp[n + 1];
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    dp[0] = cost[0];
    dp[1] = cost[1];

    // if(dp[n]!=-1){
    //     return dp[n];
    // }

    dp[n] = min(minCostClimbingStairs(cost, n - 1) + cost[n], minCostClimbingStairs(cost, n - 2) + cost[n]);

    return dp[n];
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int cost[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    printf("%d", minCostClimbingStairs(cost, n));
}
