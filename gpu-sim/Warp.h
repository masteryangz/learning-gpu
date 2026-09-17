#pragma once

#include "Instruction.h"
#include <vector>

class Warp {
    int warp_id;
    int pc;
    std::vector<Instruction> instructions;
public:
    Warp(int id) : warp_id(id), pc(0) {}
    void addInstruction(const Instruction& inst);
    bool hasNextInstruction() const;
    Instruction& nextInstruction();
    void advance();
};