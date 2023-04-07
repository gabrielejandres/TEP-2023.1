# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 1 | Problema G | Vlad and Candies


def check_vlad_can_eat(qt_candies, candies):
    max_num = max(candies)
    candies.remove(max_num)
    if (qt_candies - 1) != 0:
        second_max_num = max(candies)
    elif max_num > 1:
        return False
    else:
        return True
    return True if max_num - second_max_num <= 1 else False


def main():
    cases = int(input())
    for _ in range(cases):
        qt_candies = int(input())
        candies = [int(num) for num in input().split()]
        can_eat = check_vlad_can_eat(qt_candies, candies)
        print('YES' if can_eat else 'NO')


if __name__ == '__main__':
    main()

