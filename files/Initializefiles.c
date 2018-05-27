void inicilizerFiles(Graph** graph){
	Vertex* list;
	FILE *file;
	Files aux;
	file = fopen("files/files.dat","rb");
	if(file == NULL){
		return;
	}
	while(1){
		fread(&aux,sizeof(Files),1,file);
		if(feof(file)){
			fclose(file);
			return;
		}
	list = searchVertx(&(*graph)->listGraph, aux.id );
	insertnewFile(&list->nextFile,aux);
	}
	fclose(file);
}

void writeFiles(Graph** graph){
	Vertex *list;
	FILE *file;
	Files *aux;
	file = fopen("files/files.dat","wb");
	for (list = (*graph)->listGraph; list != NULL ; list = list->nextVertex)
		for ( aux = list->nextFile ; aux != NULL ; aux = aux->nextFile)
			fwrite(aux,sizeof(Files),1,file);
	fclose(file);
	return;
}
