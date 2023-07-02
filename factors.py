#!/usr/bin/python3

import sys
import math

def factorize(number):
    factors = []
    for i in range(2, math.isqrt(number) + 1):
        if number % i == 0:
            factors.append((i, number // i))
    return factors

def factors(filename):
    with open(filename, 'r') as file:
        for line in file:
            number = int(line.strip())
            result = factorize(number)
            for factor in result:
                print(f'{number}={factor[0]}*{factor[1]}')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: factors <file>')
        sys.exit(1)

    filename = sys.argv[1]
    factors(filename)
