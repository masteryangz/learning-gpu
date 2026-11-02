#include <iostream>
#include "Instruction.h"
#include "Warp.h"
#include "Scheduler.h"
#include "Scoreboard.h"

int main() {

    std::cout << "GPU Simulator Starting..." << std::endl;
    Warp w0(0);
    Warp w1(1);
    Instruction inst0 = {Opcode::LD, 2, 0, 1, 4};
    Instruction inst1 = {Opcode::ADD, 1, 4, 3, 2};
    Instruction inst2 = {Opcode::MUL, 6, 7, 5, 3};
    Instruction inst3 = {Opcode::ADD, 5, 9, 8, 1};
    w0.addInstruction(inst0);
    w1.addInstruction(inst1);
    w0.addInstruction(inst2);
    w1.addInstruction(inst3);
    Scheduler s(0);
    s.addWarp(&w0);
    s.addWarp(&w1);
    int cycle = 0;
    while (s.select_warp(cycle) != nullptr) {
        s.issue(cycle++);
    }

    return 0;
}