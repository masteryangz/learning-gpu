#pragma once

#include "Warp.h"

class Scheduler {

    int id;

    Warp* curr_warp;

    std::vector<Warp*> warps;

    int next_warp;

public:

    Scheduler(int id);

    void addWarp(Warp* warp);

    Warp* select_warp();

    void issue(int cycle);
};