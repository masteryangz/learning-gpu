#include "Warp.h"

int Warp::id() {
    return warp_id;
}

void Warp::addInstruction(const Instruction& inst) {
    instructions.push_back(inst);
}

bool Warp::hasNextInstruction() const {
    return pc < (int)instructions.size();
}

Instruction& Warp::nextInstruction() {
    return instructions[pc];
}

void Warp::advance() {
    pc++;
}
