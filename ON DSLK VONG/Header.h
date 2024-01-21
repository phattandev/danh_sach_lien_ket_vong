#include <iostream>
using namespace std;

typedef int typeinfo;
struct Node {
	typeinfo data;
	Node* link;
};

typedef Node* Nodeptr;
typedef struct CircularLinkedList {
	Nodeptr head, tail;
}CLL;

void init(CLL& l);
bool isEmpty(CLL l);
Nodeptr makeNode(typeinfo x);
void addFirst(CLL& l, typeinfo x);
void addLast(CLL& l, typeinfo x);
void addLast(CLL& l, typeinfo x);
void deleteBegin(CLL& l);
void deleteEnd(CLL& l);
void print(CLL l);
Nodeptr findX(CLL l, typeinfo x);
void deleteMid(CLL& l);
void addAfter(CLL& l);
void addBefore(CLL& l);