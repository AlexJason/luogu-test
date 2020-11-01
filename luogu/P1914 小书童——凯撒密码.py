def main():
    n = int(input())
    s = input()
    for c in s:
        print(chr((ord(c) - 97 + n) % 26 + 97), end='')
    return 0
    
if __name__ == "__main__":
    main()