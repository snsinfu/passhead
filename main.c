#include <assert.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    for (;;) {
        char ch;

        ssize_t n_read = read(0, &ch, 1);
        if (n_read == 0) {
            return 0;
        }
        if (n_read == -1) {
            perror("read");
            return 1;
        }

        if (write(1, &ch, 1) == -1) {
            perror("write");
            return 1;
        }
        if (ch == '\n') {
            break;
        }
    }

    if (argc == 1) {
        return 0;
    }

    if (execvp(argv[1], argv + 1) == -1) {
        perror("exec");
        return 1;
    }

    assert(0);
}
