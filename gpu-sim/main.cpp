#include <iostream>
#include "Instruction.h"
#include "Warp.h"
#include "Scheduler.h"

int main() {

    std::cout << "GPU Simulator Starting..." << std::endl;
    Warp w0(0);
    Warp w1(1);
    Warp w2(2);
    Warp w3(3);
    Instruction inst0 = {Opcode::ADD, 0, 1, 2, 1};
    Instruction inst1 = {Opcode::MUL, 1, 2, 3, 2};
    Instruction inst2 = {Opcode::FMA, 2, 3, 4, 2};
    Instruction inst3 = {Opcode::LD, 0, 1, 2, 3};
    Instruction inst4 = {Opcode::ST, 0, 1, 2, 3};
    Instruction inst5 = {Opcode::ADD, 0, 1, 2, 1};
    Instruction inst6 = {Opcode::MUL, 1, 2, 3, 2};
    Instruction inst7 = {Opcode::FMA, 2, 3, 4, 2};
    w0.addInstruction(inst0);
    w1.addInstruction(inst1);
    w2.addInstruction(inst2);
    w3.addInstruction(inst3);
    w0.addInstruction(inst4);
    w1.addInstruction(inst5);
    w2.addInstruction(inst6);
    w3.addInstruction(inst7);
    Scheduler s(0);
    s.addWarp(&w0);
    s.addWarp(&w1);
    s.addWarp(&w2);
    s.addWarp(&w3);
    int cycle = 0;
    while (s.select_warp() != nullptr) {
        s.issue(cycle++);
    }

    return 0;
}