class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        rows = len(coins)
        cols = amount + 1

        dp = [[-1 for _ in range(cols)] for _ in range(rows)]

        def dfs(index,currAmount):
            if currAmount == amount:
                return 1
            
            if currAmount > amount or index >= len(coins):
                return 0
            
            if dp[index][currAmount] != -1:
                return dp[index][currAmount]
            
            #choice 1: take one coin and stay
            choice1 = dfs(index,currAmount + coins[index])

            choice2 = dfs(index+1,currAmount)

            dp[index][currAmount] = choice1 + choice2

            return dp[index][currAmount]
        
        return dfs(0,0)
