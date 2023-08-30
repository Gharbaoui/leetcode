class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr_len = len(nums)
        i = 0
        while i < arr_len:
            if not self.isCurrentElementUnique(i, nums):
                found, value = self.getNextUniqueElement(i, nums)
                if found:
                    nums[i] = value
                else:
                    return i
            i += 1
        return i
    def getNextUniqueElement(self,current_index, arr):
        start = current_index + 1
        end = len(arr)
        for i in range(start, end):
            if self.isCurrentElementUnique(i, arr):
                return (True, arr[i])
        
        return (False, -1)

    def isCurrentElementUnique(self, current_index, arr):
        current_element = arr[current_index]
        for i in range(0, current_index):
            if arr[i] == current_element:
                return False
        return True



if __name__ == "__main__":
    arr = [0, 2, 3, 4, 4, 4.5, 5, 6]

    s = Solution()

    ret = s.removeDuplicates(arr)

    print(arr[0:ret])