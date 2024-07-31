//Niklas Helander. Tekoälyä käytetty tehtävässä tukena tehtävänannon jäsentelyssä ja koodin rakenteen optimoinnissa.

//import libraries
#include <stdio.h>
#include <stdlib.h>

//Main function. Takes command line arguments
int main(int argc, char *argv[]) {
    //Variables for file pointer, count, and character
    FILE *file;
    int count;
    char character;

    //If no files are provided, print usage and exit with status 1
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        return 1;
    }

    //Loop through each provided file
    for (int i = 1; i < argc; i++) {
        //Open the file in read mode
        file = fopen(argv[i], "r");
        //Check if the file opened successfully
        if (file == NULL) {
            //Print error message if file cannot be opened
            printf("my-unzip: cannot open file\n");
            //Exit with status 1
            return 1;
        }

        //Read and decompress each count-character pair
        while (fread(&count, sizeof(int), 1, file) && fread(&character, sizeof(char), 1, file)) {
            for (int j = 0; j < count; j++) {
                printf("%c", character);
            }
        }

        //Close the file
        fclose(file);
    }

    //Exit with status 0 if successful
    return 0;
}
