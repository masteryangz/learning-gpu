#pragma once
#include "Scoreboard.h"
#include "Warp.h"

class Scheduler {
private:
    int id;

    Warp* curr_warp;

    std::vector<Warp*> warps;

    int next_warp;

    Scoreboard sb;

public:

    Scheduler(int id);

    void addWarp(Warp* warp);

    Warp* select_warp(int curr_cycle);

    void issue(int cycle);
};