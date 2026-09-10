#include <iostream>
#include <string>

std::string determineColor(const std::string& s) {
    return ((s[0] + s[1] ) % 2 != 0)? "White" : "Black";
}

int main() {
    std::string s;
    std::cin >> s;
    std::string result = determineColor(s);
    std::cout << result << std::endl;
    return 0;
}