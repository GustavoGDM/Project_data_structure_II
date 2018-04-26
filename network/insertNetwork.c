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


int newVertex(Vertex** list,Vertex insert){
	if ( (*list) == NULL )
	{
		Vertex* aux;
		aux = (Vertex *) malloc(sizeof(Vertex));
		aux->id = insert.id;
		aux->inf = insert.inf;
		aux->nextEdge = NULL;
		aux->nextVertex = NULL;
		(*list) = aux;
		return 1;
	}
	else if( strcmp( (*list)->inf.name ,insert.inf.name) == 0 && (*list)->id == insert.id )
		return 0;
	else
		newVertex( &(*list),insert);
}

void insertNetworkVertex(Graph** graph,Vertex insert){
	if (newVertex((*graph)->listGraph,insert) == 1 )
		(*graph)->vert++;
	return;
}

Vertex* searchVertx(Vertex** list, int id ){
	if( (*list) == NULL)
		return NULL;
	else if((*list)->id == id)
		return (*list);
	else
		searchVertx((*list)->nextVertex,id);
}

Edge* searcheEdge(Vertex** list, int id ){
	if( (*list) == NULL)
		return NULL;
	else if((*list)->id == id)
		return (*list)->nextEdge;
	else
		searcheEdge((*list)->nextVertex,id);
}

int newEdge(Edge** adj,Edge insert){
	if((*adj) == NULL){
		Edge* aux;
		aux = (Edge *) malloc(sizeof(Edge));
		aux->id = insert.id;
		aux->avlbty = insert.avlbty;
		aux->transfer_speed = insert.transfer_speed;
		aux->nextEdge = NULL;
		return 1;
	}
	else if((*adj)->id == insert.id)
		return 0;
	else{
		newEdge( (*adj)->nextEdge,insert );
	}
}

void insertNetworkEdge(Graph** graph,Edge insert){
	Vertex* aux;
	aux = searcheEdge( &(*graph)->listGraph, insert.id);
	if (newEdge(&aux->nextEdge,insert))
		(*graph)->edge++;
	return;
}
