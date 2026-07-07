class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        new = nums
        return_list = []
        number_and_instances = {}

        for num in new:
            if num in number_and_instances:
                number_and_instances[num] = number_and_instances[num] + 1
            else:
                number_and_instances[num] = 1
            

        greatestOC = 0
        for number in number_and_instances:
            if number_and_instances[number] >= greatestOC:
                greatestOC = number_and_instances[number]
        
        while len(return_list) != k:
            for number in number_and_instances:
                if number_and_instances[number] == greatestOC:
                    return_list.append(number)
            greatestOC = greatestOC - 1

        return return_list