#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        const int nums1Size = nums1.size();
        std::vector<int> tmp(nums1Size, 0);
        int k = 0;
        int n2i = 0;
        int n1i = 0;
        if (m == 0 || n == 0)
        {
            if (m == 0)
                nums1.swap(nums2);
            return ;
        }
        while (n1i < m && n2i < n)
        {
            if (nums1[n1i] < nums2[n2i])
            {
                tmp[k++] = nums1[n1i++];
            } else {
                tmp[k++] = nums2[n2i++];
            }
        }
        while (n1i < m)
        {
            tmp[k++] = nums1[n1i++];
        }
        while (n2i < n)
        {
            tmp[k++] = nums2[n2i++];
        }
        nums1.swap(tmp);
    }
};

int main() {
    Solution s;

    std::vector<int> nums1{1,2,3,0,0,0};
    std::vector<int> nums2{2,5,6};
    s.merge(nums1, 3, nums2, 3);

    for (auto v : nums1)
    {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}
