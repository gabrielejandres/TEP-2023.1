/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 2 | Problema C | Team Queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ********* ESTRUTURAS ********* */ 

/* Estrutura de um nó da lista encadeada */
typedef struct node {
  int key; // valor de um elemento do time
  int team_index; // índice do time ao qual pertence
  struct node *next; // aponta para o próximo nó
} node;

/* Estrutura de um time */
typedef struct team {
  int num_elements; // quantidade de elementos de um time
  int *elements; // array de elementos de um time
  node *last_element_queue; // aponta para o último elemento do time na fila
} Team;

/* Estrutura da fila */
typedef struct queue {
    int num_of_teams; // número de times que existem na fila
    node *head; // primeiro nó da fila
    node *tail; // último nó da fila
} queue;

/* ********* FUNÇÕES ********* */ 

/* Função para imprimir os valores de uma fila */
void printQueue(queue *q) {
    node *n = q->head;
    printf("Fila: \n");
    printf("%d \n", n->key);
    while(n->next != NULL) {
      printf("%d \n", n->next->key);
      n = n->next;
    }
}

/* Função para buscar o time de um elemento */
int searchTeamOfAnElement(int element, Team *teams, int num_teams) {
    for(int i = 0; i < num_teams; i++) {
      for(int j = 0; j < teams[i].num_elements; j++){
        if (element == teams[i].elements[j]){
          return i; 
        }
      }
    }
    return -1;
}

/* Função para criar um novo nó da lista encadeada */
struct node* newNode(int value, int team_index)
{
    struct node* tmp = (struct node*) malloc(sizeof(struct node));

    if (tmp == NULL) {
        printf("Erro ao criar novo no. Falta memoria");
        exit(1);
    }

    tmp->key = value;
    tmp->team_index = team_index;
    tmp->next = NULL;

    return tmp;
}

/* Função para criar e inicializar uma fila vazia */
queue* createQueue(int num_of_teams) {
  queue *q = (queue*) malloc(sizeof(queue));

  if (q == NULL) {
    printf("Erro ao inicializar fila. Falta memoria");
    exit(1);
  }

  q->num_of_teams = num_of_teams;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

/* Função para adicionar um elemento na fila */
void enqueue(queue *q, int value, int team_index, Team *teams) { 
  // Cria um novo nó da lista encadeada
  node *tmp = newNode(value, team_index); 

  // Se a fila está vazia, o novo nó é a cabeça e cauda da fila
  if (q->tail == NULL) {
      q->head = q->tail = tmp;
      teams[team_index].last_element_queue = tmp;
      return;
  }

  // Se houver alguém do time do novo elemento na fila, ele deve entrar logo atrás
  if(teams[team_index].last_element_queue != NULL && teams[team_index].last_element_queue->team_index == team_index) {

    // Se o último elemento do time for a cauda, o novo elemento deve assumir essa posição de cauda da fila
    if(q->tail == teams[team_index].last_element_queue) {
      q->tail = tmp; 
    }

    // Armazeno qual era o nó que estava após o último desse time na fila
    node *next = teams[team_index].last_element_queue->next;

    // O novo elemento entra na frente do antigo próximo
    tmp->next = next;

    // O elemento entra logo atrás do último elemento de seu time na fila
    teams[team_index].last_element_queue->next = tmp;

    // Adiciono o endereço do meu novo nó como o último daquele time ao qual pertence na fila
    teams[team_index].last_element_queue = tmp;
  } else { 
      // Se não tiver ninguém do time do novo elemento ele é inserido no fim da fila
      q->tail->next = tmp; // adiciona o novo no no fim da fila
      q->tail = tmp; // muda a cauda
      teams[team_index].last_element_queue = tmp; // atualiza o último nó da fila
  }
}

/* Função para remover um elemento da fila */
int dequeue(queue *q, Team *teams) {
  int element;

  // Se a fila tiver vazia, não tem o que remover
  if (q->head == NULL) exit(1);
  
  // Remove o primeiro da fila e coloca o próximo como cabeça
  node *tmp = q->head;
  element = tmp->key;

  // Se a cabeça for igual à cauda quer dizer que cheguei ao fim da fila
  if(q->head == q->tail) {
    q->head = q->tail = NULL;
    teams[tmp->team_index].last_element_queue = NULL;
    return element;
  }

  // Atualizo a cabeça da lista
  q->head = q->head->next;

  // Atualiza o endereço do último nó do time na fila
  if(teams[tmp->team_index].last_element_queue == tmp) {
    if(tmp->team_index == tmp->next->team_index) {
      teams[tmp->team_index].last_element_queue = tmp->next;
    } else {
      teams[tmp->team_index].last_element_queue = NULL;
    }
  }
  
  // Se a cabeça é nula, a cauda também (a fila está vazia nesse caso)
  if (q->head == NULL) q->tail = NULL;

  free(tmp);
  return element;
}

/* Função principal */
int main(int argc, char *argv[ ]){

  int t;
  int scenario = 1;
  scanf("%d",&t);

  // Vou ler as entradas enquanto a quantidade de times for diferente de 0
  while(t != 0) {

    printf("Scenario #%d\n", scenario);

    // Para cada leva de entrada de times, vou criar uma fila diferente
    queue *teamQueue = createQueue(t);

    Team teams[t]; // array para armazenar as structs de times
    char command[10]; // string para armazenar os comandos de ação para a fila

    // Para cada um dos times, vou ler a quantidade de elementos e adicioná-los em um array
    for(int i = 0; i < t; i++) {
      int num_elements;
      scanf("%d",&num_elements);

      // Criando uma nova estrutura de times
      Team team;
      team.num_elements = num_elements;
      team.elements = (int*) malloc(num_elements * sizeof(int));
      team.last_element_queue = NULL; // ainda não há ninguém na fila

      // Lendo os elementos de um time
      for(int j = 0; j < num_elements; j++){
        int element;
        scanf("%d",&element);
        team.elements[j] = element;
      }

      // Adicionando o novo time lido ao array de times
      teams[i] = team;
    }

    // Leitura do comando de ação
    getchar();
    scanf("%s",command);

    while(strcmp(command,"STOP") != 0){
      if(strcmp(command,"ENQUEUE") == 0){
        int element;
        scanf("%d",&element);
        int team_index = searchTeamOfAnElement(element, teams, t);
        if(team_index != -1) enqueue(teamQueue, element, team_index, teams); // se o elemento não tiver time a função retorna -1
      } 
      else{
        int id = dequeue(teamQueue, teams);
        printf("%d\n", id);
      }
      scanf("%s",command);
    }

    // Lendo a próxima quantidade de membros do time
    scanf("%d",&t);

    printf("\n");
    scenario++;
    free(teamQueue);
  }

  return 0;
}

