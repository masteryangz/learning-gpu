#include "Scheduler.h"

Scheduler::Scheduler(int id) : id(id), curr_warp(nullptr), next_warp(0) {}

void Scheduler::addWarp(Warp* warp) {
    warps.push_back(warp);
}

Warp* Scheduler::select_warp() {
    if (warps.empty()) {
        return nullptr;
    }
    for (size_t i = 0; i < warps.size(); i++) {
        if (warps[next_warp]->hasNextInstruction()) {
            curr_warp = warps[next_warp];
            return curr_warp;
        }
        next_warp = (next_warp + 1) % warps.size();
    }
    return nullptr;
}

void Scheduler::issue(int cycle) {
    Instruction& inst = curr_warp->nextInstruction();
    // Issue the instruction (for simplicity, we just print it here)
    std::cout << "Cycle " << cycle << ": Issuing instruction with opcode " << inst.opcode << std::endl;
    curr_warp->advance();
}