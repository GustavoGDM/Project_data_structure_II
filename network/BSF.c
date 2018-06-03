// | -------------------------------------------------------------------------- |
// | ---------------------------- MINIMUM PATH COST --------------------------- |
// | -------------------------------------------------------------------------- |
int cstINFINITY(Graph** graph){
	int SUM = 0;
	Vertex* list;
	Edge* Adj;
	for (list= (*graph)->listGraph; list != NULL; list = list->nextVertex)
		for (Adj = list->nextEdge; Adj != NULL ; Adj = Adj->nextEdge)
			SUM += Adj->distance;
	return SUM;
}

int minPath( Graph** graph, int vertOrig, int vertDest)
{
   int hook[(*graph)->vert],v;
   int dist[(*graph)->vert];  
   int pa[(*graph)->vert];
   const int INFINITY = cstINFINITY(&(*graph));
   Edge* Adj;
   // inicialização:
   for (v = 0; v < (*graph)->vert; ++v)
      pa[v] = -1, dist[v] = INFINITY,hook[v]=-1;
   pa[vertOrig] = vertOrig, dist[vertOrig] = 0,hook[vertOrig] = vertOrig;
   Adj = searcheEdge(&(*graph)->listGraph,vertOrig);
   for (Adj ; Adj != NULL; Adj = Adj->nextEdge)
   {
      dist[Adj->id] = Adj->distance;
      hook[Adj->id] = vertOrig;
   }

   while (1) 
   {
      // cálculo de y:
      int y,z;
      int mindist = INFINITY;
      for (z = 0; z < (*graph)->vert; ++z)
         if (pa[z] == -1 && dist[z] < mindist) /* --> para cada vertitce não visitado com distância menor que dist[z] verificamos se  existe alguem não visitado nas fronteiras de 's' */
            mindist = dist[z], y = z; //-> atualizamos minDist e y
      if (mindist == INFINITY) /* -> Se minDist == INFINITY é porque não existe mais ninguem na fonteira a ser buscado */ 
         break;
      pa[y] = hook[y];
      // atualização de dist[]: 
      Adj = searcheEdge(&(*graph)->listGraph,y); // A partir dovertice com menor distancia localizada atraveis de 'y' 
      for (Adj ; Adj != NULL; Adj = Adj->nextEdge) // percorremos todas as aretas
      {
         int w = Adj->id;
         int distance = Adj->distance;
         if (!(dist[y] + distance >= dist[w]))
         {
            dist[w] = dist[y] + distance; // relaxa y-w (atualizamos os custos)
            hook[w] = y;
         }
      }
   }
   return dist[vertDest];
}
