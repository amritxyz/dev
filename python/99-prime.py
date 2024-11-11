#!/bin/python3

def prime(num):
    if num <= 1:
        return False
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    return True

def main():
    print("Prime numbers between 1 and 100 are:")
    for num in range(1, 101):
        if prime(num):
            print(num, end=' ')
    print()

if __name__ == "__main__":
    main()
