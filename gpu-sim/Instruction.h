#pragma once
#include <string>

enum class Opcode {
    ADD,
    MUL,
    FMA,
    LD,
    ST
};

struct Instruction {
    Opcode opcode;

    int src1;
    int src2;
    int dst;

    int latency;
};

std::string opcodeToString(Opcode opcode);