#include <bits/stdc++.h>

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

class BFSSolver {
private:
    vector<RubiksCube::MOVE> moves;

    unordered_map<RubiksCube1dArray, bool, Hash1d> visited;

    unordered_map<RubiksCube1dArray,RubiksCube::MOVE,Hash1d> move_done;

    RubiksCube1dArray bfs() {

        queue<RubiksCube1dArray> q;

        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {

            RubiksCube1dArray node = q.front();
            q.pop();

            if (node.isSolved()) {
                return node; 
            }
            
            for (int i = 0; i < 18; i++) {

                auto curr_move = RubiksCube::MOVE(i);

                node.move(curr_move);

                if (!visited[node]) {

                    visited[node] = true;
                    move_done[node] = curr_move;

                    q.push(node);
                }

                node.invert(curr_move);
            }
        }

        return rubiksCube;
    }

public:
    RubiksCube1dArray rubiksCube;

    BFSSolver(RubiksCube1dArray _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    vector<RubiksCube::MOVE> solve() {

        RubiksCube1dArray solved_cube = bfs();

        assert(solved_cube.isSolved());

        RubiksCube1dArray curr_cube = solved_cube;

        while (!(curr_cube == rubiksCube)) {

            RubiksCube::MOVE curr_move = move_done[curr_cube];

            moves.push_back(curr_move);

            curr_cube.invert(curr_move); 
        }

        rubiksCube = solved_cube;

        reverse(moves.begin(), moves.end());

        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_BFSSOLVER_H