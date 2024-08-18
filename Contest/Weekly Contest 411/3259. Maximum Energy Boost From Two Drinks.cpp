
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */
class Solution {
public:
    long long maxBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB, int i, int mode, vector<vector<long long>>& dp, int& n){
        if(i >= n) return 0;
        if(dp[i][mode] != -1) return dp[i][mode];
        long long noChangeMode = maxBoost(energyDrinkA, energyDrinkB, i+1, mode, dp, n);
        noChangeMode += mode == 0 ? energyDrinkA[i] : energyDrinkB[i];
        long long changeMode = maxBoost(energyDrinkA, energyDrinkB, i+2, !mode, dp, n);
        changeMode += mode == 0 ? energyDrinkA[i] : energyDrinkB[i];
        
        return dp[i][mode] = max(noChangeMode, changeMode);
    }
    
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return max(maxBoost(energyDrinkA, energyDrinkB, 0, 0, dp, n), maxBoost(energyDrinkA, energyDrinkB, 0, 1, dp, n));
    }
};
   /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/
    */
