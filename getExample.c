#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_SAVE_REQUEST "--output /tmp/read.txt"
#define SERVER_TO_REQUEST "jsonplaceholder.typicode.com/posts"
#define GET_HEADER "curl -I --head"

void main(){

    FILE *fh = fopen("/tmp/read.txt","rb");
    size_t len;
    char *buf,*path;
    path = malloc( (sizeof(SERVER_TO_REQUEST)) + (sizeof(PATH_SAVE_REQUEST)) + (sizeof(GET_HEADER)) );
    sprintf(path,"%s %s %s",GET_HEADER,SERVER_TO_REQUEST,PATH_SAVE_REQUEST);
    printf("%s\n",path);
    system(path);

    if(!fh){
        printf("cant open file in %s",PATH_SAVE_REQUEST);
        return;
    }

    fseek(fh, 0, SEEK_END);
    len = ftell(fh);
    rewind(fh);

    buf = malloc(len);
    fread(buf, 1, len, fh);

    if(memcmp(buf, "HTTP/1.1 200",12) == 0){
        printf("200 OK ! \n\n");
    }else printf("can't connect to %s",SERVER_TO_REQUEST);
    free(buf);
    free(path);
    pclose(fh);

}