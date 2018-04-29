void excludeSite(Graph** graph){
	Edge* adj = NULL,*adjAux = NULL,*adjforth = NULL;
	Vertex site,*list,*listAux,*listBack =NULL;
	int option;
	printf("|--Insira o nome  \n|--");
	fflush(stdin);
	fgets(site.inf.name,20,stdin);
	for (list = (*graph)->listGraph; list != NULL ; list = list->nextVertex ){
		if (strcmp(site.inf.name,list->inf.name) == 0){
			break;
		}
		listBack = list;
	}
	if (list == NULL)
	{
		printf("|--Site nao existe \n");
		return;
	}
	printf("|______________________________________|\n");
	printf("|                                      |\n");
	printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",list->id , list->inf.name );
	for (adj = list->nextEdge; adj != NULL ; adj = adj->nextEdge)
		printf("|   |->Conexao : Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n|     [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );

	printf("|-- Voce deseja Excluir ? [1]sim [2]nao\n|-- ");
	scanf("%d",&option);
	if (option != 1)
		return ;
	// liberando todos as conecções que chegam no site
	listAux = list;
	for (list = (*graph)->listGraph ; list != NULL; list = list->nextVertex){
		adjAux =NULL;
		adjforth = NULL;
		for (adj = list->nextEdge; adj != NULL ; adj = adjforth){
			adjforth = adj->nextEdge;
			if (listAux->id == adj->id)
			{
				if(adjAux != NULL && adj->nextEdge != NULL ){
					adjAux->nextEdge = adj->nextEdge;
					free(adj);
				}else if(adjAux != NULL && adj->nextEdge == NULL){
					adjAux->nextEdge = NULL;
					free(adj);
				}else if (adjAux == NULL && adj->nextEdge == NULL)
				{
					list->nextEdge = NULL;
					free(adj);
				}else if(adjAux == NULL && adj->nextEdge != NULL){
					list->nextEdge = adj->nextEdge;	
				}
				(*graph)->edge--;
			}else
				adjAux = adj;
			
		}
	}
	// liberando todos as conecções que saem do site
	if (listAux->nextEdge != NULL){
		adj = listAux->nextEdge ;
		listAux->nextEdge = NULL;
		for (adj = listAux->nextEdge; adj != NULL ; adj = adjAux)
		{
			(*graph)->edge--;
			adjAux = adj->nextEdge;
			free(adj);
		}
	}
	//--> liberando o site
	if (listBack == NULL &&  listAux->nextEdge != NULL)
	{
		(*graph)->listGraph = listAux->nextVertex;
		free(listAux);
	}
	else if (listBack != NULL &&  listAux->nextEdge == NULL)
	{
		free(listBack->nextVertex);
		listBack->nextVertex = NULL;
	}
	else if (listBack == NULL &&  listAux->nextEdge == NULL)
	{
		(*graph)->listGraph = listAux->nextVertex;
		free(listAux);
	}
	else if (listBack != NULL &&  listAux->nextEdge != NULL)
	{
		listBack->nextVertex = listAux->nextVertex;
		free(listAux);
	}
	(*graph)->vert--;
	printf("|-- Excluido com sucesso \n");
	return;
}

void excludeConnection(Graph** graph){
	Edge* adj,*adjAux,*adjforth;
	int vert1;
	Vertex site,*aux;
	printf("|--Insira o nome  \n|--");
	fflush(stdin);
	fgets(site.inf.name,20,stdin);
	for (aux = (*graph)->listGraph; aux != NULL ; aux = aux->nextVertex )
		if (strcmp(site.inf.name,aux->inf.name) == 0)
			break;
	if (aux == NULL)
	{
		printf("|--Site nao existe \n");
		return;
	}else{
		printf("|______________________________________|\n");
		printf("|                                      |\n");
		printf("|-- Id[%02.2d]\n|-- Nome : %-0.20s",aux->id , aux->inf.name );
		for (adj = aux->nextEdge; adj != NULL ; adj = adj->nextEdge)
			printf("|   |->Conexao : Id[%02d]\n|     [-> Disponibilidade [%0d]\n|     [-> Tempo de trasferencia [%.2f]\n|     [-> Distancia em metros [%d]\n",adj->id,adj->avlbty,adj->transfer_speed,adj->distance );
	}
	printf("|--Insira o id Da Conexao\n|-- ");
	scanf("%d",&vert1);
	adjAux =NULL;
	for (adj = aux->nextEdge; adj != NULL ; adj = adjforth){
		adjforth = adj->nextEdge;
		if (vert1 == adj->id)
		{
			if(adjAux != NULL && adj->nextEdge != NULL ){
				adjAux->nextEdge = adj->nextEdge;
				free(adj);
			}else if(adjAux != NULL && adj->nextEdge == NULL){
				adjAux->nextEdge = NULL;
				free(adj);
			}else if (adjAux == NULL && adj->nextEdge == NULL)
			{
				aux->nextEdge = NULL;
				free(adj);
			}else if(adjAux == NULL && adj->nextEdge != NULL){
					aux->nextEdge = adj->nextEdge;	
					free(adj);
			}
			(*graph)->edge--;
			printf("|--Conexao excluida \n");
			return;
		}else
			adjAux = adj;
	}
		printf("|--Conexao nao existe \n");
		return;
}
