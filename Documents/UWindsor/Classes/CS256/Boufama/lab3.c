#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	if (argc != 3){
		printf("Usage: lab3 <string> <string>\n");
		return 1;
	}
    
	FILE *fp1, *fp2;
	int x=0;
	char buffer[100];
    
	if(((fp1=fopen(argv[1], "r")) == NULL) ||
       ((fp2=fopen(argv[2], "w")) == NULL)){
		printf("No open las files\n");
		return 2;
	}
    
	fseek(fp1, 0, SEEK_END);
	int size = ftell(fp1);
	fseek(fp2, size, SEEK_SET);
	x=0;
	rewind(fp1);
	printf("%d size\n", size);
	while(size != 0){
		fgets(buffer, 99, fp1);
		printf("%s", buffer);
		x+=strlen(buffer);
		printf("%d\n", (int)strlen(buffer));
		fseek(fp2, -x, SEEK_END);
		fputs(buffer, fp2);
		size-=strlen(buffer);
		printf("%d size\n", size);
	}
	return 0;
}
