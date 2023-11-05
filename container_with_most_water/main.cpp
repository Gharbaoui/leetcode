#include <vector>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        
        while (leftIndex < rightIndex)
        {
            int currentHeight = height[leftIndex] < height[rightIndex] ? height[leftIndex] : height[rightIndex];
            int currentArea = currentHeight * (rightIndex - leftIndex);
            if (currentArea > maxArea) {
                maxArea = currentArea;
            }
            if (height[leftIndex] > height[rightIndex]){
                --rightIndex;
            } else {
                ++leftIndex;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    std::vector<int> heights {1,8,6,2,5,4,8,3,7};

    std::cout << s.maxArea(heights) << "\n";

}