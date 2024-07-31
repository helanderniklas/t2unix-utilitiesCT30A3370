//Niklas Helander. Tekoälyä käytetty tehtävässä tukena tehtävänannon jäsentelyssä ja koodin rakenteen optimoinnissa.

//import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Main function. takes command line arguments
int main(int argc, char *argv[]) {
    // Variables for pointer and buffer
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    //If less than 2 arguments are provided, print usage and exit with status 1
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n");
        return 1;
    }

    //loop each provided file
    for (int i = 2; i < argc; i++) {
        //Open the file in read mode
        file = fopen(argv[i], "r");
        //Check if the file opened successfully
        if (file == NULL) {
            //Print error message if file cannot be opened
            printf("my-grep: cannot open file\n");
            //Exit with status 1
            return 1;
        }

        //Read each line from the file
        while ((read = getline(&line, &len, file)) != -1) {
            //Check if the line contains the search term
            if (strstr(line, argv[1]) != NULL) {
                //Print the line if it contains the search term
                printf("%s", line);
            }
        }

        //close the file
        fclose(file);
    }

    //Free the allocated line buffer
    free(line);

    //Exit with status 0 if successful
    return 0;
}
