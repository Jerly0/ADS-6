// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T arr[100];
  int fst, lst;
 public:
  TPQueue() : fst(0), lst(0) {}
  void push(T p) {
    int value = lst++;
    while ((--value >= fst) && (arr[value % size].prior < p.prior)) {
      arr[(value + 1) % size] = arr[value % size];
    }
    arr[(value + 1) % size] = p;
  }
  T pop() {
    return arr[(fst++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
