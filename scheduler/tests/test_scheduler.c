#include "scheduler.h"
#include <assert.h>
#include <stdio.h>

static int counter = 0;

void test_task(void){
    counter++;
}

int main(void){
    scheduler_init(1000);
    scheduler_add_task(test_task, 10);

    for (int i = 0; i < 100; i++){
        scheduler_tick();
        scheduler_run();
    }
    
    assert(counter == 10);
    printf("Scheduler tests passed.\n");

    return 0;
}