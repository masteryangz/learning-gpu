#include "Instruction.h"

std::string opcodeToString(Opcode opcode) {
    switch (opcode) {
        case Opcode::ADD: return "ADD";
        case Opcode::MUL: return "MUL";
        case Opcode::FMA: return "FMA";
        case Opcode::LD:  return "LD";
        case Opcode::ST:  return "ST";
        default:          return "UNKNOWN";
    }
}