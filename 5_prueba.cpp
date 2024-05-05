#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    
    std::ostringstream oss;
    oss << "[" << std::put_time(std::localtime(&now_c), "%Y%m%d_%H%M%S") << "]";
    return oss.str();
}

int main() {
    std::string timestamp = getCurrentTimestamp();
    std::cout << timestamp << std::endl;
    return 0;
}