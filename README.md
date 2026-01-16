# Index for Password Strength a.k.a IPS (C++)
## Overview
Index for Password Strength (IPS) is a C++ command-line program that evaluates
the strength of a user-provided password using a custom scoring system. The
program analyzes multiple security factors and produces both a numerical score
and specific feedback on weaknesses.

This project was developed as part of C++ coursework and demonstrates
practical use of core C++ concepts including STL containers, string processing,
loops, conditionals, and algorithmic reasoning.

## Features
- Enforces password length constraints (8-15 chars)
- Evaluates 4 independent security factors:
   - Character Diversity
   - Length
   - Repitition
   - Sequential & Structural Complexity
- Outputs:
   - Individual Factor Scores (out of 100)
   - Final IPS Score (out of 100)
   - Clear explainations of detected weaknesses
 
## Technologies Used
- Language: C++
- Libraries: iostream, vector, string, algorithm, cmath
- Concepts: STL usage, input validation, scoring algorithms, security logic

## How it Works
The IPS score is computed by averaging four factors:
  1. Basic Factor – checks for lowercase, uppercase, numeric, and special characters
  2. Length Factor – rewards longer passwords within the valid range
  3. Repetition Factor – penalizes repeated characters
  4. Complexity Factor – rewards variation and penalizes predictable patterns
Each factor is scored independently out of 100.

## How to Run (Online Compiler)
  1. Go to https://www.programiz.com/cpp-programming/online-compiler/
  2. Copy and paste the code in `ips.cpp`
  3. Run the program, it will prompt you for a password and provides feedback on it

## How to Run (C++ Compiler)
  1. Compile the `ips.cpp` Program (Make sure to use a C++ compiler), for exp: `g++ ips.cpp -o ips`
  2. Run the program: `./ips`
  3. The program will prompt with you a password and provides feedback on it
  
