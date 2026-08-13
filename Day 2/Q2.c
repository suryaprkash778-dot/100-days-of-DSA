/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0*/
int maxProfit(int* prices, int pricesSize) {
    int min=0,max=1,maxp=0;
    while(max<pricesSize){
        if(prices[max]>prices[min]){
            int currentp=prices[max]-prices[min];
            if(currentp>maxp){
                maxp=currentp;
            }
        }
        else{
            min=max;
        }
        max++;
    }
    return maxp;
}
  
