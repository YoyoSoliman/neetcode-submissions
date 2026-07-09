class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        r = len(board[0])
        c = len(board)

        def isRowsValid():
            for i in range(c):
                rep = set()
                for k in range(r):
                    if board[i][k]!= '.':
                        if board[i][k] in rep:
                            return False
                        else:
                            rep.add(board[i][k])
            return True

                    

        def isColsValid():
            for i in range(r):
                rep = set()
                for k in range(c):
                    if board[k][i]!= '.':
                        if board[k][i] in rep:
                            return False
                        else:
                            rep.add(board[k][i])
            return True

        def is3x3Valid():
            for i in range (0,9,3):
                for k in range(0,9,3):
                    rep=set()
                    for n in range(3):
                        for l in range(3):
                            if board[i+n][k+l] != '.':
                                if board[i+n][k+l] in rep:
                                    return False
                                else:
                                    rep.add(board[i+n][k+l])
                
            return True
                    



        
        if isRowsValid() and isColsValid() and is3x3Valid():
            return True
        else:
            return False