
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <locale>
#include <Windows.h>
#include <fstream>


using namespace std;


//  - - - - - - - - - DECLARAÇÃO DAS VARIÁVEIS - - - - - - - - -
char op;



//  - - - - - - - - - DECLARAÇÃO DAS FUNÇÕES - - - - - - - - -
void DesenhaMenu();
void inicializa_ficheiro();
void inicializa_ficheiro2();
bool ExisteNome(string nome);
int ContarNomesRepetidos();




//  - - - - - - - - - MAIN - - - - - - - - -
int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	locale::global(locale(""));
	//SetConsoleTitle(TEXT("  Text file aplications")); // Titulo da Aplicação
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	string nome;
	
	do
		{

		/*Chama a função*/
		DesenhaMenu();

		op = _getch(); 


		switch (op)
			{

			// L //
			case 'L': case 'l': // Apresenta o que está no ficheiro de texto
			{
				ifstream fpl("lista.txt");

				while (getline(fpl, nome))
					{
					cout << "\n" << nome << "\n";
					}

				fpl.close();

				break;
			}




			// E //
			case 'E': case 'e':
			{
			//Cria um ficheiro e escreve sempre uma nova linha (Não apaga o que foi colocado antes)
			ofstream fpd("lista.txt", ios::app);

			cout << "Por favor introduza um nome\n";
			getline(cin, nome);
			
			fpd << nome <<"\n";
			
			fpd.close();

			break;
			}



			// i //
			case 'I': case 'i': // Inicializa o ficheiro com vários nomes
			{
				inicializa_ficheiro();
				cout << "\nFoi criada uma lista com 16 nomes.\n\n";
				
			}
			break;
		

			// D //
			case 'D': case 'd':// Apaga o ficheiro
				
				if (remove("lista.txt") != 0)
					cout << "Não existe esse ficheiro";

				else cout << "Removido";

				break;


			// S //
			case 'S': case 's': // Substituir um nome na lista
			{
			string nomeCompleto; // Variável que vai receber o conjunto das strings do nome
			string *apontadorNome; // Endereço da memória
			string nomeTrocado;

			cout << "Qual o nome que deseja Substituir?\n";
			getline(cin, nomeCompleto);
			
			// Verificação se o endereço é atribuido
			// O i comercial (&) relaciona e indica qual é o endereço da variável nomeCompleto

			apontadorNome = &nomeCompleto; // O apontadorNome recebe o endereço da Varável nomeCompleto
			cout << "Endereço atribuido inicialmente: " << apontadorNome << "\n"; // Indica ou mostra o endereço atual da memória da variável nomeCompleto
			cout << "String que estava na Variavel: " << *apontadorNome << "\n"; // Indica ou mostra o "valor" da variável nomeCompleto

			// Através do endereço efetua-se a troca do valor da variável
			cout << "\n\nQual o nome que deseja trocar: ";
			getline(cin, nomeTrocado);

			// Verificação se foi alterado o "valor" da Variável
				nomeCompleto = nomeTrocado;
				cout << "Endereço da memoria Atual: " << apontadorNome << "\n";
				cout << "String que ficou na Variavel: " << *apontadorNome << "\n\n";

			if (nomeCompleto == nomeCompleto)
				{
					cout << "\nTroca efectuada com Sucesso!\n";
				}
			break;
			}

			// P //
			case 'P': case 'p': // Procura um nome "Completo" na lista
				
				cout << "Qual o nome que deseja procurar?\n";
				getline(cin, nome);

				if (ExisteNome(nome) == true)
					{
						cout << "O nome existe!\n";
					}
				else
					{
						cout << "O nome Nao existe!\n";
					}
					
					
				break;


			// M //
			case 'M': case 'm': // Coloca mais um nome no fim da lista
			{
				cout << "Introduza o nome que deseja acrescentar na lista: \n";
				getline(cin, nome);

				ofstream filePointerC("Lista.txt", ofstream::app);
				filePointerC << nome;
				filePointerC.close();
				cout << "Nome introduzido com sucesso!\n";
				break;
			}

			// C //
			case 'C': case 'c': // Conta os nomes da lista
			{

			int contador = 0;
			ifstream filePointerC("lista.txt");

			while (getline(filePointerC, nome))
				{
				contador++;
				}

			cout << "\nA lista contem: " << contador << " nomes \n\n";
			filePointerC.close();
			
			}
			
				break;

			// V //
			case 'V': case 'v': // Verifica se há nomes repetidos
			{
			inicializa_ficheiro2();
			ifstream fpl("lista.txt");
			while (getline(fpl, nome))
				{
				cout << "\n" << nome << "\n";
				}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			
				cout << "Existem " << ContarNomesRepetidos() << " nomes iguais a esse.\n";

			break;
			}
			
		

			default:

				cout << "\nA letra introduzida não faz parte do menu\n\n";
				break;
			}

		} while (op != 27); //O número 27 corresponde ao ESC em ASCI, ou seja, fecha o programa
}




//  - - - - - - - - - FUNÇÕES - - - - - - - - -
void DesenhaMenu()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		cout << "xx                                              xx\n";
		cout << "xx                MENU PRINCIPAL                xx\n";
		cout << "xx                                              xx\n";
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		cout << "xx                                              xx\n";
		cout << "xx  - (I)nicializar o ficheiro com 16 nomes.    xx\n";
		cout << "xx  - (L)istar os nomes da lista.               xx\n";
		cout << "xx  - (E)screver um nome no inicio da lista.    xx\n";
		cout << "xx  - (M)ais um nome no Fim da lista.           xx\n";
		cout << "xx  - (D)eletar ou apagar o ficheiro de texto.  xx\n";
		cout << "xx  - (S)ubstituir um nome na lista.            xx\n";
		cout << "xx  - (P)rocurar um nome na lista.              xx\n";
		cout << "xx  - (A)juda.                                  xx\n";
		cout << "xx  - (C)ontar nomes.                           xx\n";
		cout << "xx  - (V)erifica se existem nomes repetidos.    xx\n";
		cout << "xx                                              xx\n";
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}

//----------------------------------------------------------------------------
void inicializa_ficheiro()
	{
	ofstream fpd("lista.txt");
	fpd << "Ana Rita Cunha" << "\n";
	fpd << "Bela Costa Silva" << "\n";
	fpd << "Carlos Alberto Costa" << "\n";
	fpd << "Carlos Serafim Ferreira" << "\n";
	fpd << "Daniel Bastos Gomes" << "\n";
	fpd << "Diogo Silva Ferraz" << "\n";
	fpd << "Elvira Gomes Pendes" << "\n";
	fpd << "Fernanda Maria Silva" << "\n";
	fpd << "Fernando Gomes Barros" << "\n";
	fpd << "Gilherme Alexandre Barros" << "\n";
	fpd << "Hilda Fonseca Silva" << "\n";
	fpd << "José Manuel Carvalho" << "\n";
	fpd << "José Alberto Gomes" << "\n";
	fpd << "Maria Silvéria Bastos" << "\n";
	fpd << "Anabela Bastos Torres" << "\n";
	fpd << "Teodoro Armando Matos" << "\n";
	fpd.close();
	
	}

//------------------------------------------------------------------------------
void inicializa_ficheiro2()
	{
	ofstream fpd("lista.txt");
	fpd << "Ana Rita Cunha" << "\n";
	fpd << "Bela Costa Silva" << "\n";
	fpd << "Bela Costa Silva" << "\n";
	fpd << "Carlos Alberto Costa" << "\n";
	fpd << "Carlos Serafim Ferreira" << "\n";
	fpd << "Daniel Bastos Gomes" << "\n";
	fpd << "Diogo Silva Ferraz" << "\n";
	fpd << "Elvira Gomes Pendes" << "\n";
	fpd << "Fernanda Maria Silva" << "\n";
	fpd << "Fernando Gomes Barros" << "\n";
	fpd << "Gilherme Alexandre Barros" << "\n";
	fpd << "Hilda Fonseca Silva" << "\n";
	fpd << "José Manuel Carvalho" << "\n";
	fpd << "José Alberto Gomes" << "\n";
	fpd << "Maria Silvéria Bastos" << "\n";
	fpd << "Anabela Bastos Torres" << "\n";
	fpd << "Teodoro Armando Matos" << "\n";
	fpd << "Teodoro Armando Matos" << "\n";
	fpd << "Teodoro Armando Matos" << "\n";
	
	cout << "Foi criada uma lista com nomes repetidos.";
	fpd.close();
	}

//---------------------------------------------------------------------------

bool ExisteNome(string nome)
	{
	bool encontrado = false;
	string nomeProcuradoNoFicheiro;

	ifstream filePointerLetraP("lista.txt");

		while (getline(filePointerLetraP, nomeProcuradoNoFicheiro))
			{
			if (nome == nomeProcuradoNoFicheiro)
				{
				encontrado = true;
				} 
			}
		filePointerLetraP.close();
	return encontrado;
	}

//----------------------------------------------------------------------------------

int ContarNomesRepetidos()
	{
	string nomeDigitado;
	string nomeDoFicheiro;

	int contador = 0;

	cout << "\nDigite o nome a procurar: \n";
	getline(cin, nomeDigitado);
	ifstream fpV("lista.txt");

	while (getline(fpV, nomeDoFicheiro)) //Percorre as linhas

		{
		if (nomeDoFicheiro == nomeDigitado)
			{
			contador++;
			}
		
		}

	fpV.close();
	return contador;
	}

//------------------------------------------------------------------------------

void SubstituiNome()
	{
	string nomeSubstituido;
	string nomeAtual;
	bool encontraNome = false;
	ifstream filePointer("lista.txt");
	ofstream filePoiterTemporario("lista2.txt");

	cout << "Qual é o nome que deseja substituir?\n";
	getline(cin, nomeSubstituido);

	cout << "Qual o nome que quer introduzir na lista?\n";
	getline(cin, nomeAtual);

	// Caso o nome digitado exista, subtitui o nome atual
	while (getline(filePointer, nomeAtual))
		{
		if (nomeAtual == nomeSubstituido && encontraNome == false)
			{
			nomeAtual = nomeSubstituido;
			encontraNome = true;
			}

		nomeAtual += "\n";
		filePoiterTemporario << nomeAtual;
		}

	filePointer.close();
	filePoiterTemporario.close();

	int rem = remove("lista.txt");
	cout << rem;
	int ren = rename("lista2.txt", "lista.txt");
	cout << ren;
	}
	




//  - - - - - - - - - END FUNÇÕES - - - - - - - - -



