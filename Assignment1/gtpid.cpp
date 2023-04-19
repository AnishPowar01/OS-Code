#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>


int main() {
    
    pid_t process_id, p_process_id;
    
    process_id=getpid();
    p_process_id=getpid();
    
    printf("Parent id : %d\n",process_id);
    printf("Child id : %d\n",p_process_id);
    
    return 0;
}
