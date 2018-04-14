#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//_______________________________________________________________________
// #Funções basica necessaria                                            |
// 1ª inserir													         |
// 2ª verificar se existe um username igual 							 |
// 3ª buscar e retornar dados do usuário e permição de acceso 			 |
//_______________________________________________________________________|
//																		 |
// #Funcoes Especificas													 |
// 1ª Manipular dados cadastrados-> Só autorizaçã de adm tem acesso		 |
// 2ª Manipular dados dos sites-> Só autorizaçã de adm tem acesso		 |
// 3ª Iniciar o programa  -> ler os cadastros do arquivo				 |
// 4ª Finalizar o programa -> Gravar em disco os dados de acesso;	     |
//_______________________________________________________________________|


typedef struct
{
	int username;
	char name[80];
	char password[10];
	int permition;
}infUser;
	enum permition {noAcess,basicUser,adimin};

typedef struct {
	infUser user;
	struct tree *left; // esquerda 
	struct tree *right; // direita
	int bal;
}tree;

typedef tree* node;

#include "acess\acess.h"

int main()
{
	tree *root=NULL;
	inicilizerFiles(&root);
	//insertUser(&root);
	login(&root);

	closingFiles(&root);
	return 0;
}

