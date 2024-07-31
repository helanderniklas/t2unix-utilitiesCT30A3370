//Niklas Helander. Tekoälyä käytetty tehtävässä tukena tehtävänannon jäsentelyssä ja koodin rakenteen optimoinnissa.

//necessary libraries
#include <stdio.h>
#include <stdlib.h>

//Main function. Takes command line arguments
int main(int argc, char *argv[]) {
    //Variable to hold pointer
    FILE *file;
    //Buffer to hold each line
    char buffer[1024];

    //If no files are provided, exit status 0
    if (argc < 2) {
        return 0;
    }

    //Loop through each file
    for (int i = 1; i < argc; i++) {
        //Open the file in read mode
        file = fopen(argv[i], "r");
        //Check if the file opened successfully
        if (file == NULL) {
            //Print error message if file cannot be opened
            printf("my-cat: cannot open file\n");
            // Exit with status 1
            return 1;
        }

        //read and print each line from the file
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }

        //Close file
        fclose(file);
    }

    //Exit with status 0 if good
    return 0;
}
