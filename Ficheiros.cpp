
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <locale>
#include <Windows.h>
using namespace std;

//  - - - - - - - - - DECLARA��O DAS VARI�VEIS - - - - - - - - -
char op;



//  - - - - - - - - - DECLARA��O DAS FUN��ES - - - - - - - - -
void DesenhaMenu();
void inicializa_ficheiro();
bool ExisteNome(string nome);




//  - - - - - - - - - MAIN - - - - - - - - -
int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	locale::global(locale(""));
	SetConsoleTitle(TEXT("  Text file aplications")); // Titulo da Aplica��o
	setlocale(LC_ALL, "Portuguese");//habilita a acentua��o para o portugu�s
	string nome;
	
	do
		{

		/*Chama a fun��o*/
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

			case 'N': case 'n':
			{

	
			//Cria um ficheiro e escreve uma linha (Apaga sempre a primeira linha)
			ofstream fpd("lista.txt", ofstream::out);

			//Cria um ficheiro e escreve sempre uma nova linha (N�o apaga o que foi colocado antes)
			//ofstream fpd("lista.txt", ios::app);

			cout << "Por favor introduza um nome\n";
			getline(cin, nome);
			
			fpd << nome << "\n";
			fpd.close();

			break;
			}

			case 'Z': case 'z':
			{
				inicializa_ficheiro();
			}
				break;

			case 'D': case 'd':// Apaga ficheiro
				
				if (remove("lista.txt") != 0)
					cout << "N�o existe esse ficheiro";

				else cout << "Removido";

				break;

			case 'S': case 's':
				cout << "Qual o nome que deseja Substituir? ";
				getline(cin, nome);

				if (ExisteNome(nome) == true)
					{
					ofstream fpd("lista.txt", ofstream::out);
					}
				else
					{
					cout << "O nome N�o existe!";
					}

				break;

			case 'P': case 'p':
				
				cout << "Qual o nome que deseja procurar? ";
				getline(cin, nome);

				if (ExisteNome(nome) == true)
					{
						cout << "O nome existe!";
					}
				else
					{
						cout << "O nome N�o existe!";
					}
					
					
				break;

			case 'J':
				break;

			case 'K':
				break;


			default:

				cout << "\nA letra introduzida n�o faz parte do menu\n\n";
				break;
			}

		} while (op != 27); //O n�mero 27 corresponde ao ESC em ASCI, ou seja, fecha o progrma
}




//  - - - - - - - - - FUN��ES - - - - - - - - -
void DesenhaMenu()
	{
		cout << "\n - (L)istar ficheiro \n";
		cout << "\n - escrever (N)o inicio do ficheiro\n";
		cout << "\n - iniciali(Z)ar ficheiro com 16 nomes\n";
		cout << "\n - (D)eletar ficheiro\n";
		cout << "\n - (S)ubstituir nome do ficheiro\n";
		cout << "\n - (P)rocurar nome do ficheiro\n";
		cout << "\n - a(J)uda\n";
		cout << "\n - (K) outra op��o\n";
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
	fpd << "Jos� Manuel Carvalho" << "\n";
	fpd << "Jos� Alberto Gomes" << "\n";
	fpd << "Maria Silv�ria Bastos" << "\n";
	fpd << "Anabela Bastos Torres" << "\n";
	fpd << "Teodoro Armando Matos" << "\n";
	fpd.close();
	cout << "Inicializado!";
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
//  - - - - - - - - - END FUN��ES - - - - - - - - -



