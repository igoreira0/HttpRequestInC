int main(int argc, char** argv) {

    FILE* fh;
    size_t len;
    int i;
    char path[64];
    for(i='a';i<='z';i++)
    {
        printf("Testing with \"%c\" letter\n",i);
        snprintf(path,( sizeof(CMD_VERIFY_USB) + sizeof(PATH_TO_SAVE) +sizeof(char) ),"%s%c%s",CMD_VERIFY_USB,i,PATH_TO_SAVE);
        system(path);
        fh = fopen("/tmp/usb.txt","rb");

        fseek(fh,0,SEEK_END);
        len = ftell(fh);
        rewind(fh);
        printf("%zu\n",len);
        if(len > 0)
        {
            printf("removable dispositive founded in sd%c\n",i);
        }
    }
    fclose(fh);
    return EXIT_SUCCESS;  
    }
