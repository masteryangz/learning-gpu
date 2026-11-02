#include "Scoreboard.h"
#include "Instruction.h"

Scoreboard::Scoreboard() {
    for (int warp = 0; warp < 4; ++warp) {
        for (int reg = 0; reg < 32; ++reg) {
            register_ready_cycle[warp][reg] = 0;
        }
    }
}

bool Scoreboard::isReady(int warp_id, const Instruction& inst, int current_cycle) {
    // Check if the source registers are ready
    if (current_cycle < register_ready_cycle[warp_id][inst.src1] ||
        current_cycle < register_ready_cycle[warp_id][inst.src2]) {
        return false;
    }
    return true;
}

void Scoreboard::markBusy(int warp_id, const Instruction& inst, int current_cycle) {
    // Mark the destination registers as busy
    register_ready_cycle[warp_id][inst.dst] = current_cycle + inst.latency;
}