#include <bits/stdc++.h>

#include "RubiksCube1dArray.cpp"
#include "BFSSolver.h"
#include "DFSSolver.h"
#include "IDDFSSolver.h"

using namespace std;

int main() {

    // -----------------------------------------
    // 1. Create and shuffle the cube
    // -----------------------------------------

    RubiksCube1dArray cube;

    int shuffle_count;

    cout << "Enter number of shuffle moves: ";
    cin >> shuffle_count;

    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(shuffle_count);

    cout << "\nShuffle moves: ";

    for (auto move : shuffle_moves) cout << cube.getMove(move) << " ";

    cout << "\n\n";

    // -----------------------------------------
    // 2. User selects algorithm
    // -----------------------------------------

    cout << "Choose Solver:\n";
    cout << "1. BFS\n";
    cout << "2. DFS\n";
    cout << "3. IDDFS\n";
    cout << "4. Benchmark All Three\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    // -----------------------------------------
    // 3. BFS
    // -----------------------------------------

    if (choice == 1) {

        RubiksCube1dArray startCube = cube;

        auto start = chrono::high_resolution_clock::now();

        BFSSolver bfsSolver(startCube);
        vector<RubiksCube::MOVE> solution = bfsSolver.solve();

        auto end = chrono::high_resolution_clock::now();

        auto duration =
            chrono::duration_cast<chrono::microseconds>(
                end - start
            );

        cout << "\n========== BFS ==========\n";

        cout << "Solution: ";
        for (auto move : solution) cout << cube.getMove(move) << " ";

        cout << "\nSolution length: "
             << solution.size();

        cout << "\nTime: "
             << duration.count()
             << " microseconds\n";

        cout << "\nSolved Cube:\n";
        bfsSolver.rubiksCube.print();
    }

    // -----------------------------------------
    // 4. DFS
    // -----------------------------------------

    else if (choice == 2) {

        RubiksCube1dArray startCube = cube;

        int depth;

        cout << "\nEnter maximum DFS depth: ";
        cin >> depth;

        auto start = chrono::high_resolution_clock::now();

        DFSSolver dfsSolver(startCube, depth);
        vector<RubiksCube::MOVE> solution =
            dfsSolver.solve();

        auto end = chrono::high_resolution_clock::now();

        auto duration =
            chrono::duration_cast<chrono::microseconds>(
                end - start
            );

        cout << "\n========== DFS ==========\n";

        if (dfsSolver.rubiksCube.isSolved()) {

            cout << "Solution: ";

            for (auto move : solution)
                cout << cube.getMove(move) << " ";

            cout << "\nSolution length: "
                 << solution.size();

            cout << "\nTime: "
                 << duration.count()
                 << " microseconds\n";

            cout << "\nSolved Cube:\n";
            dfsSolver.rubiksCube.print();

        } else {

            cout << "No solution found within depth "
                 << depth << ".\n";
        }
    }

    // -----------------------------------------
    // 5. IDDFS
    // -----------------------------------------

    else if (choice == 3) {

        RubiksCube1dArray startCube = cube;

        int depth;

        cout << "\nEnter maximum IDDFS depth: ";
        cin >> depth;

        auto start = chrono::high_resolution_clock::now();

        IDDFSSolver iddfsSolver(startCube, depth);
        vector<RubiksCube::MOVE> solution =
            iddfsSolver.solve();

        auto end = chrono::high_resolution_clock::now();

        auto duration =
            chrono::duration_cast<chrono::microseconds>(
                end - start
            );

        cout << "\n========== IDDFS ==========\n";

        if (iddfsSolver.rubiksCube.isSolved()) {

            cout << "Solution: ";

            for (auto move : solution)
                cout << cube.getMove(move) << " ";

            cout << "\nSolution length: "
                 << solution.size();

            cout << "\nTime: "
                 << duration.count()
                 << " microseconds\n";

            cout << "\nSolved Cube:\n";
            iddfsSolver.rubiksCube.print();

        } else {

            cout << "No solution found within depth "
                 << depth << ".\n";
        }
    }

    // -----------------------------------------
    // 6. Benchmark all three
    // -----------------------------------------

    else if (choice == 4) {

        cout << "\n========== BENCHMARK ==========\n";

        // ---------------- BFS ----------------

        {
            RubiksCube1dArray startCube = cube;

            auto start =
                chrono::high_resolution_clock::now();

            BFSSolver bfsSolver(startCube);
            vector<RubiksCube::MOVE> solution =
                bfsSolver.solve();

            auto end =
                chrono::high_resolution_clock::now();

            auto duration =
                chrono::duration_cast<chrono::microseconds>(
                    end - start
                );

            cout << "\nBFS\n";
            cout << "Solution length: "
                 << solution.size() << "\n";
            cout << "Time: "
                 << duration.count()
                 << " microseconds\n";
        }

        // ---------------- DFS ----------------

        {
            RubiksCube1dArray startCube = cube;

            int depth = 8;

            auto start =
                chrono::high_resolution_clock::now();

            DFSSolver dfsSolver(startCube, depth);
            vector<RubiksCube::MOVE> solution =
                dfsSolver.solve();

            auto end =
                chrono::high_resolution_clock::now();

            auto duration =
                chrono::duration_cast<chrono::microseconds>(
                    end - start
                );

            cout << "\nDFS\n";

            if (dfsSolver.rubiksCube.isSolved()) {

                cout << "Solution length: "
                     << solution.size() << "\n";

                cout << "Time: "
                     << duration.count()
                     << " microseconds\n";

            } else {

                cout << "No solution within depth "
                     << depth << "\n";
            }
        }

        // ---------------- IDDFS ----------------

        {
            RubiksCube1dArray startCube = cube;

            int depth = 8;

            auto start =
                chrono::high_resolution_clock::now();

            IDDFSSolver iddfsSolver(startCube, depth);
            vector<RubiksCube::MOVE> solution =
                iddfsSolver.solve();

            auto end =
                chrono::high_resolution_clock::now();

            auto duration =
                chrono::duration_cast<chrono::microseconds>(
                    end - start
                );

            cout << "\nIDDFS\n";

            if (iddfsSolver.rubiksCube.isSolved()) {

                cout << "Solution length: "
                     << solution.size() << "\n";

                cout << "Time: "
                     << duration.count()
                     << " microseconds\n";

            } else {

                cout << "No solution within depth "
                     << depth << "\n";
            }
        }
    }

    else {
        cout << "\nInvalid choice.\n";
    }

    return 0;
}