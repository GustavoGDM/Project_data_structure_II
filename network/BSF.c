// | -------------------------------------------------------------------------- |
// | ---------------------------- MINIMUM PATH COST --------------------------- |
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

int cstINFINITY(Graph** graph,int option){
	int SUM = 0;
	Vertex* list;
	Edge* Adj;
	for (list= (*graph)->listGraph; list != NULL; list = list->nextVertex)
	{
		for (Adj = list->nextEdge; Adj != NULL ; Adj = Adj->nextEdge)
		{
			SUM += Adj->distance;
		}
	}
	return SUM;
}

