# ifndef DEQUE_H
# define DEQUE_H



class Deque{
	int count;
	class node *head;
public:
	Deque(); 
	~Deque(); 
	int size();
	void addFirst(int x); 
	void addLast(int x); 
	int removeFirst();
	int removeLast();
	int getFirst();
	int getLast();
};

# endif /* DEQUE_H */
