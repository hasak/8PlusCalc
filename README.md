# 8PlusCalc

A series of C programs designed to multiply **two 8-byte integers** (up to `2^64-1`) into a larger number using **manual digit handling**, simulating how multiplication is done by hand.

This project explores different approaches to **big number multiplication** in C, from a naive method to more optimized and adaptive versions.


## Versions Overview

### **v1.0 – Naive Hand-Calculation**
- Stores each digit of the two numbers in arrays.
- Multiplies every digit with every digit, like pen-and-paper multiplication.
- Handles carry-over after summing all partial products.
- **Pros:** Clear, easy to understand, educational.
- **Cons:** Verbose and slower for large numbers.


### **v2.0 – Optimized Hand-Calculation**
- Improves speed by:
  - Counting digits using `log10()` instead of looping through the number.
  - Handling carry while multiplying (fewer loops and intermediate steps).
- **Pros:** Faster than v1, fewer temporary arrays.
- **Cons:** Slightly less intuitive for beginners; relies on `math.h`.


### **v3.0 – Split-10^10 Method**
- Divides numbers into **10-digit blocks**.
- Computes partial products using `pow(10,10)` and sums them with proper shifting.
- Reduces the need for large arrays to store digits.
- **Pros:** Much faster and memory-efficient.
- **Cons:** Hardcoded block size (`10^10`) limits portability.


### **v4.0 – Adaptive Splitting**
- Dynamically calculates the optimal split size based on system `long long int`.
- Uses a custom `expp()` function instead of `pow()` for integer accuracy.
- Handles carry between blocks automatically.
- **Pros:** Fully adaptive, efficient, and robust for any system.
- **Cons:** Slightly more complex code structure.


## Example

```text
Enter two 8-byte numbers (max 18446744073709551615)
123456789012345678 987654321098765432
Result: 121932631137021795223746380111126976
```


## Comparison

| Version | Approach               | Complexity       | Memory Use | Notes |
|---------|-----------------------|----------------|------------|-------|
| v1.0    | Array of digits       | O(n*m)         | High       | Educational, slow |
| v2.0    | Array + carry in loop | O(n*m) faster  | Medium     | Optimized, fewer steps |
| v3.0    | Block splitting       | O(1) per block | Low        | Very fast, limited by fixed block |
| v4.0    | Adaptive blocks       | O(1) per block | Low        | Portable, scalable, professional |

