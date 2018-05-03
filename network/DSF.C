// | -------------------------------------------------------------------------- |
// | ------------------------------- SEARCH PATH ------------------------------ |
// | -------------------------------------------------------------------------- |
// typedef struct
// {
// 	int listId;
// 	int id;
// 	int avlbty;//availability
// 	float transfer_speed;
// 	int distance;
// 	struct Edge* nextEdge;
// }Edge;

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
// 	struct Vertex* nextVertex;
// }Vertex;

// typedef struct
// {
// 	int vert;
// 	int edge;
//     Vertex* listGraph;
// }Graph;



static void path(Vertex** list,int vert, int visit[] ){
	visit[vert] = 1;
	Edge *adj;
	adj = searcheEdge(&(*list),vert);
	if(adj != NULL){
		for (adj ; adj != NULL; adj = adj->nextEdge)
			if (visit[adj->id] == 0)
				path(&(*list),adj->id,visit);
			
	}

}

int seachPath(Graph** graph,int vert1,int vert2){
	int visit[(*graph)->vert];
	int i;
	for ( i = 0; i < (*graph)->vert ; ++i)
		visit[i] = 0;
	path(&(*graph)->listGraph,vert1,&visit);
	if (visit[vert2])
		return 1;
	else
		return 0;
}
