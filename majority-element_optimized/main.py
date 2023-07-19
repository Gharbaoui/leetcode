class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stored = {}

        for elm in nums:
            if elm not in stored:
                stored[elm] = 1
            else:
                stored[elm] = stored[elm] + 1
            if stored[elm] > len(nums) / 2:
                return elm
        
def main():
    s = Solution()
    print(s.majorityElement([2,2,1,1,1,2,2]))

if __name__ == "__main__":
    main()