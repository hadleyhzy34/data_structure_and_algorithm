#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#include <iostream>
#include <vector>
using namespace std;


//multi number of transactions
int maxProfit_v2(int* prices, int pricesSize){
    int dp_sell[pricesSize];
    int dp_buy[pricesSize];

    //max profit that last action is buying
    dp_sell[0]=0;
    //max profit that last action is selling
    dp_buy[0]=-prices[0];

    for(int i=1;i<pricesSize;i++){
        //max profit is either doing nothing or sell today
        dp_sell[i] = MAX(dp_sell[i-1], prices[i]+dp_buy[i-1]);
        //max profit is either doing nothing or buy during today
        dp_buy[i] = MAX(dp_buy[i-1], dp_sell[i-1]-prices[i]);
        printf("current price is: %d, current sell is %d, current buy is: %d\n", prices[i], dp_sell[i], dp_buy[i]);
    }
    return dp_sell[pricesSize-1];
}


/*------------------------------------------------------------------------------------------------------------------*/

//dp algorithm
int maxProfit(int* prices, int pricesSize){
    int dp_sell[pricesSize];
    int dp_buy[pricesSize];

    //max profit that stock is sold yet or not bought yet
    dp_sell[0]=0;
    //max profit that stock is already bought while stock not sold yet
    dp_buy[0]=-prices[0];

    for(int i=1;i<pricesSize;i++){
        //max profit is either doing nothing or sell today
        dp_sell[i] = MAX(dp_sell[i-1], prices[i]+dp_buy[i-1]);
        //max profit is either doing nothing or buy during today
        dp_buy[i] = MAX(-prices[i], dp_buy[i-1]);
        printf("current price is: %d, current sell is %d, current buy is: %d\n", prices[i], dp_sell[i], dp_buy[i]);
    }
    return dp_sell[pricesSize-1];
}

/*---------------------------------------------------------------------------------------------------------------*/

//two pointers
class solution{
public:
    int maxProfit(vector<int> prices){
        int min_price=prices[0];
        int max_price=0;

        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<min_price){
                min_price=prices[i];
            }else if (prices[i]-min_price>max_price)
            {
                max_price = prices[i]-min_price;
            }
        }
        return max_price;
    }
};