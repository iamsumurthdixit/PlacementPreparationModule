class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        const int nax = 1e7 + 2; 
        vector<int> prev(amount + 1, nax);
        
        for(int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] == 0) {
                prev[amt] = amt / coins[0]; 
            }
        }
        for(int ind = 1; ind < n; ind++) {
            for(int amt = 0; amt <= amount; amt++) {
                int notTake = prev[amt];
                int take = nax; 
                if(amt >= coins[ind]) {
                    take = 1 + prev[amt - coins[ind]]; 
                }
                prev[amt] = min(take, notTake); 
            }
        }
        return prev[amount] < nax ? prev[amount] : -1; 
    }
};
