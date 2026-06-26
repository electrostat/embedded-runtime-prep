#include "scheduler.h"

#define MAX_TASKS 16

static scheduler_task_t tasks[MAX_TASKS];
static uint32_t system_tick = 0;
static uint32_t tick_rate_hz = 1000;

void scheduler_init(uint32_t tick_hz){
    tick_rate_hz = tick_hz;
    system_tick = 0;

    for (int i = 0; i < MAX_TASKS; i++){
        tasks[i].active = false;
    }
}

void scheduler_tick(void){
    system_tick++;
}

bool scheduler_add_task(task_fn_t fn, uint32_t period_ticks){
    for (int i = 0; i < MAX_TASKS; i++){
        if (!tasks[i].active){
            tasks[i].callback = fn;
            tasks[i].period_ticks = period_ticks;
            tasks[i].next_run_tick = system_tick + period_ticks;
            tasks[i].active = true;
            return true;
        }
    }
    
    return false;
}

void scheduler_run(void){
    for (int i = 0; i < MAX_TASKS; i++){
        if (tasks[i].active && system_tick >= tasks[i].next_run_tick){
            tasks[i].callback();
            tasks[i].next_run_tick += tasks[i].period_ticks;
        }
    }
}