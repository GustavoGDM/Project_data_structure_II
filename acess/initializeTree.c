void  inicilizerTree(tree** root){
	FILE *file;
	infUser user;
	// insert(node* root,infUser user) 
	file = fopen("acess/acesso.dat","rb");
	if(file == NULL){
		printf("Erro, Arquivo não existe!\n");
		return;
	}
	while (1){
		fread(&user,sizeof(infUser),1,file);
		if(feof(file)){
			fclose(file);
			return;
		}
		insert(&(*root),user);
	}
	fclose(file);
}

void writeTree(tree** root,FILE* file){
	if(*root != NULL){
		fwrite(&(*root)->user,sizeof(infUser),1,file);
		writeTree(&(*root)->left,file);
		writeTree(&(*root)->right,file);
	}
}

void closingTree(tree** root){
	FILE *file;
	file = fopen("acess/acesso.dat","wb");
	writeTree(&(*root),file);	
	fclose(file);
}
