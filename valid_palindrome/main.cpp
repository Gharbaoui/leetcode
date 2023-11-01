#include <iostream>

class Solution {
public:
bool isPalindrome(std::string s) {
    s = convert(s);
    const auto slen = s.size();
    if (slen < 2) {
        return true;
    }
    int leftPointer = 0;
    int rightPointer = slen - 1;

    while (leftPointer < rightPointer) {
        if (s[leftPointer] == s[rightPointer]) {
            ++leftPointer;
            --rightPointer;
        } else {
            return false;
        }
    }
    return true;
}
std::string    convert(const std::string& s) {
    std::string tmp;
    for (auto c : s) {
        if (isalnum(c))
            tmp += std::tolower(c);
    }
    return tmp;
}
};

int	main() {
	Solution s;

	std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << "\n";
}
