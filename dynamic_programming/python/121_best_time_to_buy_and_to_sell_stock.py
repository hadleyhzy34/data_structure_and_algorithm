class solution:
    def maxProfit(self,prices:list[int])->int:
        min_price = prices[0]
        max_price = 0
        
        for i in range(len(prices)):
            if prices[i] < min_price:
                min_price = prices[i]
            elif prices[i] - min_price > max_price:
                max_price = prices[i] - min_price

        return max_price
