#include <unistd.h>
#include <iostream>
#include <cmath>
#include <sys/wait.h>

int main()
{
    std::cout << "Enter number: ";
    std::string number;
    std::cin >> number;
    double num = std::stod(number);

    pid_t pid = fork();
    if (pid == -1)
    {
        std::cerr << "Could not fork process!" << std::endl;
        return 1;
    }
    else if (pid == 0)
    {
        std::cout << "Child process: " << getpid() << "\n";
        std::cout << sqrt(num) << std::endl;
        _exit(0);
    }
    else
    {
        std::cout << "Parent process with child " << pid << "\n";
        std::cout << (int)num << std::endl;
    }

    int errc;
    wait(&errc);

    if (errc != 0)
    {
        std::cerr << "Child process " << pid << " exited with error code " << errc << std::endl;
    }

    return 0;
}