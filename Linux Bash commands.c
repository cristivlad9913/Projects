#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int copiere(char *nume_src,char *nume_dest)
{
	FILE *src,*dest;
	char a;
	src=fopen(nume_src,"r");

	if(src==NULL)
 	{
  		printf("Nu s-a putut deschide fisierul sursa.\n");
  		perror(NULL);
 		return -1;
  	}
	nume_dest[strlen(nume_dest)-1]='\0';
	dest=fopen(nume_dest,"w");

	if(src==NULL)
 	{
 		fclose(src);
  		printf("Nu s-a putut deschide fisierul destinatie.\n");
		perror(NULL);
  		return -1;
  	}

	a=fgetc(src);

	while( a!=EOF)
 	{
 		fputc(a,dest);
  		a=fgetc(src);
 	}

	printf("Copierea a reusit.\n");
	fclose(src);
	fclose(dest);

return 0;
}

int stergere(char *nume)
{
	int n;
	char *aux;
//nume[strlen(nume)-1]='\0';

	if(!remove(nume))
		printf("Stergerea fisierului a reusit.\n");
	else
	{
		printf("A aparut o eroare la stergere.\n");
		perror(NULL);
	}

return 0;
}



int mutare(char *nume_src,char *nume_dest)
{

	FILE *src,*dest;
	char a;
	src=fopen(nume_src,"r");
	nume_dest[strlen(nume_dest)-1]='\0';
	dest=fopen(nume_dest,"w");

	if(src==NULL)
	{
		printf("Eroare.\n");
		perror(NULL);
		return -1;
	}

	if(dest==NULL)
	{
		fclose(src);
		printf("Eroare.\n");
		perror(NULL);
		return -1;
	}

	a=fgetc(src);

	while( a!=EOF)
	{
  		fputc(a,dest);
  		a=fgetc(src);
	}

	if(!remove(nume_src))
		printf("Mutarea fisierului a reusit.\n");
	else
	{
		printf("A aparut o eroare la mutare.\n");perror(NULL);return -1;
	}

	fclose(src);
	fclose(dest);

return 0;
}


int listare()
{
    int status;
    char *args[2];
    args[0]="/bin/ls";
    args[1]=NULL;
    if (fork()==0)
        execv(args[0],args);
    else
        wait(&status);

return 0;
}


int director(char *nume)
{
	int a;
	nume[strlen(nume)-1]='\0';
	a=mkdir(nume,S_IRWXO|S_IRWXU|S_IRWXG);
	if(a==-1)
	{
		printf("Nu s-a putut crea.\n");
		perror(NULL);
		return -1;
	}
	else
	{
		printf("Director creat.\n");
		return 0;
	}

}

int main()
{
	char sir[100];
	int sw=0;
	system("clear");
	printf("%s\t","Comenzi disponibile:\n");
	printf("\n\n");
	printf("\tcp   - Copiaza fisiere\n");
	printf("\trm   -Sterge fisier\n");
	printf("\tmv   -Mutare fisier\n");
	printf("\tmkdir  -Creeaza un nou director\n");
	printf("\tls  -Afisare file\n");
	printf("\tclear  -Curatare\n");
	printf("\texit -Iesire\n");

	while(sw==0)
	{
		printf("%s","Input:\n");
		read(0,sir,100);

		char *sep=" ,?";
		char *token=strtok(sir,sep),*c[100];
		int i=0;

		while(token!=NULL)
	 	{
           		c[i]=token;
           		i++;
           		token=strtok(NULL,sep);
          	}

		if(strcmp(c[0],"exit")==10)
	 		sw=1;
		if(strcmp(c[0],"cp")==0)
			copiere(c[1],c[2]);
		if(strcmp(c[0],"rm")==0)
	 		stergere(c[1]);
		if(strcmp(c[0],"mkdir")==0)
	 		director(c[1]);
		if(strcmp(c[0],"ls")==10)
	 		listare();
		if(strcmp(c[0],"mv")==0)
         		mutare(c[1],c[2]);

		if(strcmp(c[0],"clear")==10 && strcmp(c[0],"mv")!=0)
		{
        		system("clear");
			printf("%s\t","Comenzi disponibile:\n");
			printf("\n\n");
			printf("\tcp   - Copiaza fisiere\n");
			printf("\trm   -Sterge fisier\n");
			printf("\tmv   -Mutare fisier\n");
			printf("\tmkdir  -Creeaza un nou director\n");
			printf("\tls  -Afisare file\n");
			printf("\tclear  -Curatare\n");
			printf("\texit -Iesire\n");
		}

        }

return 0;
}
