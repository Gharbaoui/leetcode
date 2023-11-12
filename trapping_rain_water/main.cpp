#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
int trap(std::vector<int>& height) {
    int overAllArea = 0;
    int leftIndex = 0, rightIndex;
    int subMergedArea;
    const int size = height.size();
    int heighestBoxIndex;
    int heighestBox;
    int areaForHeighestBox;
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            heighestBoxIndex = 0;
            heighestBox = -1;
            subMergedArea = 0;
            rightIndex = leftIndex + 1;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                if (height[rightIndex] > heighestBox) {
                    heighestBox = height[rightIndex];
                    heighestBoxIndex = rightIndex;
                    areaForHeighestBox = subMergedArea;
                }
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            if (rightIndex < size) {
                const int width = (rightIndex - leftIndex - 1);
                const int h = std::min(
                    height[leftIndex],
                    height[rightIndex]
                );
                const int area = (width * h) - subMergedArea;
                overAllArea += area;
                leftIndex = rightIndex;
            } else {
               const int width = (heighestBoxIndex - leftIndex - 1);
                const int h = std::min(
                    height[leftIndex],
                    heighestBox
                );
                const int area = (width * h) - areaForHeighestBox;
                if (area > 0)
                    overAllArea += area;
                leftIndex = heighestBoxIndex;
            }
        } else {
            ++leftIndex;
        }
    }
    return overAllArea;
}
};


int main()
{
    std::vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;

    std::cout << s.trap(heights) << std::endl;


}