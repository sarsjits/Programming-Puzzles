class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size() > 1) {
            int minPrice = numeric_limits<int>::max();
            for(int i=0;i<prices.size();++i) {
                if(prices[i] < minPrice) {
                    minPrice = prices[i];
                } else if(prices[i] - minPrice > profit) {
                    profit = prices[i] - minPrice;
                }
            }
        }
        return profit;
    }
};
