// typedef struct{
// 	char name[20];
// 	int id;
// 	struct *Files nextFile;
// }Files;

// typedef struct
// {
// 	int listId;
// 	int id;
// 	int avlbty;//availability
// 	float transfer_speed;
// 	int distance;
// 	struct Edge* nextEdge;
// }Edge;

// enum edgeFild {avlbty,transfer_speed,distance};

// typedef struct
// {
// 	char name[20];
// 	char OS[20];
// 	char HD[20];
// 	int diskSpace;
// 	int flag;

// }sit;

// typedef struct
// {
// 	int id;
// 	sit inf;
// 	Edge* nextEdge;
// 	Files* nextFile;
// 	struct Vertex* nextVertex;
// }Vertex;

// typedef struct
// {
// 	int vert;
// 	int edge;
//     Vertex* listGraph;
// }Graph;


void insertnewFile(Files** files ,Files insert){
	if( (*files) ==NULL ){
		Files *temp;
		temp =(Files *) malloc(sizeof(Files));
		temp->id = insert.id;
		strcpy(temp->name,insert.name);
		temp->nextFile = NULL;
		(*files) = temp;
		return;
	}
	else{
		insertnewFile(&(*files)->nextFile,insert);
	}
}

void removeFile(Vertex **list , char name[]){
	Files *fileBack = NULL,*fileAux = NULL;
	fileAux = (*list)->nextFile ; 
	while(fileAux != NULL){
		if (strcmp(fileAux->name,name) == 0)
			break;
		fileBack = fileAux;
		fileAux = fileAux->nextFile;
	}
	
	if ( fileBack == NULL && fileAux->nextFile != NULL )
	{
		(*list)->nextFile = fileAux->nextFile;
		free(fileAux);
	}
	else if ( fileBack != NULL && fileAux == NULL )
	{
		free(fileBack->nextFile);
		fileBack->nextFile = NULL;
	}
	else if ( fileBack == NULL && fileAux == NULL)
	{
		(*list)->nextFile = fileAux->nextFile;
		free(fileAux);
	}
	else if ( fileBack != NULL && fileAux != NULL )
	{
		fileBack->nextFile = fileAux->nextFile;
		free(fileAux);
	}
	return;
}

void showFileVertex(Vertex **list){
	Files *auxFile;
	for (auxFile = (*list)->nextFile; auxFile != NULL ; auxFile = auxFile->nextFile)
		printf("|-- FILE : %-0.20s\n",auxFile->name);
}

void showAllFileVertex(Vertex **list){
	Vertex *auxVert;
	for (auxVert = (*list) ; auxVert != NULL; auxVert = auxVert->nextVertex){
		printf("|-- Id[%02.2d] Nome : %-0.20s",auxVert->id , auxVert->inf.name );
		showFileVertex(&auxVert);
	}
}

void showSitesAndConnectionsAndFiles(Graph** graph){
	Vertex* list;
	Edge* adj;
	Files *auxFile;
	for (list = (*graph)->listGraph; list != NULL ; list = list->nextVertex )
	{
		printf("|-- Id[%02.2d] Nome : %-0.20s",list->id , list->inf.name );
		if(list->nextFile != NULL)
		{
			printf("|-> ARQUIVOS :\n");
			printf("|   \n");
			showFileVertex(&list);
		}
		printf("|-> CONEXOES\n");
		for (adj = list->nextEdge; adj != NULL ; adj = adj->nextEdge)
			printf("|     [-> Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n|     [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
		printf("|   \n");
	}
}

void insertFileNetwork(Graph** graph){
	Vertex* list;
	Files insert;
	printf("|--Insira o id do Vertice    \n|-- ");
	scanf("%i",&insert.id);
	list = searchVertx(&(*graph)->listGraph, insert.id );
	if ( list == NULL ){
		printf("|--Site nao existe \n");
		return;
	}
	printf("|--Insira o Nome  \n|-- ");
	fflush(stdin);
	scanf("%s",insert.name);
	insertnewFile(&list->nextFile,insert);
	printf("|--Inserido com sucesso\n");	
}


void removeFileNetwork(Graph** graph){
	Vertex* list;
	Files insert;
	printf("|--Insira o id do Vertice    \n|-- ");
	scanf("%i",&insert.id);
	list = searchVertx(&(*graph)->listGraph, insert.id );
	if (list == NULL){
		printf("|--Site nao existe \n");
		return;
	}
	printf("|--Insira o Nome do arquivo  \n|-- ");
	fflush(stdin);
	scanf("%s",insert.name);
	removeFile(&(*graph)->listGraph,insert.name);
	printf("|-- Excluido com sucesso \n");
}
