// Code by Prof: Andrea Marques
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <locale.h>

using namespace std;

typedef int tDado;
const int TMax = 4;

typedef struct tFila {
    int Ini, Fim, Tam;
    tDado Elem[TMax];
} tFila;
        
tFila F;

void Primeiro(tFila F){
    if(F.Tam == 0)
     cout << " Fila Vazia" <<endl;
    else
      cout << " 1º elemento da Fila: " <<F.Elem[F.Ini+1]<<endl;;
}


void Inserir(tFila &F, int V){
    if(F.Tam == TMax)
		cout << "Capacidade Esgotada\n";
    else{
        F.Fim = (F.Fim + 1) % TMax;      
        F.Elem[F.Fim] = V;
        F.Tam++;
        
    }
}


void Remover(tFila &F){
   if(F.Tam == 0)
     cout << "Fila Vazia\n";
   else{   
      F.Ini = (F.Ini + 1) % TMax;
      F.Tam--;
      //cout << "Tamanho: " << F.Tam << endl;
      cout << "Posição do fim: " << F.Fim << endl;
      cout << "Posição do inicio: " << F.Ini << endl;
	}
}


int mapear_valor (int v){
	//cout << "v % TMax = " << v % TMax << endl;
	return v % TMax;
}     


void Visualiza(tFila F){
    int cont = 1;
    int aux = mapear_valor (F.Ini+1);
    cout << F.Ini << endl;
    while (F.Tam > cont-1){
    	cout <<cont<< "º valor: "<< F.Elem[aux] << endl;
    	cont++;
    	F.Ini++;
    	aux = mapear_valor(aux+1);
	}
}


int main(){
	setlocale(LC_ALL,"PORTUGUESE");
    F.Ini = 0;
    F.Fim = 0;
    F.Tam = 0;
    
    int V, opc;
    
    do{
    cout << "Escolha uma opção:\n";
    cout << "1 - Acessar o primeiro elemento\n";
    cout << "2 - Inserir um elemento\n";
    cout << "3 - Remover um elemento\n";
    cout << "4 - Visualiza\n";
    cout << "5 - Sair\n\n";
    
    cout << "Quero: ";
    cin >> opc;
    system("cls");
    
    switch(opc){
       case 1: Primeiro(F);
               break;
       
	   case 2: cout << "Insira um inteiro qualquer: ";
               cin >> V;
               Inserir(F, V);
               break;
       
	   case 3: Remover(F);
	   		   Sleep(10000);
               break;
       
	   case 4: Visualiza(F); 
               break;
   		}
	}while(opc<5);

	system("pause");
}
/*
main(){
	for(int i = 1; i < 21; i++)
		cout << i << " % 20 igual a = " << i % 20 << endl;
	system("Pause");
}
*/











