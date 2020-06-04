#include <iostream>
#include <locale.h>
//#include <cstdlib>
#include <windows.h>

using namespace std;

const int max_size = 3;
typedef float Data;

typedef struct Queue{
	int front, end, logic_size;
	Data vector[max_size];
}Queue;

/*
void insert(Queue &q, Data val, bool &ok){
	if(q.end == max_size)
		ok = false;
	else{
		ok = true;
		q.vector[q.end] = val;
		q.end++;
		q.logic_size++;
	}
}
*/

void insert(Queue &q, Data val, bool &ok){
	if((q.end == max_size) && (q.front == 0))
		cout << "Full" << endl;
	else{
		ok = true;
		q.vector[q.end] = val;
		q.end++;
		q.logic_size++;
	}
}




void remove(Queue &q, bool &ok){
	if(q.end == 0)
		ok = false;
	else{
		ok = true;
		q.front++;
		q.logic_size--;
	}
}


Data search(Queue q, bool &ok){
	if(q.end == 0)
		ok = false;
	else{
		ok = true;
		return q.vector[q.front];
	}		
}


void show_queue(Queue q, bool &ok){
	if(q.end == 0)
		ok = false;
	else{
		ok = true;
		for(int i = q.front; i < q.end; i++)
			cout << q.vector[i] << " ";
	}
}
 

main(){
	setlocale(LC_ALL, "Portuguese");
	bool ok;
	Queue queue;
	queue.front = 0;
	queue.end = 0;
	queue.logic_size = 0;
	
	Data value_to_insert;
	int option;
	
	while(option != 5){
	system("cls");
	
	cout << "  1  INSERT  \n  2  REMOVE  \n  3  ACCESS  \n  4  SHOW QUEUE  \n  5  QUIT";	
	cout << "  \nWhat would you like to do? ";
	cin >> option;
	switch(option){
		case 1:
		cout << "Value to insert: ";
		cin >> value_to_insert;
		insert(queue, value_to_insert, ok);
			break;
		
		case 2:
			remove(queue, ok);
			
			Sleep(5000);
			break;
		
		case 3:
			search(queue, ok);
			
			if(ok ==  false)
				cout << "Empty queue!" << endl;
			else
				cout << search(queue, ok) << endl;
		
		case 4:
			show_queue(queue, ok);
			if(ok == false)
				cout << "Empty queue!" << endl;
			Sleep(2000);
			break;
		
		default:
			cout << "Invalid option!" << endl;
			break;
	}
	if(!cin)
		break;
	}		
	system("Pause");
}
