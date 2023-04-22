# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 2 | Problema G | Alice and the Cake

import heapq
import math

def check_if_is_a_cake(num_pieces, pieces):
    if num_pieces == 1:
        print("YES")
        return 
    
    piece_weight = 0
    aux = {}
    for i in range(num_pieces):
        piece_weight += pieces[i]
        if pieces[i] in aux:
            aux[pieces[i]] += 1
        else:
            aux[pieces[i]] = 1
            
    queue = []
    heapq.heappush(queue, piece_weight)
    while len(queue) < num_pieces:
        current_piece = queue[0]
        heapq.heappop(queue)
        fl = math.floor(current_piece / 2)
        cl = math.ceil(current_piece / 2)
        if fl in aux and aux[fl] > 0:
            aux[fl] -= 1
            num_pieces -= 1
        else:
            heapq.heappush(queue, fl)
        if fl in aux and aux[fl] == 0:
            aux.pop(fl)
        if cl in aux and aux[cl] > 0:
            aux[cl] -= 1
            num_pieces -= 1
        else:
            heapq.heappush(queue, cl)
        if cl in aux and aux[cl] == 0:
            aux.pop(cl)
            
    if len(queue) == 0:
        print("YES")
    else:
        print("NO")

def main():
    cases = int(input())
    for _ in range(cases):
        num_pieces = int(input())
        pieces = [int(piece) for piece in input().split()]
        check_if_is_a_cake(num_pieces, pieces)


if __name__ == '__main__':
    main()