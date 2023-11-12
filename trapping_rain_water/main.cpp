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
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            subMergedArea = height[leftIndex + 1];
            rightIndex = leftIndex + 2;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            const int width = (rightIndex - leftIndex - 1);
            const int h = std::min(
                height[leftIndex],
                height[rightIndex]
            );
            const int area = (width * h) - subMergedArea;
            overAllArea += area;
            leftIndex = rightIndex;
        } else {
            ++leftIndex;
        }
    }
    return overAllArea;
}
};

int main() {
    std::vector<int> heights {8, 2, 3, 5, 8, 2, 3, 10};

    Solution s;
    std::cout << s.trap(heights) << "\n";
}



//  int trap(std::vector<int>& height) {
//         std::vector<int> inBetweenHeights;
//         int leftHeightIndex = 0;
//         int currentArea = 0;
//         int size {height.size()};
//         while (leftHeightIndex < size - 2) {
//             const int nextHeight = height[leftHeightIndex + 1];
//             const int leftHeight = height[leftHeightIndex];

//             if (leftHeight > nextHeight) {
//                 int heighestIndex {leftHeightIndex + 1};
//                 int maxHeight {nextHeight};
//                 int currentIndex = leftHeightIndex + 2;
//                 int insideArea = height[leftHeightIndex + 1];
//                 int insideAreaInCaseIfTheresNoHeigher;
//                 while (currentIndex < height.size() && height[leftHeightIndex] > height[currentIndex])
//                 {
//                     insideArea += height[currentIndex];
//                     if (height[currentIndex] >= maxHeight) {
//                         maxHeight = height[currentIndex];
//                         heighestIndex = currentIndex;
//                         insideAreaInCaseIfTheresNoHeigher = insideArea;
//                     }
//                     ++currentIndex;
//                 }
//                 if (currentIndex < height.size()) {
//                     const int w = currentIndex - leftHeightIndex - 1;
//                     const int h = height[leftHeightIndex];
//                     currentArea += (h * w) - insideArea;
//                     leftHeightIndex = currentIndex;
//                 } else if (heighestIndex != leftHeightIndex + 1){
//                     const int w = heighestIndex - leftHeightIndex - 1;
//                     const int h = maxHeight;
//                     currentArea += (w * h) - insideAreaInCaseIfTheresNoHeigher + height[heighestIndex];
//                     leftHeightIndex = heighestIndex;
//                 } else {
//                     return ;
//                 }
                
//             } else {
//                 ++leftHeightIndex;
//             }
//         }
//         return currentArea;
//     }