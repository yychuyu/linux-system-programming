#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_alrm(int signo)
{
    /* nothing to do */
}

unsigned int mysleep(unsigned int nsecs)
{
    unsigned int unslept;

	signal(SIGALRM, &sig_alrm);
    unslept = alarm(nsecs); 
    pause();

    return unslept;
}


int main(void)
{
    while(1){
        mysleep(2);
        printf("Two seconds passed\n");
    }

    return 0;
}
