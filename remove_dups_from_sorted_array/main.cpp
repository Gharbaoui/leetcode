#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        const auto arr_len = nums.size();
        int i = 0;
        while (i < arr_len)
        {
            if (!isCurrentUnique(i, nums))
            {
                const auto pv = getNextUniqueElement(i, nums);
                if (pv.first) {
                    nums[i] = pv.second;
                } else {
                    return i;
                }
            }
            ++i;
        }
        return i;
    }
    bool    isCurrentUnique(int current_index, const std::vector<int>& nums)
    {
        for (int i = 0; i < current_index; ++i) {
            if (nums[i] == nums[current_index])
                return false;
        }
        return true;
    }
    std::pair<bool, int>    getNextUniqueElement(int current_index, const std::vector<int>& nums)
    {
        const auto start = current_index + 1;
        const auto end = nums.size();

        for (int i = start; i < end; ++i) {
            if (isCurrentUnique(i, nums)) {
                return {true, nums[i]};
            }
        }
        return {false, -1};
    }
};