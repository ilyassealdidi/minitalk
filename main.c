#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void signal_handler(int sig)
{
    write(1, "Intterupted", strlen("Intterupted"));
}

int main(void) {
    struct sigaction SIGUSR1_action = {0};
    SIGUSR1_action.sa_handler = catchSIGUR1;
    sigfillset(&SIGUSR1_action.sa_mask);

    

    while (1);
    return 0;
}