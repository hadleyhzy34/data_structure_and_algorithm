#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

int maxProfit(int *prices,int pricesSize){
    int dp_sell_out[pricesSize];
    int dp_sell_with[pricesSize];
    int dp_buy[pricesSize];
   
    //not bought any stock at current step 
    dp_sell_out[0] = 0;

    //bought stock at current step
    dp_sell_with[0] = 0;
    dp_buy[0] = -prices[0];

    for(int i=1;i<pricesSize;i++){
        dp_sell_out[i] = MAX(dp_sell_out[i-1],dp_sell_with[i-1]); 
        dp_sell_with[i] = dp_buy[i-1]+prices[i];
        dp_buy[i] = MAX(dp_buy[i-1], dp_sell_out[i-1]-prices[i]);
    }
    return MAX(dp_sell_out[pricesSize-1],dp_sell_with[pricesSize-1]);
}
