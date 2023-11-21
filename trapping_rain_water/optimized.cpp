#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    int trap(std::vector<int>& heights) {
        std::vector<int> left(heights.size());
        std::vector<int> right(heights.size());

        fillMaxLeftArr(heights, left);
        fillMaxRight(heights, right);

        int currentArea = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            const int minHeight = std::min(left[i], right[i]);
            const int area = minHeight - heights[i];
            currentArea += (area > 0) ? area : 0;
        }
        return currentArea;
    }

void    fillMaxLeftArr(const std::vector<int> &heights, std::vector<int> &out)
{
    int currentMax = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        out[i] = currentMax;
        if (heights[i] > currentMax)
            currentMax = heights[i];
    }
}

void    fillMaxRight(const std::vector<int> &heights, std::vector<int> &out)
{
    int currentMax = 0;
    for (int i = heights.size() - 1; i >= 0; --i)
    {
        out[i] = currentMax;
        if (heights[i] > currentMax)
            currentMax = heights[i];
    }
}
};

int main()
{
    std::vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;

    std::cout << s.trap(heights) << std::endl;


}