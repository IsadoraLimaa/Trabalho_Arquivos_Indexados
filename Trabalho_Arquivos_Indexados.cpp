#include <iostream>
#include <conio.h>

using namespace std;

#define MaxCidade 10
#define MaxEspecialidade 10
#define MaxMedico 10
#define MaxPaciente 10
#define MaxCID 10
#define MaxMedicamento 10
#define MaxConsulta 10


struct Indice{
	int cod;
	int end;	
};

struct Cidade{
	int codigo;
	string nome;
	string uf;	
};

struct Especialidade{
	int codigo;
	string descricao;
};

struct Medico{
	int codigo;
	string nome;
	int codigo_esp;
	string telefone;
	string endereco;
	int codigo_cidade;
	int status;
};

struct Paciente{
	int codigo;
	string nome;
	string endereco;
	int codigo_cidade;
	int status;	
};

struct CID{
	int codigo;
	string descricao;
};

struct Medicamento{
	int codigo;
	string descricao;
	int qtde_estoque;
	int estoque_minimo;
	int estoque_maximo;
	float preco_unitario;
};

struct Consulta{
	int codigo;
	int codigo_paciente;
	int codigo_medico;
	string data;
	string hora;
	int codigo_cid;
	int codigo_medicamento;
	int qtde_medicamento;
};

//VERIFCAÇÃO DE CODIGO E RETORNO DE ENDEREÇOS 

int verifica_codigo(struct Indice idx[], int cod,  int cont){
	 int i = 0, f = cont-1;
    int m = (i + f) / 2;
    if(f == -1){
    	return -1;
	}
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        return 1;
    }
    else return -1;
}


int busca(struct Indice idx[], int cont, int cod){
	 int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        i = idx[m].end;
        return i;
    }
    else
        return -1;
}


//CIDADE

void leitura_cidade(struct Cidade v[], int &cont){
	int i = 0;
	for(int saida = 1; saida != 0 && i < MaxCidade; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: ";
		cin>>v[i].codigo;
		cin.ignore();
			if(v[i].codigo > 0){
				cout<<"Nome: ";
				getline(cin, v[i].nome);
				cout<<"UF: ";
	    		getline(cin, v[i].uf);	
			}else saida = 0;
	}	
	
	if(i == MaxCidade){
            cont = i;
        }else cont = i - 1;
}

// ESPECIALIDADE

void leitura_especialidade(struct Especialidade v[], int &cont){
	int i = 0;
	for(int saida = 1; saida != 0 && i < MaxEspecialidade; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: ";
		cin>>v[i].codigo;
		cin.ignore();
		if(v[i].codigo > 0){
		cout<<"Descricao: ";
		getline(cin, v[i].descricao);
		}
		else saida = 0;
	}	
	
	if(i == MaxEspecialidade){
            cont = i;
        }else cont = i - 1;
}

//CID

void leitura_CID(struct CID v[], int &cont){
		int i = 0;
	for(int saida = 1; saida != 0 && i < MaxCID; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: ";
		cin>>v[i].codigo;
		cin.ignore();
		if(v[i].codigo > 0){
		cout<<"Descricao: ";
		getline(cin, v[i].descricao);
		}
		else saida = 0;
	}	
	
	if(i == MaxCID){
            cont = i;
        }else cont = i - 1;
}

// MEDICAMENTO

void leitura_medicamento(struct Medicamento v[], int &cont){
	int i = 0;
	for(int saida = 1; saida != 0 && i < MaxCID; i++){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: ";
		cin>>v[i].codigo;
		cin.ignore();
		if(v[i].codigo > 0){
		cout<<"Descricao: ";
		getline(cin, v[i].descricao);
		cout<<"Quantidade em Estoque: ";
		cin>>v[i].qtde_estoque;
		cout<<"Estoque Minimo: ";
		cin>>v[i].estoque_minimo;
		cout<<"Estoque Maximo: ";
		cin>>v[i].estoque_maximo;
		cout<<"Preco Unitario: ";
		cin>>v[i].preco_unitario; 
		}
		else saida = 0;
	}	
	
	if(i == MaxMedicamento){
            cont = i;
        }else cont = i - 1;
}


void consultar_medicamento(struct Medicamento v[],struct Indice ind[], int cont){
	int cod;
	
	for(int x = 1; x != -1;){
	
		cout<<"\nInforme o codigo do medicamento que deseja consultar: ";
		cin>>cod;
		
		if(cod > 0){
		
			int resultado = busca(ind, cont, cod);
	
				if(resultado != -1){
					cout<<"\nMedicamento: "<<v[resultado].descricao;
					cout<<"\nQuantidade no Estoque: "<<v[resultado].qtde_estoque;
					cout<<"\nEstoque Minimo: "<<v[resultado].estoque_minimo;
					cout<<"\nEstoque Maximo: "<<v[resultado].estoque_maximo;
					cout<<"\nPreco Unitario: "<<v[resultado].preco_unitario;
					cout<<"\n- Valor Total: "<<v[resultado].qtde_estoque * v[resultado].preco_unitario<<endl;	
						
				} else cout<<"\nCodigo nao encontrado!\n";
		
		    } else x = -1;
		}	
}


void estoque_minimo(struct Medicamento v[], int cont){
	int k=0;
	for(int i=0; i<cont; i++){
		if(v[i].qtde_estoque < v[i].estoque_minimo){
			cout<<"\n\n----------"<<v[i].descricao<<"----------";
			cout<<"\nCodigo: "<<v[i].codigo;
			cout<<"\nQuantidade em Estoque: "<<v[i].qtde_estoque;
			cout<<"\nEstoque Minimo: "<<v[i].estoque_minimo<<endl;
			int qtde_compra = v[i].estoque_maximo - v[i].qtde_estoque;
		
			cout<<"\nQuantidade e ser comprada: "<< qtde_compra;
			cout<<"\nValor da Compra: "<< qtde_compra * v[i].preco_unitario<<endl;
			k++;
			
		} 	
	}
	
	if(k == 0){
		cout<<"\nNao ha medicamentos abaixo do estoque minimo!";
	}
}

//MEDICO

void incluir_medico(struct Medico med[], struct Indice ind_medico[], int &cont, struct Especialidade esp[], struct Indice ind_esp[], int contEsp, struct Cidade cidade[], struct Indice ind_cidade[], int contCidade){
		cout<<"\n------REGISTRO "<<cont+1<<"------\n";
		for(int i =0; i != -1;){
		cout<<"Codigo: ";
		cin>>med[cont].codigo;
		cin.ignore();
			if(verifica_codigo(ind_medico, med[cont].codigo, cont) != 1){
				i = -1;
				cout<<"Nome: ";
				getline(cin,med[cont].nome);
				for(int x=0; x != -1;){
					cout<<"Codigo Especialidade: ";
					cin>>med[cont].codigo_esp;
					cin.ignore();
								
					int resultado = busca(ind_esp, contEsp, med[cont].codigo_esp);
					if(resultado != -1){
						cout<<"Especialidade: "<<esp[resultado].descricao;
						x = -1;
								
					} else cout<<"\nCodigo invalido!\n";
				} 
				
				cout<<"\nTelefone: ";
				getline(cin, med[cont].telefone);
				
				cout<<"Endereco: ";
				getline(cin, med[cont].endereco);
				
				for(int x =0; x != -1;){
					cout<<"Codigo Cidade: ";
					cin>>med[cont].codigo_cidade;
					cin.ignore();
								
					int resultado = busca(ind_cidade, contCidade, med[cont].codigo_cidade);
					if(resultado != -1){
						cout<<"Cidade: "<<cidade[resultado].nome<<"/"<<cidade[resultado].uf;
						x = -1;
								
					}else cout<<"\nCodigo invalido!\n";
				} 
				
				med[cont].status = 0;
				
				int i;
				for(i = cont - 1; i >= 0 and ind_medico[i].cod > med[cont].codigo; i--){
					ind_medico[i+1].cod = ind_medico[i].cod;
					ind_medico[i+1].end = ind_medico[i].end;
				} 
					ind_medico[i+1].cod = med[cont].codigo;
					ind_medico[i+1].end = cont;
					cont++;
					cout<<"\n\nMedico(a) incluido(a) com sucesso!\n";
	
				}else cout<<"\nEsse codigo ja esta cadastrado!\n";
		}
}

void exclusao_medico(struct Indice idx[], struct Medico vetor[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && vetor[i].status == 0){
        vetor[i].status = 1;
        cout << "\n\nMedico "<< vetor[i].nome << " excluido com sucesso!!";
    }
    else
        cout << "\nCodigo nao cadastrado";
    getch();
}


void excluir_medico(struct Medico medico[], struct Indice ind_medico[], int cont, struct Indice ind_pC[], int cont_consulta){
	int cod;
	
	for(int x = 0; x != 1;){
		cout<<"\nDigite o codigo que deseja excluir: ";
		cin>>cod;
		if(verifica_codigo(ind_pC, cod,cont_consulta) != 1){
			exclusao_medico(ind_medico, medico, cont, cod);
			x = 1;
		}
		else{
			cout<<"\n*** Esse medico nao pode ser excluido pois tem consulta agendada ***";
		}
	
	}
}

void reorganizacao_medico(struct Indice idx[], struct Medico medico[], int &cont){
    struct Medico novoVetor[cont];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (medico[i].status == 0){
            j++;
            novoVetor[j] = medico[i];
            idx[j].cod = novoVetor[j].codigo;
            idx[j].end = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].end;
    	medico[k] = novoVetor [i];
	}
}

//PACIENTE

void incluir_paciente(struct Paciente paciente[], struct Indice ind_paciente[], int &cont, struct Cidade cidade[], struct Indice ind_cidade[], int contCidade){
		cout<<"\n------REGISTRO "<<cont+1<<"------\n";
		for(int i =0; i != -1;){
		cout<<"Codigo: ";
		cin>>paciente[cont].codigo;
		cin.ignore();
			if(verifica_codigo(ind_paciente, paciente[cont].codigo, cont) != 1){
				i = -1;
				cout<<"Nome: ";
				getline(cin,paciente[cont].nome);
				cout<<"Endereco: ";
				getline(cin,paciente[cont].endereco);
				
				for(int x =0; x != -1;){
					cout<<"Codigo Cidade: ";
					cin>>paciente[cont].codigo_cidade;
					cin.ignore();
								
					int resultado = busca(ind_cidade, contCidade, paciente[cont].codigo_cidade);
					if(resultado != -1){
						cout<<"Cidade: "<<cidade[resultado].nome<<"-"<<cidade[resultado].uf;
						x = -1;
								
					}else cout<<"\nCodigo invalido!\n";
				} 
					paciente[cont].status = 0;		
				int i;
				for(i = cont - 1; i >= 0 and ind_paciente[i].cod > paciente[cont].codigo; i--){
					ind_paciente[i+1].cod = ind_paciente[i].cod;
					ind_paciente[i+1].end = ind_paciente[i].end;
				} 
					ind_paciente[i+1].cod = paciente[cont].codigo;
					ind_paciente[i+1].end = cont;
					cont++;
					cout<<"\n\nPaciente incluido(a) com sucesso!\n";
	
				}else cout<<"\nEsse codigo ja esta cadastrado!\n";
		}
}


void exclusao_paciente(struct Indice idx[], struct Paciente vetor[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && vetor[i].status == 0){
        vetor[i].status = 1;
        cout << "\n\nPaciente "<< vetor[i].nome <<" excluido com sucesso!!";
    }
    else
        cout << "\nCodigo nao cadastrado";
    getch();
}


void excluir_paciente(struct Paciente paciente[], struct Indice ind_paciente[], int cont, struct Indice ind_pC[], int cont_consulta){
	int cod;
	
	for(int x = 0; x != 1;){
		cout<<"\nDigite o codigo que deseja excluir: ";
		cin>>cod;
		if(verifica_codigo(ind_pC, cod,cont_consulta) != 1){
			exclusao_paciente(ind_paciente, paciente, cont, cod);
			x = 1;
		}
		else{
			cout<<"\n*** Esse paciente nao pode ser excluido pois tem consulta agendada ***";
		}
	
	}
}

void reorganizacao_paciente(struct Indice idx[], struct Paciente paciente[], int &cont){
    struct Paciente novoVetor[cont];
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (paciente[i].status == 0){
            j++;
            novoVetor[j] = paciente[i];
            idx[j].cod = novoVetor[j].codigo;
            idx[j].end = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].end;
    	paciente[k] = novoVetor [i];
	}
}

//CONSULTA

void consulta(struct Consulta consulta[], int &cont, struct Indice ind_consulta[], struct Paciente paciente[], struct Indice ind_paciente[], struct Indice ind_pacienteConsulta[], int cont_paciente, struct Cidade cidade[],struct Indice ind_cidade[],int cont_cidade, struct Medico medico[], struct Indice ind_medico[], int cont_medico,struct Indice ind_medConsulta[], struct CID cid[], struct Indice ind_cid[], int cont_cid, struct Medicamento medicamento[], struct Indice ind_medicamento[], int cont_medicamento, struct Especialidade esp[], struct Indice ind_esp[], int cont_esp){
	cout<<"\n------REGISTRO "<<cont+1<<"------\n";
	for(int i =0; i != -1;){
		cout<<"Codigo: ";
		cin>>consulta[cont].codigo;
		cin.ignore();
			if(verifica_codigo(ind_consulta, consulta[cont].codigo, cont) != 1){
				for(int x =0; x != -1;){
					cout<<"Codigo Paciente: ";
					cin>>consulta[cont].codigo_paciente;
					cin.ignore();
					
					int resultado_paciente = busca(ind_paciente, cont_paciente, consulta[cont].codigo_paciente);
					
					if(resultado_paciente != -1){
						cout<<"Nome: "<<paciente[resultado_paciente].nome;
						
						int resultado_cidade = busca(ind_cidade, cont_cidade, paciente[resultado_paciente].codigo_cidade);
						
						cout<<"\tCidade: "<<cidade[resultado_cidade].nome<<"/"<<cidade[resultado_cidade].uf;
						x = -1;
								
					}else cout<<"\nCodigo invalido!\n";
				} 
				for(int x =0; x != -1;){
					cout<<"\nCodigo Medico: ";
					cin>>consulta[cont].codigo_medico;
					cin.ignore();
					int resultado_medico = busca(ind_medico, cont_medico, consulta[cont].codigo_medico);
					if(resultado_medico != -1){
						cout<<"Nome: "<<medico[resultado_medico].nome;
						
						int resultado_esp = busca(ind_esp, cont_esp, medico[resultado_medico].codigo_esp);
						cout<<"\tEspecialidade: "<<esp[resultado_esp].descricao;
						x = -1;
								
					}else cout<<"\nCodigo invalido!\n";
				} 
				
				cout<<"\nData: ";
				cin>>consulta[cont].data;
				cout<<"Horario: ";
				cin>>consulta[cont].hora;
				
				for(int x =0; x != -1;){
					cout<<"Codigo CID: ";
					cin>>consulta[cont].codigo_cid;
					cin.ignore();
					int resultado_cid = busca(ind_cid, cont_cid, consulta[cont].codigo_cid);
					if(resultado_cid != -1){
						cout<<"CID: "<<cid[resultado_cid].descricao;
						
						x = -1;
								
					}else cout<<"\nCodigo invalido!\n";
				} 
				for(int x =0; x != -1;){
					cout<<"\nCodigo Medicamento: ";
					cin>>consulta[cont].codigo_medicamento;
					cin.ignore();
					int resultado_medicamento = busca(ind_medicamento, cont_medicamento, consulta[cont].codigo_medicamento);
					if(resultado_medicamento != -1){
						cout<<"Medicamento: "<<medicamento[resultado_medicamento].descricao;
						for(int d = 0; d != -1;){
						cout<<"\nQuantidade do Medicamento: ";
						cin>>consulta[cont].qtde_medicamento;
						if(medicamento[resultado_medicamento].qtde_estoque < consulta[cont].qtde_medicamento ){
							cout<<"\n\nNao ha estoque suficiente para essa quantidade";
							cout<<"\nEstoque Atual: " << medicamento[resultado_medicamento].qtde_estoque;
						}
						else{ 
						medicamento[resultado_medicamento].qtde_estoque = medicamento[resultado_medicamento].qtde_estoque - consulta[cont].qtde_medicamento;
						d = -1; x = -1; 
						}
					}
						
								
					}else cout<<"\nCodigo invalido!\n";
				} 
				
				cout<<"\n\nConsulta  agendada com sucesso!\n\n";
				i = -1;
				
			} else cout<<"\n***Esse codigo ja existe. Digite outro codigo***\n\n";
			
	}
				
				int i=0;
				for(i=cont-1; i>= 0 && ind_consulta[i].cod > consulta[cont].codigo ;i--){
				ind_consulta[i+1].cod = ind_consulta[i].cod;
				ind_consulta[i+1].end = ind_consulta[i].end;
				ind_medConsulta[i+1].cod = consulta[i].codigo_medico;
				ind_medConsulta[i+1].end = ind_consulta[i].end;
				ind_pacienteConsulta[i+1].cod = consulta[i].codigo_paciente;
				ind_pacienteConsulta[i+1].end = ind_consulta[i].end; 
			}
				ind_medConsulta[i+1].cod = consulta[cont].codigo_medico;
				ind_medConsulta[i+1].end = cont; 
				ind_pacienteConsulta[i+1].cod = consulta[cont].codigo_paciente;
				ind_pacienteConsulta[i+1].end = cont;
				ind_consulta[i+1].cod = consulta[cont].codigo;
				ind_consulta[i+1].end = cont;
				cont++;			
}

void valor_total(struct Consulta consulta[], int cont, struct Medicamento med[], struct Indice ind_med[],int cont_med){
	int valor_total = 0;
	for(int i =0; i<cont; i++){
		int x = busca(ind_med, cont_med, consulta[i].codigo_medicamento);
		valor_total = valor_total + 100 + consulta[i].qtde_medicamento * med[x].preco_unitario;
	}
	cout<<"\n\nValor Total Arrecadado R$"<< valor_total;
}



//IMPRIMIR DADOS

void imprimir_consultas(struct Consulta v[],struct Indice ind[], int cont){
	int cod;
	
	for(int x = 1; x != -1;){
	
		cout<<"\nInforme o codigo da consulta: ";
		cin>>cod;
		
		if(cod > 0){
		
			int resultado = busca(ind, cont, cod);
	
				if(resultado != -1){
					cout<<"\nCodigo Paciente: "<<v[resultado].codigo_paciente;
					cout<<"\nCodigo Medico: "<<v[resultado].codigo_medico;
					cout<<"\nData: "<<v[resultado].data;
					cout<<"\nHora: "<<v[resultado].hora;
					cout<<"\nCodigo CID: "<<v[resultado].codigo_cid;
					cout<<"\nCodigo Medicamento: "<<v[resultado].codigo_medicamento;
					cout<<"\nQuantidade de Medicamento: "<<v[resultado].qtde_medicamento<<endl;	
						
				} else cout<<"Codigo nao encontrado!";
		
		    } else x = -1;
		}	
}

void imprimir_medico(struct Indice ind[], struct Medico vetor[], int cont){
	for(int i=0; i<cont; i++){
		int k = ind[i].end;
		if(vetor[k].status == 0){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"\nCodigo: "<<vetor[k].codigo;
		cout<<"\nCodigo: "<<vetor[k].nome;
		cout<<"\nCodigo Especialidade: "<<vetor[k].codigo_esp;
		cout<<"\nTelefone: "<<vetor[k].telefone;
		cout<<"\nEndereco: "<<vetor[k].endereco;
		cout<<"\nCodigo Cidade: "<<vetor[k].codigo_cidade<<endl;
		}
	}
}

void imprimir_paciente(struct Indice ind[], struct Paciente vetor[], int cont){
	for(int i=0; i<cont; i++){
		int k = ind[i].end;
		if(vetor[k].status == 0){
		cout<<"\n------REGISTRO "<<i+1<<"------\n";
		cout<<"\nCodigo: "<<vetor[k].codigo;
		cout<<"\nNome: "<<vetor[k].nome;
		cout<<"\nEndereco: "<<vetor[k].endereco;
		cout<<"\nCodigo Cidade: " <<vetor[k].codigo_cidade<<endl;
		}
	}
}


void imprimir_cid(struct CID vetor[], int cont){
	for(int i=0; i<cont; i++){
		cout<<"\n\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: "<<vetor[i].codigo;
		cout<<"\nDescricao: "<<vetor[i].descricao;
	}
}

void imprimir_especialidade(struct Especialidade vetor[], int cont){
	for(int i=0; i<cont; i++){
		cout<<"\n\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: "<<vetor[i].codigo;
		cout<<"\nDescricao: "<<vetor[i].descricao;
	}
}


void imprimir_medicamento(struct Medicamento vetor[], int cont){
	for(int i=0; i<cont; i++){
		cout<<"\n\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: "<<vetor[i].codigo;
		cout<<"\nDescricao: "<<vetor[i].descricao;
		cout<<"\nQuantidade no Estoque: "<<vetor[i].qtde_estoque;
		cout<<"\nEstoque Minimo: "<<vetor[i].estoque_minimo;
		cout<<"\nEstoque Maximo: "<<vetor[i].estoque_maximo;
		cout<<"\nPreco Unitario: "<<vetor[i].preco_unitario;
	}
}

void imprimir_cidade(struct Cidade vetor[], int cont){
	for(int i=0; i<cont; i++){
		cout<<"\n\n------REGISTRO "<<i+1<<"------\n";
		cout<<"Codigo: "<<vetor[i].codigo;
		cout<<"\nCidade: "<<vetor[i].nome;
		cout<<"\nUF: "<<vetor[i].uf;
	}
}



int main(){
	
	//MEDICAMENTO
	struct Medicamento medicamentos[MaxMedicamento];
	struct Indice indice_medicamentos[MaxMedicamento] ={
	{1,0}, {2,1}
	};
	int cont_medicamento = 0;
	
	//MEDICO
	struct Medico medicos[MaxMedico];
	struct Indice indice_medicos[MaxMedico];
	struct Indice indice_medicosConsulta[MaxMedico];
	int cont_medico = 0;
	
	//CIDADE
	struct Cidade cidades[MaxCidade];
	struct Indice indice_cidades[MaxCidade] = {
	{1,0}, {2,1}, {3,2}
	};
	int cont_cidade = 0;
	
	//ESPECIALIDADE	
	struct Especialidade especialidades[MaxEspecialidade];
	struct Indice indice_especialidades[MaxEspecialidade] = {
    {1,0}, {2,1}
	};
	int cont_esp = 0;
	
	//PACIENTE
	struct Paciente pacientes[MaxPaciente] = {
		{		}
	};
	struct Indice indice_pacientes[MaxPaciente];
	struct Indice indice_pacientesConsulta[MaxPaciente];
	int cont_paciente = 0;
	
	//CID
	struct CID cids[MaxCID];
	struct Indice indice_cids[MaxCID] = {
	{1,0}, {2,1}
	};
	int cont_cid = 0;
	
	//CONSULTA 
	struct Consulta consultas[MaxConsulta];
	struct Indice indice_consultas[MaxConsulta] = {
	{1,0}, {2,1}
	};
	int cont_consulta = 0;
	
	
	int opcao, opcao_cidade, opcao_especialidade, opcao_medico, opcao_paciente, opcao_cid, opcao_medicamento, opcao_consulta;
	
	do{
		cout<<"  ________________________"<<endl;
		cout<<" |          MENU  	  |" <<endl;
		cout<<" | 1 - Cidade		  |"<<endl;
		cout<<" | 2 - Especialidade	  |"<<endl;
		cout<<" | 3 - Medico		  |"<<endl;
		cout<<" | 4 - Paciente 	  |"<<endl;
		cout<<" | 5 - CID 		  |"<<endl;
		cout<<" | 6 - Medicamento	  |"<<endl;
		cout<<" | 7 - Consulta	  	  |"<<endl;
		cout<<" | 8 - Sair    	  	  |"<<endl;
		cout<<" |________________________|"<<endl;
		cout<<"\n Digite uma opcao: ";
		cin>>opcao;
		system("cls");
		
		switch(opcao){
			case 1:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  CIDADE	  |" <<endl;
					cout<<" | 1 - Incluir   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_cidade;
				
					switch(opcao_cidade){
						case 1:{
							leitura_cidade(cidades,cont_cidade);
							
							system("cls");
							break;
						}
						case 2:{
							imprimir_cidade(cidades, cont_cidade);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(opcao_cidade != 3);
				break;
			}
			
			case 2:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  ESPECIALIDADE	  |" <<endl;
					cout<<" | 1 - Incluir        	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_especialidade;
				
					switch(opcao_especialidade){
						case 1:{
							leitura_especialidade(especialidades, cont_esp);
							system("cls");
							break;
						}
						case 2:{
							imprimir_especialidade(especialidades,cont_esp);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(opcao_especialidade != 3);
				break;
			}
			
			case 3:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  MEDICO	  |" <<endl;
					cout<<" | 1 - Incluir    	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Excluir   	  |"<<endl;
					cout<<" | 4 - Reorganizar  	  |"<<endl;
					cout<<" | 5 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_medico;
				
					switch(opcao_medico){
						case 1:{
							incluir_medico(medicos,indice_medicos, cont_medico, especialidades, indice_especialidades,cont_esp, cidades, indice_cidades, cont_cidade);
							getch();
							system("cls");
							break;
						}
						case 2:{
							imprimir_medico(indice_medicos, medicos, cont_medico);
							getch();
							system("cls");
							break;
						}
						case 3:{
							excluir_medico(medicos, indice_medicos, cont_medico, indice_medicosConsulta, cont_consulta);
							getch();
							system("cls");
							break;
						}
						case 4:{
							reorganizacao_medico(indice_medicos, medicos, cont_medico);
							cout<<"\n\nArquivo reorganizado com sucesso!!";
							getch();
							system("cls");
							break;
						}
						case 5:{
							system("cls");
							break;
						}
					}
				}while(opcao_medico != 5);
				break;
			}
		
			case 4:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  PACIENTE	  |" <<endl;
					cout<<" | 1 - Incluir   	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Excluir   	  |"<<endl;
					cout<<" | 4 - Reorganizar  	  |"<<endl;
					cout<<" | 5 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_paciente;
				
					switch(opcao_paciente){
						case 1:{
							incluir_paciente(pacientes, indice_pacientes, cont_paciente, cidades, indice_cidades, cont_cidade);
							getch();
							system("cls");
							break;
						}
						case 2:{
							imprimir_paciente(indice_pacientes, pacientes, cont_paciente);
							getch();
							system("cls");
							break;
						}
						case 3:{
							excluir_paciente(pacientes, indice_pacientes, cont_paciente, indice_pacientesConsulta, cont_consulta);
							getch();
							system("cls");
							break;
						}
						case 4:{
							reorganizacao_paciente(indice_pacientes, pacientes, cont_paciente);
							cout<<"\n\nArquivo reorganizado com sucesso!!";
							getch();
							system("cls");
							break;
						}
						case 5:{
							system("cls");
							break;
						}
					}
				}while(opcao_paciente != 5);
				break;
			}
		
			case 5:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |      MENU  CID	  |" <<endl;
					cout<<" | 1 - Incluir    	  |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_cid;
				
					switch(opcao_cid){
						case 1:{
							leitura_CID(cids,cont_cid);
							
							system("cls");
							break;
						}
						case 2:{
							imprimir_cid(cids, cont_cid);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(opcao_cid != 3);
				break;
			}
			
			case 6:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  MEDICAMENTO     |" <<endl;
					cout<<" | 1 - Incluir            |"<<endl;
					cout<<" | 2 - Consultar todos    |"<<endl;
					cout<<" | 3 - Consultar um   	  |"<<endl;
					cout<<" | 4 - Estoque Minimo     |"<<endl;
					cout<<" | 5 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_medicamento;
				
					switch(opcao_medicamento){
						case 1:{
							leitura_medicamento(medicamentos, cont_medicamento);
							system("cls");
							break;
						}
						case 2:{
							imprimir_medicamento(medicamentos, cont_medicamento);
							getch();
							system("cls");
							break;
						}
						case 3:{
							consultar_medicamento(medicamentos, indice_medicamentos, cont_medicamento);
							system("cls");
							break;
						}
						case 4:{
							estoque_minimo(medicamentos, cont_medicamento);
							getch();
							system("cls");
							break;
						}
						case 5:{
							system("cls");
							break;
						}
					}
				}while(opcao_medicamento != 5);
				break;
			}
			
			case 7:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  CONSULTA	  |" <<endl;
					cout<<" | 1 - Agendar Consulta   |"<<endl;
					cout<<" | 2 - Consultar   	  |"<<endl;
					cout<<" | 3 - Valor Arrecadado   |"<<endl;
					cout<<" | 4 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>opcao_consulta;
				
					switch(opcao_consulta){
						case 1:{
							consulta(consultas,cont_consulta, indice_consultas, pacientes, indice_pacientes, indice_pacientesConsulta, cont_paciente, cidades, indice_cidades, cont_cidade, medicos, indice_medicos,
							cont_medico, indice_medicosConsulta, cids, indice_cids, cont_cid, medicamentos, indice_medicamentos, cont_medicamento, especialidades, indice_especialidades,cont_esp);
							getch();
							system("cls");
							break;
						}
						case 2:{
							imprimir_consultas(consultas, indice_consultas, cont_consulta);
							getch();
							system("cls");
							break;
						}
							case 3:{
							valor_total(consultas, cont_consulta, medicamentos, indice_medicamentos, cont_medicamento);
							getch();
							system("cls");
							break;
						}
						
						case 4:{
							system("cls");
							break;
						}
					}
				}while(opcao_consulta != 4);
				break;
			}
			
			case 8: 
				system("cls");
            	cout<<"\n\t.......SAINDO DO PROGRAMA.....";
            	getch();
            	opcao = 8;
            	break;
            	
            default:
                cout << "\nOpcao invalida\n" << endl;
                break;
        }
        
    }while(opcao != 8);
	
	
}








