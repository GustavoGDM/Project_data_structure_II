// // -> Graph
// typedef struct
// {
// 	int id;
// 	int avlbty;//availability
// 	float transfer_speed;
// 	struct adj* nextEdge;
// }Edge;

// typedef struct
// {
// 	char name;
// 	char OS;
// 	char HD;
// }sit;

// typedef struct
// {
// 	int id;
// 	struct sit inf;
// 	struct adj* nextEdge;
// 	struct adj* nextVertex;
// }Vertex;

// typedef struct
// {
// 	int Vert;
// 	int Edge;
// 	struct Vertex* listGraph;
// }Graph;

void inicilizerGraph(Graph** graph){
	if((*graph) == NULL)
	{
		Graph* aux;
		aux = (Graph *) malloc(sizeof(Graph));
		aux->vert =0;
		aux->edge = 0;
		aux->listGraph = NULL;
		(*graph) =  aux;
	}
	readGraph(&(*graph));
	return;
}

void closingGraph(Graph** graph){
	Vertex* list,* listAux;
	Edge *adj,*adjAux;
	Files *file,*fileAux;
	for (list = (*graph)->listGraph ; list != NULL; list = list->nextVertex){
		for (adj = list->nextEdge; adj != NULL ; adj = adjAux){
			adjAux = adj->nextEdge;
			free(adj);
		}
		for ( file = list->nextFile ; file != NULL ; file = fileAux){
			fileAux = file->nextFile;
			free(file);
		}
	}
	for (list = (*graph)->listGraph ; list != NULL; list = listAux){
		listAux = list->nextVertex;
		free(list);
	}
	free((*graph));
}


void readGraph(Graph** graph){
	FILE *file;
	Graph aux;
	Vertex list;
	Edge adj;
	int i;
	file = fopen("network/network.dat","rb");
	if(file == NULL)
	{
		return;
	}
	fread(&aux,sizeof(Graph),1,file);
	for ( i = 0 ; i < aux.vert ; i++)
	{
		fread(&list,sizeof(Vertex),1,file);
		insertNetworkVertex(&(*graph),list);
	}
	for ( i = 0 ; i < aux.edge ; i++)
	{
		fread(&adj,sizeof(Edge),1,file);
		insertNetworkEdge( &(*graph), adj.listId, adj);
	}
	fclose(file);
}

void writeGraph(Graph** graph){
	FILE *file;
	Vertex* list;
	Edge* adj;
	Graph *aux = (*graph);
	file = fopen("network/network.dat","wb");
	fwrite(aux,sizeof(Graph),1,file);
	for (list = (*graph)->listGraph ; list != NULL; list = list->nextVertex)
		fwrite(list,sizeof(Vertex),1,file);
	for (list = (*graph)->listGraph ; list != NULL; list = list->nextVertex)
		for (adj = list->nextEdge; adj != NULL ; adj = adj->nextEdge)
			fwrite(adj,sizeof(Edge),1,file);
	fclose(file);
	return;

}
