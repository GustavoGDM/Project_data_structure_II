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

void insertnewFile(Vertex **list,Files insert){
	if( (*list)==NULL )
		return;
	else if ((*list)->id == insert.id )
	{
		Files **aux = (*list)->nextFile;
		while( (*aux) != NULL){
			(*aux) = (*aux)->nextFile;
		}
		Files *temp;
		temp =(Files *) malloc(sizeof(Files));
		temp->id = insert.id;
		strcpy(temp->name,insert.name);
		temp->nextFile = NULL;
		(*aux) = temp;
		return;
	}
	else
	insertnewFile(&(*list)->nextVertex,insert);
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
	printf("|-- Excluido com sucesso \n");
	return;
}

void showFileVertex(Vertex **list ,int vert ){
	Files *auxFile;
	for (auxFile = (*list)->nextFile; auxFile != NULL ; auxFile = auxFile->nextFile)
		printf("\n|-- NAME : %-0.20s",auxFile->name);
}

void showAllFileVertex(Vertex **list ,int vert ){
	Files *auxFile;
	Vertex *auxVert;
	for (auxVert = (*list) ; auxVert != NULL; auxVert = auxVert->nextVertex){
		printf("\n|-- ID : %d",auxVert->id);
		for (auxFile = auxVert->nextFile; auxFile != NULL ; auxFile = auxFile->nextFile)
			printf("\n|-- FILE : %-0.20s",auxFile->name);
	}
}
