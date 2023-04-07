# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 1 | Problema F | Save more mice


def calculate_max_saved_mice(hole_position, qt_mice, mice):
    mice.sort(reverse = True)
    cat_position = 0
    saved_mice = 0
    for i in range(qt_mice):
        if cat_position < mice[i]:
            cat_position += hole_position - mice[i] # a posicao do gato vai avancar ate que o rato da posicao i chegue no buraco
            saved_mice += 1
        else:
            break
    print(saved_mice)


def main():
    cases = int(input())
    for _ in range(cases):
        hole_position, qt_mice = input().split()
        mice = [int(num) for num in input().split()]
        calculate_max_saved_mice(int(hole_position), int(qt_mice), mice)
        

if __name__ == '__main__':
    main()
