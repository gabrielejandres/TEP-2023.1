# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 2 | Problema G | Alice and the Cake

import heapq
import math

def check_if_is_a_cake(num_pieces, pieces):
    if num_pieces == 1:
        print("YES")
        return 
    
    piece_weight = sum(pieces)
    queue = []
    heapq.heappush(queue, piece_weight)
    while len(queue) < num_pieces:
        current_piece = queue[0]
        heapq.heappop(queue)
        fl = math.floor(current_piece / 2)
        cl = math.ceil(current_piece / 2)
        if fl in pieces:
            pieces.remove(fl)
            num_pieces -= 1
        else:
            heapq.heappush(queue, fl)
        if cl in pieces:
            pieces.remove(cl)
            num_pieces -= 1
        else:
            heapq.heappush(queue, cl)
            
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