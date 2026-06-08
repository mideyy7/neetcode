class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
        if amount == 0: return amount
        sort in descending order to minimize coin count
        for each coin:
            while coin <= amount:
                amount -= coin
                count += 1
                if amount == 0: return count
        return -1
        */
        if (amount == 0) return 0;
        int count = 0;
        sort(coins.begin(), coins.end(), [](int a, int b) {
            return a > b;
        });
        for (int coin: coins) {
            while (coin <= amount) {
                amount -= coin;
                count += 1;
                if (amount == 0) return count;
            }
        }
        return -1;
        
    }
};
