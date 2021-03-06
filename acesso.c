#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
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

// -> Tree
typedef struct
{
	int username;
	char name[20];
	char password[10];
	int permition;
}infUser;

enum permition {noAcess,basicUser,adimin};
enum userFild {username,name,password,permition};

typedef struct {
	infUser user;
	struct tree *left; // esquerda
	struct tree *right; // direita
	int bal;
}tree;

typedef tree* node;

// -> Graph
typedef struct{
	char name[20];
	int id;
	struct Files* nextFile;
}Files;

typedef struct
{
	int listId;
	int id;
	int avlbty;//availability
	float transfer_speed;
	int distance;
	struct Edge* nextEdge;
}Edge;

enum edgeFild {avlbty,transfer_speed,distance};

typedef struct
{
	char name[20];
	char OS[20];
	char HD[20];
	int diskSpace;
	int flag;

}sit;

typedef struct
{
	int id;
	sit inf;
	Edge* nextEdge;
	Edge* nextFile;
	struct Vertex* nextVertex;
}Vertex;

typedef struct
{
	int vert;
	int edge;
    Vertex* listGraph;
}Graph;

#include "network\network.h"
#include "acess\acess.h"
#include "login\login.h"
#include "files\files.h"

int main()
{
	tree *root = NULL;
	Graph *graph = NULL;
	inicilizerTree(&root);
	inicilizerGraph(&graph);
	inicilizerFiles(&graph);
	login(&root,&graph);
	closingTree(&root);
	writeFiles(&graph);
	writeGraph(&graph);
	closingGraph(&graph);
	return 0;
}

