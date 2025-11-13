#include <unistd.h>
#include <sys/mman.h>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

class MemoryAllocator
{
public:
    explicit MemoryAllocator(size_t size) : size(size)
    {
        address = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        printf("Allocated address = %p\n", address);
        if (address == nullptr)
        {
            throw std::bad_alloc();
        }
    }

    template <typename T>
    T* cast()
    {
        return static_cast<T*>(address);
    }

    ~MemoryAllocator()
    {
        munmap(address, size);
    }

private:
    size_t size;
    void* address;
};

class User
{
public:
    User(const std::string& name, int year = 2025) : name(name), year(year) {}

    void printInfo()
    {
        write(STDOUT_FILENO, name.c_str(), name.size());
        write(STDOUT_FILENO, " (", 2);
        write(STDOUT_FILENO, std::to_string(year).c_str(), 4);
        write(STDOUT_FILENO, ")\n", 2);
    }

private:
    std::string name;
    int year;
};

int main()
{
    MemoryAllocator memoryAllocator(sizeof(User));
    void* ptr = memoryAllocator.cast<void>();

    User* user = new (ptr) User("Emil Shteinberg", 2025);
    user->printInfo();
    user->~User();

    return 0;
}