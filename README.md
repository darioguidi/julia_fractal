# Julia Fractal Explorer
> Personal project developed entirely by **Dario Guidi**
Interactive Julia Set Fractal Renderer written in **C** using **SDL2**.

An interactive application for real-time visualization of Julia fractals.
The program allows exploration of different Julia sets by manipulating complex
numbers on the Gauss complex plane, with smooth real-time rendering via SDL2.

---

## Features

- Real-time rendering of the iterative formula:
  ```
  z(n+1) = z(n)^2 + c
  ```

- Interactive exploration
  - Mouse dragging to inspect complex point trajectories
  - Real-time updates of the fractal

- Mathematical presets
  - Multiple predefined values of the complex constant `c`
  - Selection via command-line arguments

- Magma color effect
  - Custom coloring algorithm
  - Based on the Escape Time Algorithm
  - Volcanic-style gradient visualization

- Manual memory management
  - Dynamic linked lists to track complex values
  - Explicit malloc() / free() usage
  - Memory-leak–safe implementation

---

## Mathematical Background

The Julia set is generated using the recursive formula:

```
z(n+1) = z(n)^2 + c
```

Where:
- z is a complex number in the Gauss plane
- c is a fixed complex constant defining the fractal shape
- If |z| > 4, the sequence diverges and the point is considered outside the set

---

## Tech Stack

- Language: C (ISO Standard)
- Graphics: SDL2
- Mathematics: Complex numbers and numerical computation
- Data Structures: Dynamic arrays and linked lists

---

## Project Structure

```
.
├── main.c
├── function.c
├── utility.c
├── *.h
```

- main.c: Application loop and SDL event handling
- function.c: Fractal computation and iteration logic
- utility.c: Window, renderer and pixel utilities

---

## Build and Run

### Requirements

- GCC
- SDL2 development libraries

Ubuntu / Debian:

```bash
sudo apt-get install libsdl2-dev
```

---

### Compilation

```bash
gcc main.c function.c utility.c -o JuliaFractal -lSDL2 -lm
```

---

### Execution

```bash
./JuliaFractal
```

---

## Performance Notes

- Double nested loop on a 900x900 resolution grid
- Optimized per-pixel iteration
- Real-time rendering of thousands of points per frame

---

## Why This Project?

This project demonstrates:

- Low-level programming and manual memory management in C
- Efficient implementation of iterative numerical algorithms
- Applied mathematics translated into working software
- Real-time graphics programming with SDL2

---

## License

MIT License
