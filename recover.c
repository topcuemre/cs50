#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t BYTE;

#define BLOCK_SIZE 512
#define FILE_SIZE 8
 
bool new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    //checking the argumnet condition 
    if ( argc != 2)
    {
        printf("Call with only one argument please...");
        return 1;
    }
    // accessing to memory card via fopen
    FILE *f = fopen(argv[1],"r");
    //buffer array initialization of equal size to the size of input file
    if (f == NULL)
    {
        printf("file not found...");
    }
    BYTE buffer[BLOCK_SIZE];
    //reading from file
    fread(buffer, 512, 1, f);
    
    bool first_jpeg = false;
    int index = 0;
    FILE *fo;
    while (fread(buffer, BLOCK_SIZE, 1, f))
    {
        if(new_jpeg(buffer))
        {
            if ( !first_jpeg)
                first_jpeg = true;
            else
                fclose(fo);
            char file[FILE_SIZE];
            sprintf(file, "%03i.jpg", index++);
            fo = fopen(file, "w");
            if (fo == NULL)
                return 1;
            fwrite(buffer, BLOCK_SIZE, 1, fo);
        }
        else if (first_jpeg)
        {
            //writing on file again
            fwrite(buffer,BLOCK_SIZE, 1 ,fo);
        }
    }
    fclose(fo);
    fclose(f);
    //checking memory bytes
}
