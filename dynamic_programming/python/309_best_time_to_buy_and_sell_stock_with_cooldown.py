#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

class solution:
    def maxProfit(prices:list[int])->int:
        pricesSize = len(prices)
        
        dp_sell_out = []
        dp_sell_with = []
        dp_buy = []
        
        #current action is not selling, next step could be buying
        dp_sell_out.append(0)
        # current action is selling, next step must be cooldown
        dp_sell_with.append(0)

        # make sure last action is buying
        dp_buy.append(-prices[0])

        for i in range(1,pricesSize):
            dp_sell_out.append(max(dp_sell_out[i-1],dp_sell_with[i-1]))
            dp_sell_with.append(dp_buy[i-1]+prices[i])
            dp_buy.append(max(dp_buy[i-1],dp_sell_out[i-1]-prices[i]))

        return max(dp_sell_out[pricesSize-1],dp_sell_with[pricesSize-1])
