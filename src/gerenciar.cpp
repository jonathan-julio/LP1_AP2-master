#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "concessionaria.h"

#include "veiculo.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

using namespace std;
using std::string;
using std::getline;


gerenciar::~gerenciar(){

}


concessionaria gerenciar::criarconcessionaria(){
	string nome;
	string P_nome;
	string sobrenome;
	string cnpj;
	int pessoa;
	vector<automovel*> listaConc_A;
	vector<moto*> listaConc_M;
	vector<caminhao*> listaConc_C;
	
	cout << "Informe o nome da concessionaria: ";
	cin.ignore(200,'\n');
	getline(cin,nome);
	cout << "Informe o tipo de proprietario.\nPessoa fisica ----- 1\nPessoa Juridica --- 2\n";
	cin >> pessoa;
	if(pessoa  == 1){
		cout << endl<< "Informe o nome do proprietario: ";
		cin >> P_nome;
		cout << endl<< "Informe o sobrenome do proprietario: ";
		cin >> sobrenome;
		cnpj = "";
	}
	else if (pessoa == 2){
		cout << endl<< "Informe o CNPJ da concessionaria: ";
		cin >> cnpj;
		sobrenome = "";
		P_nome ="";	
	}
	else{
		cout << endl<< "Escolha invalida.\n";
		return criarconcessionaria();
	}

	
	concessionaria *novaConc = new concessionaria(nome,P_nome,sobrenome,cnpj,listaConc_A,listaConc_M,listaConc_C);
	statusConc status = inexistente;

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome() == nome){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				status = existe;
			}
		}

	if (status == inexistente){
			listaLoja.push_back(novaConc);
			cout<< endl << "Concessionaria Inaugurada."<< endl;
	}

	return *novaConc;

}


concessionaria gerenciar::criarconcessionariaCSV(){
	string arq,NOME_CONC,NOME_P,SOBRENOME,CNPJ,MARCA,PRECO,CHASSI,MOTOR,MODELO,CARGA,DATA; 
	int motorr,modeloo,cargaa;
	concessionaria aux;
	string nomeConcAux,pNomeAux, sobrenomeAux,cnpjAux;
	double precoo;	
	vector<automovel*> listaConc_A;
	vector<moto*> listaConc_M;
	vector<caminhao*> listaConc_C;
	
	cout << "Informe o nome do arquivo: (SEM INCLUIR .CSV)";
	cin>>arq;
	
	ifstream arquivoE;
	arquivoE.open(arq+".csv");	
	if(arquivoE.is_open()){		
		while(arquivoE.good()){
			getline	(arquivoE,NOME_CONC,';');
			getline	(arquivoE,NOME_P,';');
			getline	(arquivoE,SOBRENOME,';');
			getline	(arquivoE,CNPJ,';');
			getline	(arquivoE,MARCA,';');
			getline	(arquivoE,PRECO,';');
			getline	(arquivoE,CHASSI,';');
			getline	(arquivoE,MOTOR,';');
			getline	(arquivoE,MODELO,';');
			getline	(arquivoE,CARGA,';');
			getline	(arquivoE,DATA,'\n');
			
			
			if (CNPJ != "" && CNPJ != "CNPJ"){
				nomeConcAux = NOME_CONC;
				cnpjAux = CNPJ;
				pNomeAux = "";
				sobrenomeAux = "";
				break;		
			}
			else if(NOME_P != "" && NOME_P != "NOME" ){
				cnpjAux = "";
				nomeConcAux = NOME_CONC;
				pNomeAux = NOME_P;
				sobrenomeAux = SOBRENOME;
				break;		
			}
		}
		for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
			if ((**it).get_nome()== nomeConcAux){
				cout << endl << "Concessionaria ja cadastrado. Operacao CANCELADA!" << endl;
				return **it;
				arquivoE.close();
			}
		}
		if(arquivoE.is_open()){
	
		concessionaria *novaConc = new concessionaria(nomeConcAux,pNomeAux,sobrenomeAux,cnpjAux,listaConc_A,listaConc_M,listaConc_C);
		listaLoja.push_back(novaConc);		
	 	while(arquivoE.good()){
			getline	(arquivoE,NOME_CONC,';');
			getline	(arquivoE,NOME_P,';');
			getline	(arquivoE,SOBRENOME,';');
			getline	(arquivoE,CNPJ,';');
			getline	(arquivoE,MARCA,';');
			getline	(arquivoE,PRECO,';');
			getline	(arquivoE,CHASSI,';');
			getline	(arquivoE,MOTOR,';');
			getline	(arquivoE,MODELO,';');
			getline	(arquivoE,CARGA,';');
			getline	(arquivoE,DATA,'\n');
			
			if (CNPJ != "" && CNPJ != "CNPJ" && NOME_P != "" && NOME_P != "NOME" ){			
					concessionaria *novaConc = new concessionaria(nomeConcAux,pNomeAux,sobrenomeAux,cnpjAux,listaConc_A,listaConc_M,listaConc_C);
					aux = *novaConc;
					listaLoja.push_back(novaConc);				
				}
			else{
				if (MOTOR != "" and MOTOR != "MOTOR"){
				motorr = stoi(string (MOTOR));	
				precoo = stod(string (PRECO));	
				novaConc->add_automovel(MARCA, precoo, CHASSI,motorr,DATA);	
							
				}
				else if (MODELO != "" and MODELO != "MODELO"){
					modeloo = stoi(string (MODELO));	
					precoo = stod(string (PRECO));	
					novaConc->add_moto(MARCA,precoo, CHASSI,modeloo,DATA);				
				}
				else if (CARGA != "" and CARGA != "CARGA"){
					cargaa = stoi(string (CARGA));	
					precoo = stod(string (PRECO));	
					novaConc->add_caminhao(MARCA,precoo, CHASSI,cargaa,DATA);				
				}
			}	
		}
		cout << endl << "Concessionaria cadastrado." << endl;
		return *novaConc;
		free(novaConc);
		//arquivoE.close();
		}	
	}	
	else{
		cout << "Erro ao abrir arquivo. Verifique se o nome esta correto. "<< endl;	
	}
	
	return aux;

	
}


void gerenciar::salvarConcessionaria(){
	cout << endl << "Deseja salvar qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}
	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
		
	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			ofstream arquivo;
			arquivo.open(nome+".csv");
			arquivo << "NOME CONC;NOME;SOBRENOME;CNPJ;MARCA;PRECO;CHASSI;MOTOR;MODELO;CARGA;DATA"<< endl;
			
			string cnpjAux = (**it).get_cnpj();
			if ( cnpjAux == ""){	
				arquivo << nome <<";"<< (**it).get_primeiro_nome() <<";" << (**it).get_sobrenome()<<";" <<";;;;;;;";
			}
			else{
				arquivo << nome <<";;;"<< cnpjAux <<";;;;;;;";
			}
			for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
				if ((**it).get_nome() == nome){
				
				arquivo << (**it);
				}
			}
			cout << endl << "Concessionaria " << nome << " salva com sucesso."<< endl;	

			} 
	}
}



void gerenciar::cadastrarCarro(){

	cout << endl << "Deseja cadastrar o carro em qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;


	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	statusConc status = inexistente;

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			status = existe;
			if ((**it).add_carro()){
				status = carroCadastrado;
			} 
		}
	}
	if (status == inexistente){
		cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	} 
	else if (status == carroCadastrado){
		cout << endl << "Veiculo cadastrado." << endl;
	} 
	return;
}

bool gerenciar::estoques(){

	cout << endl << "Estoque de qual concessionaria quer acessar? " << endl << "Concessionarias:" << endl << endl;
			  
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);

	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			cout << endl << " O estoque da " << nome << " possui: "<< endl;
			cout << (**it);
			return true;
		}
	}
	cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	return false;
}


bool gerenciar::listarConcessionarias(){
	cout << endl << "Estoque de qual concessionaria quer acessar? " << endl << "Concessionarias:" << endl << endl;
			  
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}
	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);
	for ( vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){

			cout << endl << " Concessionaria " << nome << endl<< endl;
			if ( (**it).get_cnpj() == ""){
				cout << " Proprietario " << (**it).get_primeiro_nome() << " " << (**it).get_sobrenome() << endl;	
			}
			else{
				cout << endl << " CNJP " << (**it).get_cnpj() << endl;
			}
			cout << " Fronta total de Automoveis : " << (**it).getSizeLista_A() << endl;
			cout << " Fronta total de Motos      : " << (**it).getSizeLista_M() << endl;
			cout << " Fronta total de Caminhoes  : " << (**it).getSizeLista_C() << endl;
			cout << " Total de Veiculos          : " << (**it).getSizeLista_A()+ (**it).getSizeLista_M() + (**it).getSizeLista_C() << endl;
			return true;
		}
	}
	cout << endl << "Concessionaria nao encontrada. Tente novamente." << endl;
	return false;	
}


void gerenciar::buscaChassi(){

	cout << endl << "qual concessionaria? " <<endl<< "Concessionarias:" << endl << endl;


	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		cout << (**it).get_nome() << endl;
	}

	cout << endl << "Digite a concessionaria: ";
	string nome;
	cin.ignore(200,'\n');
	getline(cin,nome);

	for (vector<concessionaria*>::iterator it = listaLoja.begin(); it != listaLoja.end(); ++it){
		if ((**it).get_nome() == nome){
			if ((**it).verificarChassi()){
			} 
		}
	}
}

