#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        close(fd[0]);
        int x;
        while (cin >> x) {
            x *= 2;
            write(fd[1], &x, sizeof(x));
        }
        close(fd[1]);
    }
    else {
        close(fd[1]);
        int x, sum = 0;
        while (read(fd[0], &x, sizeof(x)) > 0)
            sum += x;
        cout << "Result:" << sum << endl;
        close(fd[0]);
        wait(nullptr);
    }
    return 0;
}
