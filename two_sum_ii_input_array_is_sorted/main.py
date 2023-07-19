class Solution:
    def twoSum(self, numbers, target):
        left_index = 0
        right_index = len(numbers) - 1

        while left_index < right_index:
            combined_values_of_left_and_write = numbers[left_index] + numbers[right_index]
            if combined_values_of_left_and_write > target:
                right_index -= 1
            elif combined_values_of_left_and_write < target:
                left_index += 1
            else:
                return [left_index + 1, right_index + 1]
            
def main():
    
    s = Solution()

    arr = [2,7,11,15]
    target = 9
    print (s.twoSum(arr, target))

main()