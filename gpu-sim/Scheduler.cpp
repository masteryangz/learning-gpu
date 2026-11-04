#include "Scheduler.h"
#include <iostream>

Scheduler::Scheduler(int id) : id(id), curr_warp(nullptr), next_warp(0) {}

void Scheduler::addWarp(Warp* warp) {
    warps.push_back(warp);
}

Warp* Scheduler::select_warp(int curr_cycle) {
    curr_warp = nullptr;
    if (warps.empty()) {
        return nullptr;
    }
    for (size_t i = 0; i < warps.size(); i++) {
        if (warps[next_warp]->hasNextInstruction() && sb.isReady(warps[next_warp]->id(), warps[next_warp]->nextInstruction(), curr_cycle)) {
            curr_warp = warps[next_warp];
            next_warp = (next_warp + 1) % warps.size();
            return curr_warp;
        }
        next_warp = (next_warp + 1) % warps.size();
    }
    return nullptr;
}

void Scheduler::issue(int cycle) {
    if (curr_warp == nullptr) {
        return;
    }
    Instruction& inst = curr_warp->nextInstruction();
    sb.markBusy(curr_warp->id(), inst, cycle);
    // Issue the instruction (for simplicity, we just print it here)
    std::cout << "Cycle " << cycle << ": " << "W" << curr_warp->id() << " issues " << opcodeToString(inst.opcode) << std::endl;
    curr_warp->advance();
}

bool Scheduler::hasUnfinishedWarps() const {
    for (Warp* warp : warps) {
        if (warp->hasNextInstruction()) {
            return true;
        }
    }
    return false;
}