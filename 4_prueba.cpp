#include <iostream>
#include <ctime>
#include <iomanip>

int main(void)
{
    time_t aux;
    struct tm *time_info;

    time (&aux);
    time_info = localtime(&aux); 
    std::cout << asctime(time_info) << std::endl;
    std::cout << time_info->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_mday;
    std::cout << "_"; 
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << time_info->tm_sec;
    std::cout << std::endl;
    return (0);
}