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

void readEdge(Graph** graph){
	Edge adj;
	FILE *file;
	file = fopen("network/Edge.dat","rb");
	if(file == NULL){
		printf("Erro, Arquivo não existe!\n");
		return;
	}
	while(1){

		fread(&adj,sizeof(Edge),1,file);
		if(feof(file))
		{
			fclose(file);
			return;
		}
		insertNetworkEdge( &(*graph),adj);
	}

}

void readVertex(Graph** graph){
	Vertex list;
	FILE *file;
	file = fopen("network/vertex.dat","rb");
	if(file == NULL){
		printf("Erro, Arquivo não existe!\n");
		return;
	}
	while(1){

		fread(&list,sizeof(Vertex),1,file);
		if(feof(file)){
			fclose(file);
			return;
		}
		insertNetworkVertex(&(*graph),list);
	}
}

void inicilizerGraph(Graph** graph){
	if((*graph) == NULL)
	{
		(*graph) = (Graph *) malloc(sizeof(Edge));
		(*graph)->vert =0;
		(*graph)->edge = 0;
		(*graph)->listGraph = NULL;
	}
	readVertex(&(*graph));
	readEdge(&(*graph));
	return;
}

void closingGraph(Graph** graph){
	FILE* fileVertex;
	FILE* fileEdge;
	Vertex *list = (*graph)->listGraph;
	fileVertex = fopen("network/vertex.dat","wb");
	fileEdge = fopen("network/Edge.dat","wb");
	Edge* adj;
	for (list ; list != NULL; list = list->nextVertex){
		fwrite(list,sizeof(Vertex),1,fileVertex);
		for (adj = list->nextEdge; adj != NULL ; adj = adj->nextEdge){
			fwrite(adj,sizeof(Edge),1,fileEdge);
		}
	}
}
