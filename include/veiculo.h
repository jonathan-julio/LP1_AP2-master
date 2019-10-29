#define _GLIBCXX_USE_CXX11_ABI 0
#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iterator>
#include <algorithm>



using namespace std;

class veiculo{
	private: 
		string marca; 
		double preco;
		string chassi; 
		string data;
		

//Getters e Setters
	public: 	

		string getMarca();	
		double getPreco();		 
		string getChassi();
		virtual string getData();
		
		void setData();
		void setData(string data_);
		void setMarca(string marca_); 
		void setPreco(double preco_);
		void setChassi(string chassi_);
		

	
};

#endif // VEICULO_H
