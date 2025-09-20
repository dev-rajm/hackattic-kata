import sys


def almost_binary(s: str) -> int:
    result = 0
    for ch in s:
        result <<= 1
        if ch == "#":
            result |= 1
        elif ch == ".":
            pass
        else:
            break
    return result


def main() -> None:
    for line in sys.stdin:
        line = line.strip()
        if line:
            print(almost_binary(line))
        else:
            break


if __name__ == '__main__':
    main()

