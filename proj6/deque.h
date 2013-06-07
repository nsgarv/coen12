# ifndef DEQUE_H
# define DEQUE_H

typedef struct node NODE;
typedef class deque DEQUE;
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

class deque{
	int count;
	class node *head;
public:
	Deque::Deque(); 
	Deque::~Deque(); 
	int Deque::size();
	void Deque::addFirst(int x); 
	void Deque::addLast(int x); 
	int Deque::removeFirst();
	int Deque::removeLast();
	int Deque::getFirst();
	int Deque::getLast();
};

# endif /* DEQUE_H */
