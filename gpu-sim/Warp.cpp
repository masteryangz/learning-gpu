#include "Warp.h"

void Warp::addInstruction(const Instruction& inst) {
    instructions.push_back(inst);
}

bool Warp::hasNextInstruction() const {
    return pc < instructions.size();
}

Instruction& Warp::nextInstruction() {
    return instructions[pc];
}

void Warp::advance() {
    pc++;
}
