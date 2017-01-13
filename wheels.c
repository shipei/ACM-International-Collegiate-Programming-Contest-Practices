#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef State_h
#define State_h
struct State {
        int a;
        int b;
        int c;
        int d;
      };
#endif

int isEqual(struct State s1, struct State s2) {
  if(s1.a == s2.a && s1.b == s2.b && s1.c == s2.c && s1.d == s2.d)
    return 0;
  else
    return 1;
}

struct State deepCopy(struct State s) {
  struct State new_state;
  new_state.a = s.a;
  new_state.b = s.b;
  new_state.c = s.c;
  new_state.d = s.d;
  return new_state;
}

struct State * adjacent(struct State curr) {
  static struct State adj[8];
  struct State a1 = deepCopy(curr);
  if(a1.a == 9) {
    a1.a = 0;
  }
  else {
    a1.a = curr.a+1;
  }
  adj[0] = a1;
  struct State a2 = deepCopy(curr);
  if(a2.a == 0) {
    a2.a = 9;
  }
  else {
    a2.a = curr.a-1;
  }
  adj[1] = a2;
  struct State a3 = deepCopy(curr);
  if(a3.b == 9) {
    a3.b = 0;
  } else {
    a3.b = curr.b+1;
  }
  adj[2] = a3;
  struct State a4 = deepCopy(curr);
  if(a4.b == 0) {
    a4.b = 9;
  } else {
    a4.b = curr.b-1;
  }
  adj[3] = a4;
  struct State a5 = deepCopy(curr);
  if(a5.c == 9) {
    a5.c = 0;
  } else {
    a5.c = curr.c+1;
  }
  adj[4] = a5;
  struct State a6 = deepCopy(curr);
  if(a6.c == 0) {
    a6.c = 9;
  } else {
    a6.c = curr.c-1;
  }
  adj[5] = a6;
  struct State a7 = deepCopy(curr);
  if(a7.d == 9) {
    a7.d = 0;
  } else {
    a7.d = curr.d+1;
  }
  adj[6] = a7;
  struct State a8 = deepCopy(curr);
  if(a8.d == 0) {
    a8.d = 9;
  } else {
    a8.d = curr.d-1;
  }
  adj[7] = a8;
  return adj;
}

int hash(struct State s) {
  return s.a * 1000 + s.b * 100 + s.c * 10 + s.d;
}

#ifndef Queue_h
#define Queue_h

struct Queue {
  struct State array[10000];
  int front;
  int rear;
  int itemCount;
};
#endif

struct State peek(struct Queue *Q) {
   return Q->array[Q->front];
}

bool isEmpty(struct Queue *Q) {
   return Q->itemCount == 0;
}

int size(struct Queue *Q) {
   return Q->itemCount;
}

bool isFull(struct Queue *Q) {
   return Q->itemCount == 10000;
}

void enqueue(struct Queue *Q, struct State s) {
  if(!isFull(Q)) {
    if(Q->rear == 10000-1) {
      Q->rear = -1;
    }
    Q->rear += 1;
    Q->array[Q->rear] = s;
    Q->itemCount += 1;
  }
}

struct State dequeue(struct Queue *Q) {
   struct State s = Q->array[Q->front++];
   if(Q->front == 10000) {
      Q->front = 0;
   }
   Q->itemCount--;
   return s;
}


int bfs(struct State init, struct State target, int visited[10000]) {
  if(isEqual(init, target) == 0) return 0;
  else {
    int steps = 1;
    int curNum = 1;
    int nextNum = 0;
    struct Queue *Q = malloc(sizeof(struct Queue));
    Q->front = 0;
    Q->rear = -1;
    Q->itemCount = 0;
    enqueue(Q, init);
    visited[hash(init)] = 1;
    while(!isEmpty(Q)) {
      struct State a = dequeue(Q);
      curNum--;
      int i;
      for(i = 0; i < 8; i++) {
        struct State *adj;
        adj = adjacent(a);
        if(visited[hash(*(adj+i))] == 1) {
        }
        else {
          if(isEqual(*(adj+i), target) == 0) {
            return steps;
          } else {
            nextNum++;
            enqueue(Q, *(adj+i));
            visited[hash(*(adj+i))] = 1;
          }
        }
      }
      if(curNum == 0) {
        curNum = nextNum;
        nextNum = 0;
        steps++;
      }
    }
  }
  return -1;
}

int main() {
  int cases;
  scanf("%d", &cases);
  int result[cases];
  int x = 0;
  while(cases--) {
    int s1, s2, s3, s4;
    struct State init;
    scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
    init.a = s1;
    init.b = s2;
    init.c = s3;
    init.d = s4;
    int t1, t2, t3, t4;
    struct State target;
    scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
    target.a = t1;
    target.b = t2;
    target.c = t3;
    target.d = t4;
    int forbidden_num, i;
    scanf("%d", &forbidden_num);
    int visited[10000] = {0};
    for(i = 0; i < forbidden_num; i++) {
      int f1, f2, f3 ,f4;
      struct State forbidden;
      scanf("%d %d %d %d", &f1, &f2, &f3, &f4);
      forbidden.a = f1;
      forbidden.b = f2;
      forbidden.c = f3;
      forbidden.d = f4;
      visited[hash(forbidden)] = 1;
    }
    result[x] = bfs(init, target, visited);
    x++;
  }
  int i;
  for(i = 0; i < x; i++) {
    printf("%d\n", result[i]);
  }
  return 0;
}
