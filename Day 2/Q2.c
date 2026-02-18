/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0*/
int maxProfit(int* prices, int pricesSize) {
    int l = 0; // buy pointer
    int r = 1; // sell pointer
    int maxp = 0;

    while (r < pricesSize) {
        if (prices[r] > prices[l]) {
            int currentp = prices[r] - prices[l];
            if (currentp > maxp) {
                maxp = currentp;
            }
        } else {
            // found a cheaper buy price
            l = r;
        }
        r++;
    }
    return maxp;
}
