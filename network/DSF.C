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


static int visit[100];
int searchMaxPath( Graph ** graph,int option,int vert_orig, int vert_dest)
{
	int vert,visit[(*graph)->vert];
   for (vert = 0; vert < (*graph)->vert; ++vert) 
      visit[v] = 0;
   return maxPath( &(*graph)->listGraph, &visit,vert_orig, vert_dest);
}

int maxPath( lista ** list,int visit [], int option, int vert1, int vert2)
{
   int maxv = -1;
   if (vert1 == vert2) 
      return 0;
   visit[vert1] = 1;
   Edge* Adj;
	Adj = buscarAdj(&(*list),vert1);
	for (Adj ; Adj !=NULL ; Adj = Adj->nextEdge){
      if (visit[Adj->v] == 0) {
         int maxw = maxPath( &(*list), &visit,option,Adj->vert1,vert2);
         if (maxw != -1 && maxv < Adj->cst + maxw){
         	switch(option){
         		case transfer_speed:
         		maxv = Adj->cst + maxw;
         		break;
         		case avlbty:
         		maxv = Adj->cst + maxw;
         		break;
         	}
         } 
            
      }
   }
   visit[vert1] = 0; 
   return maxv;
}