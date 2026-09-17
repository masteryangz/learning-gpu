#include "Scheduler.h"

Scheduler::Scheduler(int id) : id(id), curr_warp(nullptr), next_warp(0) {}

void Scheduler::addWarp(Warp* warp) {
    warps.push_back(warp);
}

Warp* Scheduler::select_warp() {
    if (warps.empty()) {
        return nullptr;
    }
    curr_warp = warps[next_warp];
    next_warp = (next_warp + 1) % warps.size();
    return curr_warp;
}

void Scheduler::issue(int cycle) {
    if (curr_warp && curr_warp->hasNextInstruction()) {
        Instruction& inst = curr_warp->nextInstruction();
        // Issue the instruction (for simplicity, we just print it here)
        std::cout << "Cycle " << cycle << ": Issuing instruction with opcode " << inst.opcode << std::endl;
        curr_warp->advance();
    }
}