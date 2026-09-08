Rubik's Cube Solver: State-Space Search Engine
An extensible state-space search engine in C++ that models a Rubik's Cube as a graph of discrete configurations. Each cube state represents a node, while legal face rotations form the edges, enabling systematic exploration of the state space to find solution sequences from scrambled configurations.
Core Features
Compact 1D State Representation: Models the complete cube using a 54-sticker 1D character array, providing a simple and memory-efficient representation for state comparison and hashing.
Graph-Based State Transitions: Treats every cube configuration as a graph state and generates 18 standard face-turn operations — clockwise, counter-clockwise, and 180° rotations across all six faces.
Optimal Shortest-Path Search: Implements Breadth-First Search (BFS) to explore states level-by-level, guaranteeing a minimum-move solution while using back-pointer state tracking to reconstruct the solution sequence.
Hash-Based State Deduplication: Uses a custom Hash1d functor with unordered_map for average O(1) state lookup, preventing repeated exploration of previously visited cube configurations.
Extensible Search Architecture: Separates the cube representation from search algorithms using an abstract RubiksCube interface, allowing BFS, depth-limited DFS, and IDDFS to operate on the same underlying cube model and be benchmarked through a common driver.
Tech Stack
Language: C++17
Design: Object-Oriented Programming
Concepts: Graph Theory, State-Space Search, Hashing, Recursion, Backtracking, BFS, DFS, IDDFS
Data Structures: queue, unordered_map, vector
Architecture & Algorithms
The solver represents the Rubik's Cube as a discrete state graph:
Cube State → Generate 18 Moves → New Cube States → Search → Solution Path
BFS — Breadth-First Search
Explores the state space level-by-level. Since every move has equal cost, BFS guarantees the shortest solution in number of moves. A back-pointer map records how each discovered state was reached, allowing the final solution path to be reconstructed.
DFS — Depth-Limited Depth-First Search
Explores one branch deeply before backtracking and uses a configurable depth limit to prevent unbounded traversal. It has low auxiliary memory usage but does not guarantee a shortest solution.
IDDFS — Iterative Deepening DFS
Repeatedly executes depth-limited DFS with increasing depth limits. This provides optimal-depth search behavior while retaining DFS's low memory requirements, with the trade-off of repeatedly exploring states across iterations.
Benchmarking
The command-line driver supports:
1. BFS
2. Depth-Limited DFS
3. IDDFS
4. Benchmarking all three approaches
For each solver, the program reports the solution length and execution time, allowing direct comparison of search behavior and performance.
Getting Started
Prerequisites
GCC / Clang / MSVC
C++17 or later
Build
If compiling the current source structure:

gg++ -std=c++17 main.cpp RubiksCube.cpp -o rubiks

Run
On Windows:
rubiks.exe
The program allows you to choose the number of scramble moves and select BFS, DFS, IDDFS, or benchmark all three algorithms.
# Rubik's Cube Solver: State-Space Search Engine

An extensible state-space search engine in C++ that models a Rubik's Cube as a graph of discrete configurations. Each cube state represents a node, while legal face rotations form the edges, enabling systematic exploration of the state space to find solution sequences from scrambled configurations.

# Core Features

* **Compact 1D State Representation:** Models the complete cube using a **54-sticker 1D character array**, providing a compact representation for efficient state comparison and hashing.

* **Graph-Based State Transitions:** Treats every cube configuration as a graph state and generates **18 standard face-turn operations** — clockwise, counter-clockwise, and 180° rotations across all six faces.

* **Optimal Shortest-Path Search:** Implements **Breadth-First Search (BFS)** to explore states level-by-level, guaranteeing a minimum-move solution while using **back-pointer state tracking** to reconstruct the solution sequence.

* **Hash-Based State Deduplication:** Uses a custom `Hash1d` functor with `unordered_map` for **average O(1) state lookup**, preventing repeated exploration of previously visited cube configurations.

* **Extensible Search Architecture:** Separates the cube representation from search algorithms using an abstract `RubiksCube` interface, allowing **BFS, depth-limited DFS, and IDDFS** to operate on the same underlying cube model and be benchmarked through a common driver.

# Tech Stack

* **Language:** C++17
* **Design:** Object-Oriented Programming
* **Concepts:** Graph Theory, State-Space Search, Hashing, Recursion, Backtracking, BFS, DFS, IDDFS
* **Data Structures:** `queue`, `unordered_map`, `vector`

# Architecture & Algorithms

The solver represents the Rubik's Cube as a discrete state graph:

**Cube State → Generate 18 Moves → New Cube States → Search → Solution Path**

### BFS — Breadth-First Search

Explores the state space level-by-level. Since every move has equal cost, BFS guarantees the **shortest solution in number of moves**. A back-pointer map records how each discovered state was reached, allowing the final solution path to be reconstructed.

### DFS — Depth-Limited Depth-First Search

Explores one branch deeply before backtracking and uses a configurable depth limit to prevent unbounded traversal. It has low auxiliary memory usage but **does not guarantee a shortest solution**.

### IDDFS — Iterative Deepening DFS

Repeatedly executes depth-limited DFS with increasing depth limits. This can find an **optimal-depth solution** while retaining DFS's low memory requirements, at the cost of repeatedly exploring states across iterations.

# Benchmarking

The command-line driver supports:

1. **BFS**
2. **Depth-Limited DFS**
3. **IDDFS**
4. **Benchmarking all three approaches**

For each solver, the program reports the **solution length** and **execution time**, allowing direct comparison of search behavior and performance.

# Getting Started

## Prerequisites

* GCC / Clang / MSVC
* C++17 or later

## Build

```bash
g++ -std=c++17 main.cpp RubiksCube.cpp -o rubiks
```

## Run

On Windows:

```bash
rubiks.exe
```

The program allows you to choose the number of scramble moves and select **BFS, DFS, IDDFS, or benchmark all three algorithms**.
# Rubik's Cube Solver: State-Space Search Engine

An extensible state-space search engine in C++ that models a Rubik's Cube as a graph of discrete configurations. Each cube state represents a node, while legal face rotations form the edges, enabling systematic exploration of the state space to find solution sequences from scrambled configurations.

# Core Features

* **Compact 1D State Representation:** Models the complete cube using a **54-sticker 1D character array**, providing a compact representation for efficient state comparison and hashing.

* **Graph-Based State Transitions:** Treats every cube configuration as a graph state and generates **18 standard face-turn operations** — clockwise, counter-clockwise, and 180° rotations across all six faces.

* **Optimal Shortest-Path Search:** Implements **Breadth-First Search (BFS)** to explore states level-by-level, guaranteeing a minimum-move solution while using **back-pointer state tracking** to reconstruct the solution sequence.

* **Hash-Based State Deduplication:** Uses a custom `Hash1d` functor with `unordered_map` for **average O(1) state lookup**, preventing repeated exploration of previously visited cube configurations.

* **Extensible Search Architecture:** Separates the cube representation from search algorithms using an abstract `RubiksCube` interface, allowing **BFS, depth-limited DFS, and IDDFS** to operate on the same underlying cube model and be benchmarked through a common driver.

# Tech Stack

* **Language:** C++17
* **Design:** Object-Oriented Programming
* **Concepts:** Graph Theory, State-Space Search, Hashing, Recursion, Backtracking, BFS, DFS, IDDFS
* **Data Structures:** `queue`, `unordered_map`, `vector`

# Architecture & Algorithms

The solver represents the Rubik's Cube as a discrete state graph:

**Cube State → Generate 18 Moves → New Cube States → Search → Solution Path**

### BFS — Breadth-First Search

Explores the state space level-by-level. Since every move has equal cost, BFS guarantees the **shortest solution in number of moves**. A back-pointer map records how each discovered state was reached, allowing the final solution path to be reconstructed.

### DFS — Depth-Limited Depth-First Search

Explores one branch deeply before backtracking and uses a configurable depth limit to prevent unbounded traversal. It has low auxiliary memory usage but **does not guarantee a shortest solution**.

### IDDFS — Iterative Deepening DFS

Repeatedly executes depth-limited DFS with increasing depth limits. This can find an **optimal-depth solution** while retaining DFS's low memory requirements, at the cost of repeatedly exploring states across iterations.

# Benchmarking

The command-line driver supports:

1. **BFS**
2. **Depth-Limited DFS**
3. **IDDFS**
4. **Benchmarking all three approaches**

For each solver, the program reports the **solution length** and **execution time**, allowing direct comparison of search behavior and performance.

# Getting Started

## Prerequisites

* GCC / Clang / MSVC
* C++17 or later

## Build

```bash
g++ -std=c++17 main.cpp RubiksCube.cpp -o rubiks
```

## Run

On Windows:

```bash
rubiks.exe
```

The program allows you to choose the number of scramble moves and select **BFS, DFS, IDDFS, or benchmark all three algorithms**.
# Rubik's Cube Solver: State-Space Search Engine

An extensible state-space search engine in C++ that models a Rubik's Cube as a graph of discrete configurations. Each cube state represents a node, while legal face rotations form the edges, enabling systematic exploration of the state space to find solution sequences from scrambled configurations.

# Core Features

* **Compact 1D State Representation:** Models the complete cube using a **54-sticker 1D character array**, providing a compact representation for efficient state comparison and hashing.

* **Graph-Based State Transitions:** Treats every cube configuration as a graph state and generates **18 standard face-turn operations** — clockwise, counter-clockwise, and 180° rotations across all six faces.

* **Optimal Shortest-Path Search:** Implements **Breadth-First Search (BFS)** to explore states level-by-level, guaranteeing a minimum-move solution while using **back-pointer state tracking** to reconstruct the solution sequence.

* **Hash-Based State Deduplication:** Uses a custom `Hash1d` functor with `unordered_map` for **average O(1) state lookup**, preventing repeated exploration of previously visited cube configurations.

* **Extensible Search Architecture:** Separates the cube representation from search algorithms using an abstract `RubiksCube` interface, allowing **BFS, depth-limited DFS, and IDDFS** to operate on the same underlying cube model and be benchmarked through a common driver.

# Tech Stack

* **Language:** C++17
* **Design:** Object-Oriented Programming
* **Concepts:** Graph Theory, State-Space Search, Hashing, Recursion, Backtracking, BFS, DFS, IDDFS
* **Data Structures:** `queue`, `unordered_map`, `vector`

# Architecture & Algorithms

The solver represents the Rubik's Cube as a discrete state graph:

**Cube State → Generate 18 Moves → New Cube States → Search → Solution Path**

### BFS — Breadth-First Search

Explores the state space level-by-level. Since every move has equal cost, BFS guarantees the **shortest solution in number of moves**. A back-pointer map records how each discovered state was reached, allowing the final solution path to be reconstructed.

### DFS — Depth-Limited Depth-First Search

Explores one branch deeply before backtracking and uses a configurable depth limit to prevent unbounded traversal. It has low auxiliary memory usage but **does not guarantee a shortest solution**.

### IDDFS — Iterative Deepening DFS

Repeatedly executes depth-limited DFS with increasing depth limits. This can find an **optimal-depth solution** while retaining DFS's low memory requirements, at the cost of repeatedly exploring states across iterations.

# Benchmarking

The command-line driver supports:

1. **BFS**
2. **Depth-Limited DFS**
3. **IDDFS**
4. **Benchmarking all three approaches**

For each solver, the program reports the **solution length** and **execution time**, allowing direct comparison of search behavior and performance.

# Getting Started

## Prerequisites

* GCC / Clang / MSVC
* C++17 or later

## Build

```bash
g++ -std=c++17 main.cpp RubiksCube.cpp -o rubiks
```

## Run

On Windows:

```bash
rubiks.exe
```

The program allows you to choose the number of scramble moves and select **BFS, DFS, IDDFS, or benchmark all three algorithms**.
