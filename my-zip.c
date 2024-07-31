//Niklas Helander. Tekoälyä käytetty tehtävässä tukena tehtävänannon jäsentelyssä ja koodin rakenteen optimoinnissa. +debuggaaminen

//import libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Main function. Takes command line arguments
int main(int argc, char *argv[]) {
    //Variables for pointer and characters
    FILE *file;
    int count;
    char current, previous;

    //If no files are provided, print usage and exit with status 1
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    //Loop each provided file
    for (int i = 1; i < argc; i++) {
        //Open the file in read mode
        file = fopen(argv[i], "r");
        //Check if the file opened successfully
        if (file == NULL) {
            //Print error message if file cannot be opened
            printf("my-zip: cannot open file\n");
            //Exit with status 1
            return 1;
        }

        //Initialize variables for encoding
        count = 1; // Initialize count to 1 since the first character is already read
        previous = fgetc(file);

        //Read each character from the file
        while ((current = fgetc(file)) != EOF) {
            //Check if the current character is the same as the previous one
            if (current == previous) {
                count++;
            } else {
                //Write the count and the character
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&previous, sizeof(char), 1, stdout);
                //Reset count and update previous character
                count = 1;
                previous = current;
            }
        }

        //Write the last run
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&previous, sizeof(char), 1, stdout);

        //Close the file
        fclose(file);
    }

    //Exit with status 0 if successful
    return 0;
}
