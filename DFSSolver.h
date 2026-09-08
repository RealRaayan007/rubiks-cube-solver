#include <bits/stdc++.h>
#include "RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

class DFSSolver {
private:

    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

    bool dfs(int dep) {

        if (rubiksCube.isSolved()) return true;

        if (dep > max_search_depth)
            return false;

        for (int i = 0; i < 18; i++) {

            RubiksCube::MOVE curr_move = RubiksCube::MOVE(i);

            rubiksCube.move(curr_move);

            moves.push_back(curr_move);

            if (dfs(dep + 1)) return true;

            moves.pop_back();

            rubiksCube.invert(curr_move);
        }

        return false;
    }

public:

    RubiksCube1dArray rubiksCube;

    DFSSolver(RubiksCube1dArray _rubiksCube, int _max_search_depth = 8) {

        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    // Performs DFS and returns the solution moves
    vector<RubiksCube::MOVE> solve() {

        dfs(1);

        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_DFSSOLVER_H