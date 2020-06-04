#include <iostream>
#include <locale.h>
#include <cstdlib>

using namespace std;

typedef float Data;

typedef struct Queue{
	Data value;
	Queue *next;
}Queue;

typedef Queue *ptqueue;

typedef struct Desc{
	ptqueue front;
	ptqueue end;
}Desc;



void insert(Desc &q, Data val){
	ptqueue temp;
	temp = new Queue;
	temp->value = val;
	temp->next = NULL;
	
	if(q.front == NULL)
		q.front = temp;
	
	else
		q.end->next = temp;
	
	q.end = temp;
}

void remove(Desc &q, bool &ok){
	if(q.front == NULL)
		ok = false;
	else{
		q.front = q.front->next;
		if(q.front == NULL)
			q.end = NULL;
	}
		
}

void print_queue(Desc q, bool &ok){
	if(q.front == NULL)
		ok = false;
	else{
		while(q.front != NULL){
			cout << q.front->value << "  ";
			q.front = q.front->next;
		}
		cout << "\n" << endl;
	}
}

main(){
	setlocale(LC_ALL, "Portuguese");
	Desc queue;
	queue.front = NULL;
	queue.end = NULL;
	
	bool ok = true;
	
	insert(queue, 10);
	insert(queue, 20);
	insert(queue, 30);
	
	remove(queue, ok);
	remove(queue, ok);
	remove(queue, ok);

	print_queue(queue, ok);
		
	system("Pause");
}








