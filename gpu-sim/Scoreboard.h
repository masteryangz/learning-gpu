#pragma once

#include "Instruction.h"

class Scoreboard {
private:
    int register_ready_cycle[4][32];

public:
    Scoreboard();

    bool isReady(int warp_id,
                 const Instruction& inst,
                 int current_cycle);

    void markBusy(int warp_id,
              const Instruction& inst,
              int current_cycle);
};