 #include <iostream>
 #include <stdexcept>

 int main()
 {
    int a = 10;
    int b = 0;

    int c;
    try
    {
        if (b == 0)
            throw "divide by zero";
    c = a/b;
    std::cout << c << std::endl;

    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    return (0);
 }