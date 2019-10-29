#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "veiculo.h"
#include "gerenciar.h"
#include "concessionaria.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;
gerenciar listaConc;

//int automovel::numeroCarros = 0;
int concessionaria::numeroConc = 0;

int main (int argc, char const *argv[]){
	int x = -1;
	int xx = 0;
	while (x!= 0){
		cout << endl << "++++++++++++++++++++++++++++++++"<<endl
		<< endl << "Escolha a opcao desejada"<<endl	
		<< "Digite 1 - Criar Concessionaria"<< endl
		<< "Digite 2 - Adicionar veiculo "<<endl
		<< "Digite 3 - Detalhes Concessionaria "<<endl
		<< "Digite 4 - Lista de veiculos"<< endl
		<< "Digite 5 - Salvar concessionaria"<< endl
		<< "Digite 6 - Buscar chassi"<< endl
		<< "Digite 0 - Sair"<< endl
		<< "++++++++++++++++++++++++++++++++"<<endl
		<< endl<< "Digite sua Escolha: " <<endl;
	
		cin >> x; 

		switch (x){
			case 1: 
				cout << "Digite 1 - Criar Concessionaria do zero."<< endl
					 << "Digite 2 - Criar Concessionaria a partir de um arquivo CSV."<< endl;
					 cin >> xx;
					 if (xx == 1){
					 	listaConc.criarconcessionaria();
					 	break;
					 }
					 else if (xx == 2){
					 	listaConc.criarconcessionariaCSV();
					 	break;
					 }
					 else {
					 	break;
					 	x = 9;

					 }					
			case 2: 
					listaConc.cadastrarCarro();
					break;	
			case 3: 
					listaConc.listarConcessionarias();
					break;	
			case 4:
					listaConc.estoques();
					break;
			case 5:
					listaConc.salvarConcessionaria();
					break;
			case 6:
					listaConc.buscaChassi();
					break;
			case 0:
					cout<<endl<< "Ate mais!" << endl;
					return 0;
			default:
			cin.clear();
			cin.ignore(200,'\n');
			cout << endl << "Entrada invalida, digite novamente" <<endl;
		}
	}
	return 0;


}
