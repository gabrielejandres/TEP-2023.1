# Topicos Especiais em Programacao | UFRJ | 2023.1
# Gabriele Jandres Cavalcanti | 119159948
# Aula 1 | Problema D | Elections


def calculate_votes_difference(votes):
    max_votes = max(votes)
    differences = []
    repeated = votes.count(max_votes)
    for vote in votes:
        if max_votes == vote and repeated > 1:
            differences.append("1")
        elif max_votes == vote:
            differences.append("0")
        else:
            differences.append(str(max(votes) - vote + 1))
    print(' '.join(differences))


def main():
    cases = int(input())
    for _ in range(cases):
        votes = [int(candidate_votes)
                 for candidate_votes in input().split()]
        calculate_votes_difference(votes)


if __name__ == '__main__':
    main()
