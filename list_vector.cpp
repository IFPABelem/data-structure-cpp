#include <iostream>
//#include <locale.h>
#include <windows.h>

using namespace std;

const int max_size = 10;
typedef int Integer_type;

typedef struct List{
	Integer_type logic_size = 0;
	Integer_type vector[max_size];
}List;

// Find
Integer_type find_an_element(List &l, Integer_type position, bool &check){
	if((position < 0) || (position > l.logic_size))
		check = false;
	else{
		check = true;
		return l.vector[position];
	}
		
}
// Change
void change_an_element(List &l, Integer_type position, Integer_type new_value, bool &check){
	if((position < 0) || (position > l.logic_size))
		check = false;
	else
		l.vector[position] = new_value;
}
// Insert
void insert_an_element(List &l, Integer_type position, Integer_type new_value, bool &check){
	if(l.logic_size == max_size)
		check = false;
	else if ((position < 0) || (position > l.logic_size))
		check = false;
	else{
		check = true;
		for(int i = position; i < l.logic_size - 1; i++)
			l.vector[i] = l.vector[i + 1];
		l.vector[position] = new_value;	
		l.logic_size++;
	}
}
// Delete
void delete_an_element(List &l, Integer_type posi,  bool &check){
	if((posi < 0) || (posi > l.logic_size))
		check = false;
	for(int i = posi; i < l.logic_size; i++)
		l.vector[i] = l.vector[i + 1];
	l.logic_size--;	
}


void show_list(List l, bool &check){
	if(l.logic_size == 0)
		check = false;	
	else{
		check = true;
		cout << "======= YOUR LIST =======" << endl;
		for(int i = 0; i < l.logic_size; i++)
			cout << "Element: " << l.vector[i] << endl;			
	}
}


main(){
	//setlocale(LC_ALL, "Portuguese");
		
	List list;
	bool check;
	Integer_type new_value, position_to_delete, value_to_change, position;
	int option;
	
	while(option != 6){
		system("cls");
		cout << "    1 INSERT \n    2 DELETE \n    3 FIND \n    4 CHANGE \n    5 SHOW LIST  \n    6 QUIT" << endl;
		cout << "    What would you like to do? ";
		cin >> option;
		switch(option){
			case 1:
				cout << "Value to insert: ";
				cin >> new_value;
				cout << "Position: ";
				cin >> position;
				insert_an_element(list, position, new_value, check);
				if (check == false)
					cout << "Error!" << endl;
				else
					cout << "Inserted successfuly!" << endl;					
				break;
			case 2:
				cout << "Position to delete: ";
				cin >> position_to_delete;
				delete_an_element(list, position_to_delete, check);
				if (check == false)
					cout << "Not found!" << endl;
				else
					cout << "Deleted sucessfuly" << endl;
				break;
			case 3:
				cout << "Element position: ";
				cin >> position;
				find_an_element(list, position, check);
				if (check == false)
					cout << "Not found!" << endl;
				else
					cout << find_an_element(list, position, check) << endl;
				break;
			case 4:
				cout << "Position that you wanna change: ";
				cin >> position;
				cout << "New value: ";
				cin >> new_value;
				change_an_element(list, position, new_value, check);
				if(check == false)
					cout << "There's no value in this position!" << endl;
				break;
			case 5:
				show_list(list, check);
				if(check == false)
					cout << "Your list is empty!" << endl;			
				Sleep(7000);
				break;
			case 6:
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
