#include <iostream>

// app {число} {число2} 
// stdout: число + число2 = результат
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage:\napp {num1} {num2}" << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        double first = std::stod(argv[1]);
        double second = std::stod(argv[2]);
        std::cout << first << " + " << second << " = " << first + second << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to parse arguments: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}