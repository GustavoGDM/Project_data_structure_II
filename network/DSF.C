// | -------------------------------------------------------------------------- |
// | ------------------------------- SEARCH PATH ------------------------------ |
// | -------------------------------------------------------------------------- |

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

static float visit[100];

static float maxPath( Vertex** list, int option, int vert1, int vert2)
{
	float maxv = -1;
	Vertex *listAux;
	if (vert1 == vert2){
		return 0;
	}
	visit[vert1] = 1;
	Edge* Adj;
	listAux = searchVertx(&(*list),vert1);
	for (Adj = listAux->nextEdge ; Adj !=NULL ; Adj = Adj->nextEdge)
	{
		if (visit[Adj->id] == 0) 
		{
			float maxw = maxPath( &(*list),option,Adj->id,vert2);
			if (option == transfer_speed){
				if (maxw != -1 && maxv < Adj->transfer_speed + maxw){
					maxv = Adj->transfer_speed + maxw;
				}
			}
			else if (option == avlbty){
				if (maxw != -1 && maxv < Adj->avlbty + maxw){
					maxv = Adj->avlbty + maxw;
				}
			}
		}
	}
	visit[vert1] = 0; 
	return maxv;
}

float searchMaxPath( Graph ** graph,int option,int vertOrig, int vertDest)
{
	int vert;
	for (vert = 0; vert < (*graph)->vert; ++vert) 
		visit[vert] = 0;

	return maxPath( &(*graph)->listGraph, option,vertOrig, vertDest);
}
