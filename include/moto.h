#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef MOTO_H
#define MOTO_H



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "veiculo.h"


using namespace std;

class moto : public veiculo{
	private: 
		int modelo;
	public: 


		moto();
		moto(string marca, double preco, string chassi, int modelo_);
		moto(string marca, double preco, string chassi, int modelo_,string data_);
		~moto();
		int getModelo();
		void setModelo(int modelo_);


		friend ostream& operator << (ostream &o, moto &veiculo_);
		friend ofstream& operator << (ofstream &om, moto &veiculo_);

		bool operator==( moto &mot) ;

		bool operator==( string &marca) ;
	
};




#endif // AUTOMOVEL_H
