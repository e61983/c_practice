#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

static
void signal_handle( int signum )
{
    printf("Signal %d received.\n",signum);
}

int main(int argc, const char *argv[])
{
    printf("PID:%d\n",getpid());
    fflush(stdout);
    if(SIG_ERR==(signal(SIGUSR1,signal_handle))) {
        printf("Error Catching SIGUSR1\n");
    }
    if(SIG_ERR==(signal(SIGUSR2,signal_handle))) {
        printf("Error Catching SIGUSR2\n");
    }
    if(SIG_ERR==(signal(SIGINT,signal_handle))) {
        printf("Error Catching SIGINT\n");
    }
    char buf[1024];
    while(1) {
        int n;
        if(-1==( n = read(STDIN_FILENO,buf,1024))) {
            if(errno==EINTR) {
                printf("Interrupted.");
            }
        } else {
            write(STDOUT_FILENO,buf,n);
        }

    }

}
