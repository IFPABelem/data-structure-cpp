#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string>

using namespace std;

typedef float Data;

typedef struct No{
	Data value;
	No *NextElement;
} No;


typedef No *PtNo;


void insert_beginning(PtNo &hea, Data val){
	PtNo new_node;
	new_node = new No;
	new_node->value = val;
	
	if(hea == NULL)
		new_node->NextElement = NULL;
	else
		new_node->NextElement = hea;
	
	hea = new_node;
}

 
void append(PtNo &hea, Data val){
	PtNo new_last_node, temp;
	
	new_last_node = new No;
	temp = new No;
	
	new_last_node->value = val;
	new_last_node->NextElement = NULL;
	
	if(hea == NULL)
		hea = new_last_node;
	
	else{
		temp = hea;		
		while(temp->NextElement != NULL)
			temp = temp->NextElement;	
		//cout << temp->value;	
		temp->NextElement = new_last_node;
	}
}


void insert(PtNo &hea, int position, Data val, bool &ok){
	PtNo temp, new_node;
	new_node = new No;
	temp = new No;
	
	new_node->value = val;
	
	if (hea == NULL){	
		new_node->NextElement = NULL;
		hea = new_node;
	}			
	else{
		int coun = 0;
		temp = hea;
		while(temp != NULL){
			temp = temp->NextElement;
			coun++;
		}		
		if ((position > 0) && (position < coun)){
			ok = true;
			temp = hea;
			int c = 1;
			while(c < position){
				temp = temp->NextElement;
				c++;
			}
		
		new_node->NextElement = temp->NextElement;
		temp->NextElement = new_node;
		
		}
		else{
			ok = false;
		}
	}
}


void delete_last_elemen(PtNo &hea, bool &ok){
	PtNo temp;
	temp = new No;
	if(hea == NULL)
		ok = false;
	
	else{
		temp = hea;			
		while(temp->NextElement != NULL){
			if((temp->NextElement)->NextElement == NULL)
				break;
			temp = temp->NextElement;
		}
		temp->NextElement = NULL;
	}
}


void delete_from_position(PtNo &hea, int position, bool &ok){
	PtNo temp;
	temp = new No;
	temp = hea;
		
	if (hea == NULL)
		ok = false;

	else{
		ok = true;		
		int cont = 1;
		while(cont < position){
			temp = temp->NextElement;
			cont++;
		}
		temp->NextElement = (temp->NextElement)->NextElement;
	}
}


delete_from_value(PtNo &hea, Data val, bool &ok){
	PtNo temp;
	temp = new No;
	if(hea == NULL)
		ok = false;
	else{
		int coun = 0;
		temp = hea;
		while(temp != NULL){
			temp = temp->NextElement;
			coun++;
			}
		
		if(coun > 1){
			ok = true;
			temp = hea;
			while(temp != NULL){
				if(((temp->NextElement)->value) == val)
					break;
				temp = temp->NextElement;
			}
			temp->NextElement = (temp->NextElement)->NextElement;
		}
		else{
			ok = false;
		}
	}
}

void delete_head(PtNo &hea){
	PtNo temp;	
	temp = new No;
	temp = hea->NextElement;
	hea = temp;
}


void show_list(PtNo &hea){
	PtNo temp;
	temp = hea;
	while(temp != NULL){
		cout << temp->value << "  ";
		temp = temp->NextElement;
	}
}


main(){
	//setlocale(LC_ALL, "Portuguese");
	bool ok;
	PtNo head;
	head = new No;
	head = NULL;
	int option;
	Data insert_at_the_en, insert_at_the_begin, value_to_insert, position_to_insert, delete_from_posi, delete_from_val;	
	while(option != 9){
		system("cls");
		cout << "  1  INSERT AT THE END  \n  2  INSERT AT THE BEGINNING  \n  3  INSERT FROM POSITION  \n  4  DELETE FROM POSITION  \n  5  DELETE LAST NODE  \n  6  DELETE FROM A VALUE  \n  7  DELETE FIRST NODE  \n  8  SHOW LIST  \n  9  QUIT" << endl;	
		cout << "  What would you like to do? ";
		cin >> option;
		switch(option){
			case 1:
				cout << "Value to append: ";
				cin >> insert_at_the_en;
				append(head, insert_at_the_en);
				break;
			case 2:
				cout << "Value to insert at the beginning: ";
				cin >> insert_at_the_begin;
				insert_beginning(head, insert_at_the_begin);
				break;
			case 3:
				cout << "Position to insert: ";
				cin >> position_to_insert;
				cout << "Value to insert: ";
				cin >> value_to_insert;
				insert(head, position_to_insert, value_to_insert, ok);
				if(ok == false)
					cout << "Invalid position!" << endl;
				break;
			case 4:
				cout << "Position to be deleted: ";
				cin >> delete_from_posi;
				delete_from_position(head, delete_from_posi, ok);
				if(ok == false)
					cout << "Invalid position!" << endl;
				break;
			case 5:
				delete_last_elemen(head, ok);
				if(ok == true)
					cout << "Last node deleted!" << endl;
				break;
			case 6:
				cout << "Value to be deleted: ";
				cin >> delete_from_val;
				delete_from_value(head, delete_from_val, ok);
				if(ok == true)
					cout << "Deleted successfuly" << endl;
				else
					cout << "Error!" << endl;
				break;
			case 7:
				delete_head(head);
				break;
			case 8:
				show_list(head);
				break;
			case 9:
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

