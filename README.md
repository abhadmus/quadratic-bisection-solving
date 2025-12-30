# Cubic Root Estimator in C

This is a C program that estimates one **real root** of a cubic polynomial  
`f(x) = ax³ + bx² + cx + d` using the **bisection method**. The root is calculated with a precision of `0.0001`, and the user can run the process multiple times with different inputs.

---

## Features

- Accepts any real coefficients for a cubic polynomial
- Uses a **range-aware** dynamic interval search
- Applies the **bisection method** to narrow in on a real root
- Automatically adjusts the interval range based on input magnitudes
- Provides results accurate to **four decimal places**
- Offers a **replay option** to try again without restarting the program

---

## What It Does

The program:
1. Prompts the user to enter the coefficients `a`, `b`, `c`, `d`
2. Estimates an initial interval `[-R, +R]` where a root may exist
3. Applies the **bisection method** to iteratively narrow the interval
4. Stops once the function values on the interval are within `0.0001` of each other
5. Displays the estimated root `x` such that `f(x) ≈ 0`

---

## How to Compile and Run

### Compile:
```bash
gcc root.c -o root -lm
```

> Note: `-lm` is required to link the math library for `fabs()`.

### Run:
```bash
./root
```

---

## Sample Interaction

```
************************************************
Welcome to the cubic root estimator.
This estimates the value of one root of
f(x) = ax^3 + bx^2 + cx + d.
************************************************
Enter the coefficients in the form 'a b c d': 1 -6 11 -6
There is a root at: x = 1.0000
Do you wish to try another quadratic [y/n]: y
...
```

---

## Algorithm Used

The **bisection method** is a root-finding algorithm that:
- Starts with a range `[l, u]` where the function changes sign
- Repeatedly evaluates the midpoint `m = (l + u)/2`
- Narrows the interval based on the sign of `f(m)`
- Continues until the interval difference is small (here, < 0.0001)

---

## Notes & Limitations

- Only **one real root** is found. If multiple real roots exist, only one is returned.
- The function assumes the existence of at least one real root within the calculated range.
- Interval range is dynamically scaled to `10 × max(|a|, |b|, |c|, |d|)` for robustness.
- Coefficients are assumed to be valid float inputs.
- Handles precision with basic float math, not guaranteed for edge-case behavior.

---

## Dependencies

Standard C libraries only:
- `stdio.h`
- `stdlib.h`
- `math.h`

---

## Exit Behavior

The program continues to run until the user chooses `'n'` when prompted to try again.