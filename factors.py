#!/usr/bin/env python3
import sys

def factorize(n):
    factors = []
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

if len(sys.argv) != 2:
    print("Usage: python factors.py <file>")
    sys.exit(1)

input_file = sys.argv[1]

try:
    with open(input_file, "r") as file:
        for line in file:
            num = int(line.strip())
            factors = factorize(num)
            if len(factors) == 2:
                p, q = factors
                print(f"{num}={p}*{q}")

except FileNotFoundError:
    print(f"File '{input_file}' not found.")
    sys.exit(1)
except ValueError:
    print("Invalid input in the file.")
    sys.exit(1)
