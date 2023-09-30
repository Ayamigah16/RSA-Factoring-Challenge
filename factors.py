import sys

def factorize(number):
    # Start with the smallest possible factor
    factor = 2
    factors = []

    # Find all factors of the number
    while factor * factor <= number:
        if number % factor:
            factor += 1
        else:
            number //= factor
            factors.append(factor)

    if number > 1:
        factors.append(number)

    return factors

def main():
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        return

    filename = sys.argv[1]

    with open(filename, 'r') as file:
        lines = file.readlines()

    for line in lines:
        number = int(line.strip())
        factors_list = factorize(number)

        if len(factors_list) == 2:
            print(f"{number}={factors_list[0]}*{factors_list[1]}")

if __name__ == "__main__":
    main()

