class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if (len(nums) == 1):
            return 1
        prvIndex = 0
        currentIndex = 0
        nextUnique = 0
        counter = 0
        while True:
            nextUnique = self.findNextUniqueIndex(nums, prvIndex)
            if nextUnique == -1:
                return counter + 1
            currentIndex += 1
            nums[currentIndex] = nums[nextUnique]
            prvIndex = nextUnique
            counter += 1
        return counter
    def findNextUniqueIndex(self, nums, prvIndex):
        i = prvIndex + 1
        length = len(nums)
        while i < length:
            if nums[i] > nums[prvIndex]:
                return i
            i += 1
        return -1

def main():
    nums = [1,1,2]
    s = Solution()
    ret = s.removeDuplicates(nums)
    print(nums)
    print (ret)

if __name__ == "__main__":
    main()