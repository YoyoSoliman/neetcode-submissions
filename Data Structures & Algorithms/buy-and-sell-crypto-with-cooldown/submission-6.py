class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        rows = len(prices)
        cols = 2

        dp = [[-1 for _ in range(cols)] for _ in range(rows)]

        def dfs(index,hasCoin):
            if index >= len(prices):
                return 0
            
            if dp[index][hasCoin] != -1:
                return dp[index][hasCoin]
            

            #choice 1 sell the coin if we have it:
            choice1 = 0
            if (hasCoin == 1):
                choice1 = prices[index] + dfs(index+2,0)
            else :
                choice1 = (-1 * prices[index]) + dfs(index+1,1)
            

            #choice 2: keep gooing
            choice2 = dfs(index+1,hasCoin)

            dp[index][hasCoin] = max(choice1,choice2)

            return dp[index][hasCoin]
        
        return dfs(0,0)