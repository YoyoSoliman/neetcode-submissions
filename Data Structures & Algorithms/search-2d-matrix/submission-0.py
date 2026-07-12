class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        l=0
        h=len(matrix)-1#2

        mid_1 = 0

        while l <= h:

            mid_1= l + int((h-l)/2)
            if matrix[mid_1][0] <= target and matrix[mid_1][len(matrix[0])-1] >= target:
                break
            if matrix[mid_1][0] < target:
                l = mid_1 + 1
            else:
                h = mid_1 - 1

        
        l=0
        h=len(matrix[0])-1
        mid_2=0

        while l <=h :
            mid_2 = l + int(h-l/2)
            if matrix[mid_1][mid_2] == target:
                return True
            
            if matrix[mid_1][mid_2] < target:
                l = mid_2 + 1
            else:
                h = mid_2-1
        
            
        return False


