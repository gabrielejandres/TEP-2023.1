# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 1 | Problema E | Make it Divisible by 25


def calculate_min_removed(string):
    size = len(string)
    min_removed = size
    for i in range(size):
        for j in range(i + 1, size):
            num = int(string[i] + string[j])
            if num % 25 == 0:
                min_removed = min(min_removed, (j - i - 1) + (size - 1 - j))
    print(str(min_removed))


def main():
    cases = int(input())
    for _ in range(cases):
        string = input().strip()
        calculate_min_removed(string)


if __name__ == '__main__':
    main()
