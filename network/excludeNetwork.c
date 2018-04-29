// -> Graph
// typedef struct{
// 	int id;
// 	int avlbty; //availability
// 	float transfer_speed;
// 	struct adj* nextAdj;
// }adj;

// typedef struct{
// 	char name;
// 	char OS;
// 	char HD;
// }sit;

// typedef struct{
// 	int id;
// 	struct sit node;
// 	struct adj* nextAdj;
// 	struct adj* nextList;
// }list;

// typedef struct{
// 	int Vert;
// 	int Edge;
// }graph;

void excludeSite(Graph** graph){
	Edge* adj,* adjAux,*adjNext;
	Vertex site,*list,*listAux;
	int option;
	printf("|--Insira o nome  \n|--");
	fflush(stdin);
	fgets(site.inf.name,20,stdin);
	printf("|______________________________________|\n");
	printf("|                                      |\n");
	for (list = (*graph)->listGraph; list != NULL ; list = list->nextVertex ){
		if (strcmp(site.inf.name,list->inf.name) == 0){
			break;
		}
		listAux = list;
	}
	if (list == NULL)
	{
		printf("|--Site nao existe ");
		return;
	}else{
		printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",list->id , list->inf.name );
		printf("|-- SO : %-0.20s|-- HD : %-0.20s",list->inf.OS , list->inf.HD );
		printf("|-- Disk Space : %d\n",list->inf.diskSpace);
		for (adj = list->nextEdge; adj != NULL ; adj = adj->nextEdge)
			printf("     |->  Id[%02d] -> Disponibilidade [%02d] -> Tempo de trasferência [%.2f] -> Distancia [%d] ",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
	}
	printf("\n|--Voce deseja Excluir ? [1]sim [2]nao");
	scanf("%d",&option);
	// liberando todos as conecções que chegam no site
	for (list = (*graph)->listGraph ; list != NULL; list = list->nextVertex)
	{
		for (adj = list->nextEdge; adj != NULL ; adj = adjNext)
		{
				adjNext = adj->nextEdge;
				if (list->id == adj->id)
				{
					adjAux->nextEdge = adj->nextEdge;
					free(adj);
				}
				else
				{
					adjAux = adj;
				}
		}
	}
	// liberando todos as conecções que saem do site
	list = listAux->nextVertex;
	for (adj = list->nextEdge; adj != NULL ; adj = adjAux)
	{
		adjAux = adj->nextEdge;
		free(adj);
	}
	// liberando o site
	list = listAux->nextVertex;
	listAux->nextVertex = list->nextVertex;
	free(list);
}
