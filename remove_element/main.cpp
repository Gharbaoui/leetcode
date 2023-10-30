#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index;
        int len = nums.size();
        int current_value;
        int next_index;
        for (index = 0; index < len; ++index) {
            current_value = nums[index];
            if (current_value == val) {
                next_index = index + 1;
                while (next_index < len) {
                    if (nums[next_index] != val) {
                        break ;
                    }
                    ++next_index;
                }
                if (next_index < len) {
                    std::swap(nums[index], nums[next_index]);
                } else {
                    break;
                }
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums{3,2,2,3};

    Solution s;

    std::cout << s.removeElement(nums, 3) << "\n";

    for (auto val : nums){
        std::cout << val << ", ";
    }
    std::cout << std::endl;
}
