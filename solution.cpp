#include <bits/stdc++.h>
using namespace std;
vector<int> enemyPower;
vector<vector<vector<vector<vector<int>>>>> dp;
int initialPower, levelCount, skippedCount, rechargeCount;
bool recursionCheck(int remainingPower, int remainingSkip, int remainingRecharge, int currentCircleIndex, bool isPrevCircleSkipped)
{
    // Abhimanyu Crossed all circles
    if (currentCircleIndex == levelCount)
        return true;

    // If already solved this case
    if (dp[currentCircleIndex][remainingPower][remainingSkip][remainingRecharge][isPrevCircleSkipped] != -1)
        return dp[currentCircleIndex][remainingPower][remainingSkip][remainingRecharge][isPrevCircleSkipped];

    int curPowerNeed = enemyPower[currentCircleIndex];
    bool possibility = false;

    // Abhimanyu handled edurable enemies
    if (currentCircleIndex == 3 || currentCircleIndex == 7)
    {
        if (!isPrevCircleSkipped)
            curPowerNeed += enemyPower[currentCircleIndex - 1] / 2;
    }

    // Abhimanyu defeated enemies
    if (curPowerNeed <= remainingPower)
    {
        possibility |= recursionCheck(remainingPower - curPowerNeed, remainingSkip, remainingRecharge, currentCircleIndex + 1, false);
    }

    // Abhimanyu skipped the circle
    if (remainingSkip > 0)
    {
        possibility |= recursionCheck(remainingPower, remainingSkip - 1, remainingRecharge, currentCircleIndex + 1, true);
    }

    // Abhimanyu recharged and defeated enemies
    if (remainingRecharge > 0 && curPowerNeed <= initialPower)
    {
        possibility |= recursionCheck(initialPower - curPowerNeed, remainingSkip, remainingRecharge - 1, currentCircleIndex + 1, false);
    }

    // Store result and return
    return dp[currentCircleIndex][remainingPower][remainingSkip][remainingRecharge][isPrevCircleSkipped] = possibility;
}

bool canAbhimanyuCrossChakravyuha(vector<int> &k, int p, int a, int b)
{
    enemyPower = k;
    levelCount = k.size();
    initialPower = p;
    skippedCount = min(a, levelCount);
    rechargeCount = min(b, levelCount);

    dp = vector<vector<vector<vector<vector<int>>>>>(levelCount, vector<vector<vector<vector<int>>>>(initialPower + 1, vector<vector<vector<int>>>(skippedCount + 1, vector<vector<int>>(rechargeCount + 1, vector<int>(2, -1)))));

    return recursionCheck(initialPower, skippedCount, rechargeCount, 0, false);
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int p, a, b;
        cin >> p >> a >> b;

        vector<int> k(11);
        for (int i = 0; i < 11; i++)
        {
            cin >> k[i];
        }
        cout << (canAbhimanyuCrossChakravyuha(k, p, a, b) ? "Abhimanyu can cross the Chakravyuh : WON" : "Abhimanyu can not cross the Chakravyuh : LOST") << endl;
    }
    return 0;
}