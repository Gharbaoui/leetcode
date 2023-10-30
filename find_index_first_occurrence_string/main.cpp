#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hi = 0;
        int ni;
        const int hlen = haystack.size();
        const int nlen = needle.size();
        if (nlen > hlen) {
            return -1;
        }
        while (hi < hlen) {
            ni = 0;
            while (ni < nlen && needle[ni] == haystack[hi + ni])
                ++ni;
            if (ni == nlen)
                return hi;
            ++hi;
        }
        return -1;
    }
};




int main() {
    std::string haystack = "mississippi";
    std::string needle = "issip";
    
    Solution s;

    int val = s.strStr(haystack, needle);

    std::cout << val << "\n";
}
