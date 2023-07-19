class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        """brute force solution O(n^2)"""
        for start_index, elem1 in enumerate(nums):
            for index, elem2 in enumerate(nums[start_index + 1:]):
                if elem1 + elem2 == target:
                    return [start_index, start_index + index + 1]
        return [-1, -1]
    
    def twoSum1(self, nums: list[int], target: int) -> list[int]:
        """better solution O(n)"""
        storedValues = {} # val -> index
        for i, n in enumerate(nums):
            to_look_for = target - n
            if to_look_for in storedValues:
                return [i, storedValues[to_look_for]]
            storedValues[n] = i

def main():
    s = Solution()
    nums = [3, 2, 4]
    target = 6
    print (s.twoSum1(nums, target))

if __name__ == "__main__":
    main()