# IE-0117 - Lab 3: Matrix Operations in C

This repository contains the solutions to **Lab 3** of the course **IE-0117**, implemented in the C programming language. The exercises focus on:

- Working with square matrices.
- Input validation.
- Diagonal analysis.
- Random matrix generation.

##  Project Structure

```
.
├── Ejercicio1.c       # Sum of both diagonals in a square matrix
├── Ejercicio2.c       # Find the maximum value in a matrix
├── Ejercicio3.c       # Find the longest diagonal sequence of 1s in a binary matrix
├── README.md          # This documentation
└── (other lab files)  # Source code, LaTeX report, etc.
```

## ⚙Requirements

Make sure you have the GCC compiler installed.

```bash
gcc --version
```

If not installed, use:

```bash
sudo apt install build-essential
```

---

##  Compilation and Execution

###  Exercise 1 – Diagonal Sum

```bash
gcc Ejercicio1.c -o ejercicio1
./ejercicio1
```

###  Exercise 2 – Maximum Value

```bash
gcc Ejercicio2.c -o ejercicio2
./ejercicio2
```

### Exercise 3 – Longest Diagonal of 1s

```bash
gcc Ejercicio3.c -o ejercicio3
./ejercicio3
```

> Note: In Exercise 3, the size of the matrix can be changed in the `#define SIZE` directive or by modifying input prompts depending on the implementation.

---

##  Report

A full report is included in the repository, describing:

- The logic and pseudocode behind each exercise.
- Code explanations and validation mechanisms.
- Screenshots of the results and randomly generated matrices.

---

## Author

Developed by Jafet Cruz for the IE-0117 course.
