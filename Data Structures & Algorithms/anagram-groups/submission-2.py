class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams_collection = {}

        for str in strs:
            a = "".join(sorted(str))

            if a in anagrams_collection: 
                anagrams_collection[a].append(str)
            else :
                anagrams_collection[a] = [str]

        all_values = list(anagrams_collection.values())
        return all_values
