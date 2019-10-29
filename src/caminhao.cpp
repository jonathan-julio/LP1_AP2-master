#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "gerenciar.h"
#include "caminhao.h"
#include "veiculo.h"
#include "concessionaria.h"

using namespace std;

caminhao::caminhao(){
	setMarca("");
	setPreco(0);
	setChassi("");
	setTipo_carga(0);
	setData();
	//++numeroCarros;
}

caminhao::caminhao(string marca_, double preco_, string chassi_,int tipo_carga_ ){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setTipo_carga(tipo_carga_);
	setData();
	//++numeroCarros;
}
caminhao::caminhao(string marca_, double preco_, string chassi_,int tipo_carga_ ,string data_){
	setMarca(marca_);
	setPreco(preco_);
	setChassi(chassi_);
	setTipo_carga(tipo_carga_);
	setData(data_);	
	//++numeroCarros;
}


caminhao::~caminhao(){
//	--numeroCarros;
}

int caminhao::getTipo_carga(){
	return tipo_carga;
}

void caminhao::setTipo_carga(int tipo_carga_){
	tipo_carga = tipo_carga_;
}

ostream& operator<< (ostream &o, caminhao &veiculo_){
	o << "*********CAMINHAO******" << endl
	  << "> Marca: " << veiculo_.getMarca() << endl
	  << "> Preco: " << veiculo_.getPreco() << endl
	  << "> Tipo de carga: " << veiculo_.getTipo_carga() << " (1 NORMAL, 2 RISCO)" << endl
	  << "> Data fabricacao: " << veiculo_.getData() << endl
	  << "> Numero do Chassi: " << veiculo_.getChassi() << endl;
	return o;
}
ofstream& operator<< (ofstream &o, caminhao &veiculo_){
	o << endl << ";;;;"<< veiculo_.getMarca()<<";" << veiculo_.getPreco()<<";"<< veiculo_.getChassi()<<";;;" << veiculo_.getTipo_carga()<<";" << veiculo_.getData();
	return o;
}

bool caminhao::operator==( caminhao &autom)  {
	if (this->getChassi() == autom.getChassi()){
		return true;
	} else {
		return false;
	}
}

bool caminhao::operator==( std::string &marca)  {
	if (this->getChassi() == marca){
		cout<< "*********CAMINHAO******" << endl
	  		<< "> Marca: " << this->getMarca() << endl
	  		<< "> Preco: " << this->getPreco() << endl
	  		<< "> Tipo de carga: " << this->getTipo_carga() << " (1 NORMAL, 2 RISCO)" << endl
	 		<< "> Data fabricacao: " << this->getData() << endl
	  		<< "> Numero do Chassi: " << this->getChassi() << endl;
		return true;
	} else {
		return false;
	}
}
