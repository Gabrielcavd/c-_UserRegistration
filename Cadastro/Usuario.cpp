#include <iostream>
#include "Usuario.hpp"
#include <utility>
#include <string>
#include <algorithm>

Usuario Usuario::operator ++ (){
	creditos++;
return Usuario(nome, cpf);
}

Usuario Usuario::operator --(){
	if(creditos == 0){
		std::cout << "ERRO: Créditos ficaram negativos" << std::endl;
	}else{
		creditos--;
	}
	return Usuario(nome, cpf);
}


void Usuario::setNome(std::string user){
	if(user.size() < 1){
		std::cout << "Nome em branco!" << std::endl;
	}else{
		this->nome = user;
	}
}

std::string Usuario::getNome(){
	return nome;
}

int Usuario::getCredito(){
	return creditos;
}

int Usuario::getCPF(){
	return cpf;
}

bool Usuario::addCredito(int valor){
	if(valor <= 0){
		std::cout << "Valor deve ser maior que 0" << std::endl;
		return false;
	}
	 creditos += valor;
	 return true;
}

bool Usuario::removeCredito(int valor){
	if (valor > creditos){
		std::cout << "ERRO: Créditos ficaram negativos" << std::endl;
		return false;
	}
	creditos -= valor;
	return true;
}

void Cadastro::addUsuario(Usuario user){
	auto search = usuarios.find(user.getCPF());
	
	if (search != usuarios.end()){
		std::cout << "CPF já cadastrado" << std::endl;
	}
	else{
		usuarios.insert(std::pair<int, Usuario>(user.getCPF(), user));
	}
}

std::vector<Usuario> Cadastro::getUsuarios(){
	std::vector<Usuario> novo;
	for(auto it = usuarios.begin(); it != usuarios.end(); ++it){
		novo.push_back(it -> second);
	}
	return novo;
}

Usuario Cadastro::getUsuarioCPF(int cpf){
	auto search = usuarios.find(cpf);
	
	if (search != usuarios.end()) return search ->second;
	else throw "Usuário não encontrado";
	
}

std::vector<Usuario> Cadastro::getUsuariosNome(std::string nome){
	std::vector<Usuario> usuario_novo;
	for(auto it = usuarios.begin(); it != usuarios.end(); ++it){
		if (it -> second.getNome() == nome){
			usuario_novo.push_back(it -> second);
		}
	}
	
	if (usuario_novo.size() == 0) throw "Usuário não encontrado";
	else return usuario_novo;
	
}

void Cadastro::delUsuarioCPF(int cpf){
	auto search = usuarios.find(cpf);
	
	if (search != usuarios.end()) usuarios.erase(cpf);
	else throw "Usuário não encontrado";
	
}

std::vector<Usuario> Cadastro::getUsuariosOrdem(){
	std::vector<int> cpf_ordem;
	std::vector<Usuario> usuarios_ordem;
	
	for(auto it = usuarios.begin(); it != usuarios.end(); ++it){
		cpf_ordem.push_back(it -> second.getCredito());
	}
	
	std::sort (cpf_ordem.begin(), cpf_ordem.end());
	
	for(long unsigned int i = 0; i < cpf_ordem.size(); i++){
		for(auto it = usuarios.begin(); it != usuarios.end(); ++it){
			if (cpf_ordem[i] == it -> second.getCredito()){
				usuarios_ordem.push_back(it -> second);
				break;
			}	
		}
	}
	
	return usuarios_ordem;
}