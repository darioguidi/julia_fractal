Julia Fractal Explorer

Interactive Julia Set Fractal Renderer written in C using SDL2

An interactive application for real-time visualization of Julia fractals.
The program allows exploration of different Julia sets by manipulating complex numbers on the Gauss complex plane, providing smooth and efficient rendering via SDL2.

✨ Features

Real-Time Rendering
Dynamic computation of the iterative formula:

zₙ₊₁ = zₙ² + c


Interactive Exploration

Mouse dragging to inspect complex point trajectories

Real-time updates of the fractal structure

Mathematical Presets

Multiple predefined values of the complex constant c

Selection via command-line arguments

Magma Color Effect

Custom coloring algorithm

Based on the Escape Time Algorithm

Volcanic-style gradient visualization

Manual Memory Management

Dynamic linked lists to track complex values

Explicit malloc() / free() usage

Memory-leak–safe implementation

🧮 Mathematical Background

The Julia set is generated using the recursive formula:

zₙ₊₁ = zₙ² + c


Where:

z is a complex number in the Gauss plane

c is a fixed complex constant defining the fractal shape

If |z| > 4, the sequence diverges and the point is considered outside the set

🛠️ Tech Stack

Language: C (ISO Standard)

Graphics: SDL2

Math: Complex numbers & numerical computation

Data Structures: Dynamic arrays, linked lists

📁 Project Structure
.
├── main.c        # Application loop and SDL event handling
├── function.c    # Fractal computation and iteration logic
├── utility.c     # Window, renderer and pixel utilities
├── *.h           # Header files

⚙️ Build & Run
Requirements

GCC

SDL2 development libraries

Ubuntu / Debian

sudo apt-get install libsdl2-dev

Compilation
gcc main.c function.c utility.c -o JuliaFractal -lSDL2 -lm

Execution
./JuliaFractal

🚀 Performance Notes

Double nested loop on a 900x900 resolution grid

Optimized per-pixel iteration

Real-time rendering of thousands of points per frame

👨‍💻 Why This Project?

This project showcases:

Low-level programming skills
Manual memory handling and pointer-based data structures

Algorithmic thinking
Efficient implementation of iterative numerical methods

Applied mathematics
Practical translation of abstract mathematical concepts into working software

Graphics programming
Real-time rendering using a low-level multimedia library
