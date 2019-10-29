#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef CAMINHAO_H
#define CAMINHAO_H



#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

#include "veiculo.h"

using namespace std;

class caminhao : public veiculo{
	private: 
		int tipo_carga;  
		

	public: 
		//static int numeroCarros;

		caminhao();
		caminhao(string marca, double preco, string chassi, int tipo_carga_); //para quando o veiculo é cadastrado manualmente
		caminhao(string marca, double preco, string chassi, int tipo_carga_,string data_); //para quando o veiculo é cadastrado por arquivo csv
		
		~caminhao();
		int getTipo_carga();
		void setTipo_carga(int tipo_carga_);

		friend ostream& operator << (ostream &o, caminhao &veiculo);
		friend ofstream& operator << (ofstream &o, caminhao &veiculo);

		bool operator==( caminhao &cam) ;
		bool operator==( string &marca) ;
	
};




#endif // AUTOMOVEL_H
