#include "Demo.h"

#define SUCCESS 1
#define FAILURE 0
#define FILE_NAME "demo.txt"
#define MAX_READ_SZ 50

int
writeToFile (char *fileName, char *message)
{
    FILE *fp = NULL;
    int retCode = SUCCESS;
    
    if ((fileName != NULL) &&
        (message != NULL))
    {
        fp = fopen (fileName, "w");
        if (fp != NULL)
        {
            fprintf (fp, "%s", message);
            fclose (fp);
        }
        else
        {
            printf ("Unable to open file %s", fileName);
            retCode = FAILURE;
        }
    }
    else
    {
        printf ("Invalid data");
        retCode = FAILURE;
    }
    
    return (retCode);
}

int
readFromFile (char *fileName)
{
    FILE *fp = NULL;
    int retCode = SUCCESS;
    char buf[MAX_READ_SZ + 1] = {0x00};
    
    if (fileName != NULL)
    {
        fp = fopen (fileName, "r");
        if (fp != NULL)
        {
            while (fgets (buf, MAX_READ_SZ, fp) != NULL)
            {
                printf ("%s", buf);
                memset (buf, 0x00, sizeof(buf));
            }
            fclose (fp);
        }
        else
        {
            printf ("Unable to open file %s", fileName);
            retCode = FAILURE;
        }
    }
    else
    {
        printf ("Invalid data");
        retCode = FAILURE;
    }
    
    return (retCode);
}

int FileOperations()
{
    writeToFile (FILE_NAME, "Hello\n world!!");
    readFromFile (FILE_NAME);
    
    return 0;
}
