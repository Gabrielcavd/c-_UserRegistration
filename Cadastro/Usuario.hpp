#pragma once
#include <string>
#include <stdio.h>
#include <map>
#include <vector>


class Usuario{
private:
	std::string nome;
	int cpf;
	int creditos;
	
public:
	std::string getNome();
	void setNome(std::string);
	int getCPF();
	int getCredito();
	bool addCredito(int);
	bool removeCredito(int);
	
	Usuario operator++();
	Usuario operator--();
	
	Usuario(std::string nome, int cpf){
		this->nome = nome;
		this->cpf = cpf;
		this->creditos = 10;
	}
};

class Cadastro{
private:
	std::map<int, Usuario> usuarios;
public:
	void addUsuario(Usuario);
	std::vector<Usuario> getUsuarios();
	Usuario getUsuarioCPF(int);
	std::vector<Usuario> getUsuariosNome(std::string);
	void delUsuarioCPF(int);
	std::vector<Usuario> getUsuariosOrdem();

};