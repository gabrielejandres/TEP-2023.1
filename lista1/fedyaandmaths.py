# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 1 | Problema A | Fedya and Maths


def calculate_mod_5(num):
    result = 4 if num % 4 == 0 else 0 # todos os numeros que forem multiplos de 4 vao deixar resto 1 quando fizermos x^n, onde x = {1, 2, 3, 4}, quando fizermos a soma deles mod 5, o resultado sera 4, todos os outros casos a soma mod 5 sera 0
    print(result)


def main():
    num = int(input())
    calculate_mod_5(num)


if __name__ == '__main__':
    main()

