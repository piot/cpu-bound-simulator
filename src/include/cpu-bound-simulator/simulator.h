/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef CPU_BOUND_SIMULATOR_H
#define CPU_BOUND_SIMULATOR_H

#include <stddef.h>
#include <monotonic-time/monotonic_time.h>

typedef struct CpuBoundSimulatorSetup {
    size_t targetTimeStep;
} CpuBoundSimulatorSetup;

typedef struct CpuBoundSimulator {
    CpuBoundSimulatorSetup setup;
    MonotonicTimeMs lastMs;
} CpuBoundSimulator;

void cpuBoundSimulatorInit(CpuBoundSimulator* self, const CpuBoundSimulatorSetup* setup);
void cpuBoundSimulatorUpdate(CpuBoundSimulator* self);
void cpuBoundSimulatorSetup(CpuBoundSimulator* self, const CpuBoundSimulatorSetup* setup);

#endif
