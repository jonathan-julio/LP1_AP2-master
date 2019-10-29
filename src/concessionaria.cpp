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

concessionaria::concessionaria(){
	nome = "";
	cnpj = "";
}
concessionaria::~concessionaria(){
}

concessionaria::concessionaria(string nome_, string primeiro_nome_,string sobrenome_, string cnpj_, const vector<automovel*>lista_A, const vector<moto*>lista_M,const vector<caminhao*>lista_C){
	nome = nome_;
	primeiro_nome = primeiro_nome_;
	sobrenome = sobrenome_;
	cnpj = cnpj_;
	listaConc_A = lista_A;
	listaConc_M = lista_M;
	listaConc_C = lista_C;
	++(++numeroConc);
}
concessionaria::concessionaria(string nome_, string cnpj_, const vector<automovel*>lista_A, const vector<moto*>lista_M,const vector<caminhao*>lista_C){
	nome = nome_;
	cnpj = cnpj_;
	listaConc_A = lista_A;
	listaConc_M = lista_M;
	listaConc_C = lista_C;
	++(++numeroConc);
}


int concessionaria::getSizeLista_A(){
	return listaConc_A.size();	
}
int concessionaria::getSizeLista_M(){
	return listaConc_M.size();	
}
int concessionaria::getSizeLista_C(){
	return listaConc_C.size();	
}
	

string concessionaria::get_nome(){
	return nome; 
}
string concessionaria::get_primeiro_nome(){
	return primeiro_nome; 
}
string concessionaria::get_sobrenome(){
	return sobrenome; 
}
string concessionaria::get_cnpj(){
	return cnpj; 
}

bool concessionaria::add_automovel(string marca, double preco, string chassi,int motor,string data_){
		automovel *autom = new automovel(marca, preco, chassi,motor,data_);		
		listaConc_A.push_back(autom);
		return true;
}
bool concessionaria::add_moto(string marca, double preco, string chassi,int modelo,string data_){	
		moto *autom = new moto(marca, preco, chassi,modelo,data_);
		listaConc_M.push_back(autom);
		return true;	
}
bool concessionaria::add_caminhao(string marca, double preco, string chassi,int carga, string data_){		
		caminhao *autom = new caminhao(marca, preco, chassi,carga,data_);
		listaConc_C.push_back(autom);
		return true;
}

bool concessionaria::verificarChassi(){
		string chassi;
		cout << endl << "Informe o chassi"<< endl;	
		cin >> chassi;
		int cont = 0 ;
		
		for (vector<automovel*>::iterator it = listaConc_A.begin(); it != listaConc_A.end(); ++it){
			if ((**it) == chassi){
				cont +=1;
				return true;	
			}
		}
		for (vector<moto*>::iterator it = listaConc_M.begin(); it != listaConc_M.end(); ++it){
			if ((**it) == chassi){
				cont +=1;
				return true;	
			}
		}
		for (vector<caminhao*>::iterator it = listaConc_C.begin(); it != listaConc_C.end(); ++it){
			if ((**it) == chassi){
				cont +=1;
				return true;	
			}
		}
		if (cont == 0 ){
			cout << endl << "Chassi nao pertece a essa concessionaria."<< endl;	
			return false;
		}
	return false;
}
bool concessionaria::add_veiculo(){
	string chassi;
	string marca;
	double preco;
	int motor;
	int carga;
	int modelo;
	int escolha;
	cout << endl << "-> informe o tipo de Veiculo:";
	cout << endl << "-> automovel ........ 1";
	cout << endl << "-> Moto.............. 2";
	cout << endl << "-> Caminhao.......... 3"<< endl;
	cin >> escolha;
	
	
	
	if (escolha == 1){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Tipo do motor:\n(1 para gasolina, 2 para eletrico): "<< endl;	
		cin >> motor;
		
		automovel *autom = new automovel(marca, preco, chassi,motor);
		
		for (vector<automovel*>::iterator it = listaConc_A.begin(); it != listaConc_A.end(); ++it){
			if ((**it) == *autom){
				cout << endl << "Carro ja cadastrado. Operacao CANCELADA!" << endl;
				return false;	
			}
		}
		
		listaConc_A.push_back(autom);
		
	
	}
	if (escolha == 2){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Modelo:\n(1 para esportio, 2 para comum): "<< endl;	
		cin >> modelo;
		
		moto *autom = new moto(marca, preco, chassi,modelo);
		

		for (vector<moto*>::iterator it = listaConc_M.begin(); it != listaConc_M.end(); ++it){
			if (**it == *autom){
				cout << endl << "Carro ja cadastrado. Operacao CANCELADA!" << endl;
				return false;	
			}
		}
	
		listaConc_M.push_back(autom);
	}
	if (escolha == 3){
		cout << endl << "-> Digite os dados do carro";

		cout << endl << "Numero do Chassi: "<< endl;
		cin>>chassi;
	
		cout << endl << "Marca: "<< endl;
		cin>>marca;
	
		cout << endl << "valor: "<< endl;	
		cin >> preco;
		
		cout << endl << "Tipo da carga:\n(1 para normal, 2 para de risco): "<< endl;	
		cin >> carga;
		
		caminhao *autom = new caminhao(marca, preco, chassi,carga);
		
		for (vector<caminhao*>::iterator it = listaConc_C.begin(); it != listaConc_C.end(); ++it){
			if (**it == *autom){
				cout << endl << "Carro ja cadastrado. Operacao CANCELADA!" << endl;
				return false;	
			}
		}
		listaConc_C.push_back(autom);
	}
	else if(escolha != 1 && escolha !=2 && escolha != 3){
		cout << endl << "Opcao invalida.\n\n";
		
	}
	return true;
}



   ostream& operator<<(ostream &o, concessionaria &concessionaria){
	for (vector<automovel*>::iterator i = concessionaria.listaConc_A.begin(); i != concessionaria.listaConc_A.end(); ++i)
	{
		o << (**i) << endl;
	}
	for (vector<moto*>::iterator i = concessionaria.listaConc_M.begin(); i != concessionaria.listaConc_M.end(); ++i)
	{
		o << (**i) << endl;
	}
	for (vector<caminhao*>::iterator i = concessionaria.listaConc_C.begin(); i != concessionaria.listaConc_C.end(); ++i)
	{
		o << (**i) << endl;
	}
	return o;
}
ofstream& operator<<(ofstream &of, concessionaria &concessionaria){
	for (vector<automovel*>::iterator i = concessionaria.listaConc_A.begin(); i != concessionaria.listaConc_A.end(); ++i)
	{
		of << (**i);
	}
	for (vector<moto*>::iterator i = concessionaria.listaConc_M.begin(); i != concessionaria.listaConc_M.end(); ++i)
	{
		of << (**i);
	}
	for (vector<caminhao*>::iterator i = concessionaria.listaConc_C.begin(); i != concessionaria.listaConc_C.end(); ++i)
	{
		of << (**i);
	}
	
	return of;
}




bool concessionaria::operator==(const concessionaria &conc) const{
	if (this->nome == conc.nome){
		return true;
	} else {
		return false;
	}
}
