#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string>

using namespace std;

typedef float Data;
const int max_size = 10;

typedef struct Stack{
	int top_element;
	Data vector[max_size];
} Stack;



void Push(Stack &s, Data val){ // OBS: pq verificar se está vazia?
	//if(s.top_element == -1)
	//	ok = false;
	//else{
	//	ok =  true;
		s.top_element++;
		s.vector[s.top_element] = val;
	//}
}


void Pop(Stack &s, bool &ok){
	if(s.top_element == -1)
		ok = false;
	else{
		ok = true;
		s.top_element--;
	}
}


Data Access(Stack &s, bool &ok){
	if(s.top_element == -1)
		ok = false;
	else{
		ok = true;
		return s.vector[s.top_element];
	}		
}


void Print_stack(Stack s, bool &ok){
	if(s.top_element == -1)
		ok = false;
	else{
		ok = true;
		cout << "======= YOUR STACK =======" << endl;
		for(int i = s.top_element; i >= 0; i--)
			cout << s.vector[i] << endl;
	}
}


main(){
	setlocale(LC_ALL, "Portuguese");
		
	Stack stack;
	stack.top_element = -1;
	bool ok;
	Data value_to_push;
	int option;
	while(option != 5){
	system("cls");
	cout << "  1  PUSH  \n  2  POP  \n  3  ACCESS  \n  4  SHOW STACK  \n  5  QUIT";	
	cout << "  What would you like to do? ";
	cin >> option;
	switch(option){
		case 1:
		cout << "Value to insert at the top of the stack: ";
		cin >> value_to_push;
		Push(stack, value_to_push);
			break;
		case 2:
		Pop(stack, ok);
			break;
		case 3:
		Access(stack, ok);
		if(ok == false)
			cout << "Not found!" << endl; 
		else
			cout << "Top element: " << Access(stack, ok) << endl;
			break;
		case 4:
			Print_stack(stack, ok);
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
}
