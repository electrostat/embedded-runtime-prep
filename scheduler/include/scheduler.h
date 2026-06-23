#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>
#include <stdbool.h>

typedef void (*task_fn_t)(void);

typedef struct {
    task_fn_t callback;
    uint32_t period_ticks;
    uint32_t next_run_tick;
    bool active;
} scheduler_task_t;

void scheduler_init(uint32_t tick_hz);
void scheduler_tick(void);
bool scheduler_add_task(task_fn_t fn, uint32_t period_ticks);
void scheduler_run(void);

#endif
