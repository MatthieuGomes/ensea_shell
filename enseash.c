#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
	write(STDOUT_FILENO,"Bienvenue dans le Shell ENSEA.\nPour quitter, tapez \'exit\'.\n",strlen("Bienvenue dans le Shell ENSEA.\nPour quitter, tapez \'exit\'.\n"));
	char reponse[100]="";
	int returncode=0;
	char header[110];
	while(1){

		char waitmsg[100]="enseash";
		*header='\0';
		if(strlen(reponse)>0){
			strcat(header," [");
			strcat(header,reponse);
			strcat(header,":");
			char strreturncode[2];
			sprintf(strreturncode, "%d", returncode);
			strcat(header,strreturncode);

			strcat(header,"]");
			strcat(waitmsg,header);
		}
		strcat(waitmsg," % ");
		*reponse='\0';
		write(STDOUT_FILENO,waitmsg,strlen(waitmsg));
		returncode=0;
		int size=read(STDIN_FILENO,reponse,100);
		reponse[size-1]='\0';
		if(strcmp(reponse,"exit")==0){
			write(STDOUT_FILENO,"Bye bye...\n",strlen("Bye bye...\n"));	
			return 0;
		}
		else{
			int pid,status;
			
			pid=fork();
			
			if(pid!=0){
				wait(&status);

			}
			else{
				execlp(reponse,reponse,(char*) NULL);
			}
			returncode=WEXITSTATUS(status);
		}
	}
	return 0;
}
