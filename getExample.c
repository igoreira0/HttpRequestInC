#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_SAVE_REQUEST "--output /tmp/read.txt"
#define SERVER_TO_REQUEST "jsonplaceholder.typicode.com/posts"
#define GET_HEADER "curl -I --head"
#define GET_BY_ID "?id="

void main(int argc, char *argv[ ]){
    int i;
    FILE *fh;
    size_t len;
    char *buf,*path;
    if(argc == 1){
        path = malloc( (sizeof("curl ")) + (sizeof(SERVER_TO_REQUEST)) + (sizeof(PATH_SAVE_REQUEST)) );
        sprintf(path,"curl %s %s",SERVER_TO_REQUEST,PATH_SAVE_REQUEST);
        printf("%s\n",path);
        system(path);
        fh = fopen("/tmp/read.txt","rb");
        if(!fh){
            printf("cant open file in %s",PATH_SAVE_REQUEST);
            return;
        }

        fseek(fh, 0, SEEK_END);
        len = ftell(fh);
        rewind(fh);

        buf = malloc(len);
        fread(buf, 1, len, fh);
        buf[len] = '\0';

        printf("\nJSON RECEIVED:\n%s",buf);
        free(buf);
        free(path);
        pclose(fh);
    }
    for(i=1;i<argc;i++)
    {
        if(argc>1)   
        {
            path = malloc( (sizeof("curl ")) + (sizeof(SERVER_TO_REQUEST)) + (sizeof(PATH_SAVE_REQUEST)) + (sizeof(GET_BY_ID)) + (strlen(argv[i])) );
            sprintf(path,"curl %s%s%s %s",SERVER_TO_REQUEST,GET_BY_ID,argv[i],PATH_SAVE_REQUEST);
            printf("%s\n",path);
        }
        else return;
        system(path);
        fh = fopen("/tmp/read.txt","rb");
        if(!fh){
            printf("cant open file in %s",PATH_SAVE_REQUEST);
            return;
        }

        fseek(fh, 0, SEEK_END);
        len = ftell(fh);
        rewind(fh);

        buf = malloc(len);
        fread(buf, 1, len, fh);
        buf[len] = '\0';

        printf("\nJSON RECEIVED:\n%s",buf);
        free(buf);
        free(path);
        pclose(fh);
    }
}