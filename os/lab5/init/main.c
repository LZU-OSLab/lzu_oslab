#include <sbi.h>
#include <kdebug.h>
#include <mm.h>
#include <trap.h>
#include <sched.h>
#include <clock.h>
#include <syscall.h>
#include <assert.h>

int main()
{
    print_system_infomation();
    mem_init();
    mem_test();
    trap_init();
    sched_init();
    clock_init();
    kputs("Hello LZU OS");
    init_task0();
    syscall(NR_fork);    /* task 0 creates task 1 */
    syscall(NR_fork);    /* task 0 creates task 2, task 1 creates task 3 */
    long local = syscall(NR_getpid) + 100;
    syscall(NR_test_fork, local);
    while (1)
        ; /* infinite loop */
    return 0;
}
