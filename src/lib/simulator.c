/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <cpu-bound-simulator/simulator.h>
#include <errno.h>

#include <time.h>
static void sleepMs(size_t milliseconds)
{
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;

    int err = nanosleep(&ts, &ts);
    if (err != 0) {
        CLOG_ERROR("NOT WORKING:%d", errno)
    }
}

void cpuBoundSimulatorInit(CpuBoundSimulator* self, const CpuBoundSimulatorSetup* setup)
{
    cpuBoundSimulatorSetup(self, setup);
    self->lastMs = monotonicTimeMsNow();
}

void cpuBoundSimulatorUpdate(CpuBoundSimulator* self)
{
    MonotonicTimeMs now = monotonicTimeMsNow();
    size_t timeSpent = (size_t)(now - self->lastMs);
    self->lastMs = now;

    if (timeSpent < self->setup.targetTimeStep) {
        size_t sleepTimeMs = self->setup.targetTimeStep - timeSpent;
        sleepMs(sleepTimeMs);
    }
}

void cpuBoundSimulatorSetup(CpuBoundSimulator* self, const CpuBoundSimulatorSetup* setup)
{
    self->setup = *setup;
}
