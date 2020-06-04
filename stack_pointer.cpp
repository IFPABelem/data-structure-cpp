#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

typedef int Data;

typedef struct Stack{
	Data top;
	Stack *next;
} Stack;


typedef Stack *pts;


void push(pts &s, Data val){
	pts temp;
	temp = new Stack;
	temp->top = val;
	if(s == NULL)
		temp->next = NULL;
		
	else
		temp->next = s;
	s = temp;
}


void pop(pts &s, bool &ok){
	pts temp;
	temp = new Stack;
	if(s == NULL)
		ok = false;
	else{
		ok = true;
		temp = s->next;
		free(s);
	}
	s = temp;
}

Data access(pts &s, bool &ok){
	pts temp;
	temp = new Stack;
	if(s == NULL)
		ok = false;
	else{
		return s->top;
	}
}


void print_stack(pts &s, bool &ok){
	pts temp;
	temp = new Stack;
	if(s == NULL)
		ok = false;
	else{
		ok = true;
		temp = s;
		while(temp != NULL){
			cout << temp->top << endl;
			temp = temp->next;
		}
	}
}


main(){
	setlocale(LC_ALL, "Portuguese");
	
	bool ok;
	pts stack;
	stack = new Stack;
	stack = NULL;
	
	int option;
	Data value_to_push;
	while(option != 5){
	system("cls");
	cout << "  1  PUSH  \n  2  POP  \n  3  ACCESS  \n  4  SHOW STACK  \n  5  QUIT \n";	
	cout << "  What would you like to do? ";
	cin >> option;
	switch(option){
		case 1:
		cout << "Value to insert at the top of the stack: ";
		cin >> value_to_push;
		push(stack, value_to_push);
			break;
		case 2:
		pop(stack, ok);
			break;
		case 3:
			access(stack, ok);
		if(ok == false)
			cout << "Not found!" << endl; 
		else
			cout << "Top element: " << access(stack, ok) << endl;
			break;
		case 4:
			print_stack(stack, ok);
			if(ok == false)
				cout << "Empty stack!" << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
			break;
	}
	if(!cin)
		break;
	Sleep(2000);
	}			
	system("Pause");
	
	
	
	
	
	
	system("Pause");
}

