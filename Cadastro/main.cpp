#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include "Usuario.hpp"
#include "windows.h"

using namespace std;

int main()
{
	Cadastro users;
	int resposta;
	int sair = 0;
	while(sair != 1){
		
		
		cout << "SISTEMA DE CADASTRO DE USUÁRIOS" << endl << "O que deseja fazer?" << endl;
		cout << "1 - Cadastrar usuário" << endl << "2 - Adicionar crédito" << endl 
		<< "3 - Remover crédito" << endl << "4 - Consultar todos os usuários" << endl 
		<< "5 - Consultar usuário por nome" << endl << "6 - Consultar usuário por CPF" << endl
		<< "7 - Deletar usuário" << endl << "8 - Sair" << endl;
		cout << "Digite sua opção:" << endl;
		
		cin >> resposta;
		
		switch (resposta){
			case 8:{ 
				sair = 1;
				break;
			}
			case 1:{
				system("cls");
				string nome;
				int cpf;
				cout << "Digite um nome" << endl;
				cin.ignore();
				getline(cin, nome);
				cout << "Digite um CPF (só numeros)" << endl;
				cin >> cpf;
				Usuario novo(nome, cpf);
				users.addUsuario(novo);
				cout << "Usuário adicionado com sucesso." << endl;

				system("pause");
				break;
			}
			case 2:{
				system("cls");
				int CPF;
				int qntd;
				cout << "Digite o CPF do usuário para adicionar crédito" << endl;
				cin >> CPF;
				cout << "Digite a quantidade de crédito" << endl;
				cin >> qntd;
				users.getUsuarioCPF(CPF).addCredito(qntd);
				cout << "Créditos adicionados com sucesso." << endl;

				system("pause");
				break;
			}
			case 3:{
				system("cls");
				int CPF;
				int qntd;
				cout << "Digite o CPF do usuário para remover crédito" << endl;
				cin >> CPF;
				cout << "Digite a quantidade de crédito" << endl;
				cin >> qntd;
				users.getUsuarioCPF(CPF).removeCredito(qntd);
				cout << "Créditos removidos com sucesso." << endl;

				system("pause");
				break;
				
			}
			case 4:{
				system("cls");
				vector<Usuario> users_novo;
				users_novo = users.getUsuarios();
				for(long unsigned int i = 0; i < users_novo.size(); i++){
						cout << "Nome: " << users_novo[i].getNome() << endl
						<< "CPF: " << users_novo[i].getCPF() << endl 
						<< "Créditos: " << users_novo[i].getCredito() << endl;
					}
				
				system("pause");
				break;
			}
			case 5:{
					system("cls");
					string nome;
					vector<Usuario> novos_users;
					cout << "Digite o nome do usuário" << endl;
					cin.ignore();
					getline(cin, nome);
					try{
					novos_users = users.getUsuariosNome(nome);
					}catch(...){
						cerr << "Usuário não encontrado. \n";
					}
					for(long unsigned int i = 0; i < novos_users.size(); i++){
						cout << "Usuário encontrado!" << endl
						<< "Nome: " << novos_users[i].getNome() << endl
						<< "CPF: " << novos_users[i].getCPF() << endl 
						<< "Créditos: " << novos_users[i].getCredito() << endl;
					}

					system("pause");
					break;
				}
			case 6:{
				system("cls");
				int CPF;
				cout <<  "Digite o CPF do usuário" << endl;
				cin >> CPF;
				try{
					users.getUsuarioCPF(CPF);
				}catch(...){
					cerr << "Usuário não encontrado. \n";
				}
				cout << "Usuário encontrado!" << endl
				<< "Nome: " << users.getUsuarioCPF(CPF).getNome() << endl
				<< "CPF: " << users.getUsuarioCPF(CPF).getCPF() << endl 
				<< "Créditos: " << users.getUsuarioCPF(CPF).getCredito() << endl;

				system("pause");
				break;
				}
			case 7:{
				system("cls");
				int CPF;
				cout << "Digite o CPF do usuário" << endl;
				cin >> CPF;
				
				try{
					users.delUsuarioCPF(CPF);
				}catch(...){
					cerr << "Usuário não encontrado. \n";
				}
				cout << "Usuário apagado com sucesso. \n";

				system("pause");
				break;
				}
				
			}
			
			
		}
	
	return 0;
}
