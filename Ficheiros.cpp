
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <locale>
#include <Windows.h>


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
	SetConsoleTitle(TEXT("  Text file aplications")); // Titulo da Aplicação
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	string nome;
	
	do
		{

		/*Chama a função*/
		DesenhaMenu();

		op = _getch(); 


		switch (op)
			{

			case 'L': case 'l':
			{
				ifstream fpl("lista.txt");

				while (getline(fpl, nome))
					{
					cout << "\n" << nome << "\n";
					}

				//cout << nome << "\n";
				fpl.close();

				break;
			}

			case 'E': case 'e':
			{

	
			//Cria um ficheiro e escreve uma linha (Apaga sempre a primeira linha)
			ofstream fpd("lista.txt", ofstream::out);

			//Cria um ficheiro e escreve sempre uma nova linha (Não apaga o que foi colocado antes)
			//ofstream fpd("lista.txt", ios::app);

			cout << "Por favor introduza um nome\n";
			getline(cin, nome);
			
			fpd << nome << "\n";
			fpd.close();

			break;
			}

			case 'I': case 'i': // Inicializa o ficheiro com vários nomes
			{
				inicializa_ficheiro();
			
				
			}
			break;
		

			case 'D': case 'd':// Apaga o ficheiro
				
				if (remove("lista.txt") != 0)
					cout << "Não existe esse ficheiro";

				else cout << "Removido";

				break;



			case 'S': case 's':
				cout << "Qual o nome que deseja Substituir? ";
				getline(cin, nome);

				if (ExisteNome(nome) == true)
					{
					cout << "Nome a colocar na lista? \n";
					getline(cin, nome);
					system("clear || cls");
					ofstream fps("lista.txt", ios::app);
					fps << nome << "\n";
					fps.close();
					}
				else
					{
					cout << "O nome Não existe!\n";
					}

				break;



			case 'P': case 'p': // Procura um nome "Completo" na lista
				
				cout << "Qual o nome que deseja procurar? ";
				cin.ignore();
				getline(cin.ignore(), nome);

				if (ExisteNome(nome) == true)
					{
						cout << "O nome existe!\n";
					}
				else
					{
						cout << "O nome Nao existe!\n";
					}
					
					
				break;



			case 'M': case 'm': // Coloca mais um nome na lista
			{
				cout << "Introduza o nome que deseja acrescentar na lista: ";
				getline(cin, nome);

				ofstream filePointerC("Lista.txt", ofstream::app);
				filePointerC << nome;
				filePointerC.close();

				break;
			}


			case 'C': case 'c':
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
		cout << "xx  - (V)erifica se há nomes repetidos.         xx\n";
		cout << "xx                                              xx\n";
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}


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
	//cout << "Inicializado!";
	}

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
	fpd.close();
	//cout << "Inicializado!";
	}

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




//  - - - - - - - - - END FUNÇÕES - - - - - - - - -



