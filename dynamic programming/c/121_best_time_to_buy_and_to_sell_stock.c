int maxProfit(int *prices, int pricesSize){
    int dp_sell[pricesSize];
    int dp_buy[pricesSize];

    dp_sell[0]=0;
    dp_buy[0]=-prices[0];

    for(int i=0;i<pricesSize;i++){
        dp_sell[i] = dp_buy[i-1]+
    }


    return dp_sell[pricesSize-1];
}