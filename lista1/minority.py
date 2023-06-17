# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 1 | Problema G | Minority


def calculate_minority(string):
    qt_zeros = string.count('0')
    qt_ones = len(string) - qt_zeros
    minority = min(qt_zeros, qt_ones)
    if qt_zeros == qt_ones:
        print(str(qt_zeros - 1))
    else:
        print(str(minority))


def main():
    cases = int(input())
    for _ in range(cases):
        string = input()
        calculate_minority(string)


if __name__ == '__main__':
    main()