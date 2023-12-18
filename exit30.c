#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
	write(STDOUT_FILENO,"Vous avez bien executé le programm exit30\n",strlen("Vous avez bien executé le programm exit30\n"));
	exit(30);
}
