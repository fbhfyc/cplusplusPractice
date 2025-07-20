#include <stdio.h>

int main()
{
	/*
	FILE* fp =fopen("./tmp.txt","w");
        if ( !fp ) {
		return -1;
	}

	const char * buffer = "i am fbh";
	for (int i=0; i<100; ++i) {
	    fprintf(stdout,"[%d]--%s\n",i,buffer);
	}
	char buffer[100];
	int age =30;
	float height = 1.75;

	int count = sprintf(buffer,"age:%d, height:%f",age,height);
	fprintf(stdout,"buffer is: %s\n",buffer);
	fprintf(stdout,"count is : %d\n",count);

	int res = snprintf(NULL,0,"--%d**",100);
	fprintf(stdout, "[%d]",res);
	*/

	char buf[10];
	int res = snprintf(buf, 10, "hello,%s!","world");
 	printf("[%d]\n",res);
 	printf("buffer[%s]\n",buf);
	return 0;
}
