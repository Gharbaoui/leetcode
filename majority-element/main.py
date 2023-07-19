class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr_len = len(nums)

        for index, elm in enumerate(nums):
            current_count = 1
            inner_index = index + 1
            while inner_index < arr_len:
                if elm == nums[inner_index]:
                    current_count += 1
                inner_index += 1
            if current_count > arr_len/2:
                return elm

def main():
    s = Solution()
    print(s.majorityElement([2,2,1,1,1,2,2]))

if __name__ == "__main__":
    main()