/* Author: Yuan Bo
 * Date: 2021/3/15
 * Description:
 * This assignment is going to get you used to working with the
 * Unix/Linux compiler through some exercises and create some ASCII art through file I/O.
 *
 * Usage:
 * This function have the syntax: <exe> <input file> <-a|-i> <outputfile>
 * exe is whatever the name compile
 * ex: gcc -g -Wall bo_yuan_assn3.c -o hexArt
 * the example above give the exe name hexArt
 *
 * Also this function takes two file name and have a '-a' or '-i' in between.
 * when it is -a, function will take a file have only hex number in it and output it to a binary art to output file location
 * when it is -i, function will take a file have only binary art and reverse the art. ( - to #, # to -)
 * */

#include <stdio.h>
#include <string.h>

char* toArt(char num);

char reverse(char art);

int main(int argc, char** argv) {
    //then the length of the command is correct (equal to 4) enter the function.
    if (argc == 4) {

        FILE* readFile;
        FILE* writeFile;
        char* art;
        char artChar;
        char line[256]; //line of the hax number have max char 255 so I make it 256.
        char artLine[1021]; //link of hte binary art have max char 1020 so I make it 1021.

        //part 1， when 3rd command is equal to -a, enter part 1.
        if (strcmp(argv[2], "-a") == 0) {
            readFile = fopen(argv[1], "r");
            writeFile = fopen(argv[3], "w");

            while (fscanf(readFile, "%s", line) != EOF) //keep it in while loop until fscanf equal to EOF (scanned nothing).
            {
                int i = 0;
                while (line[i + 1] != '\0') //while line[i + 1] is not empty, keep change it to binary art and print in file. Left the last char in line.
                {
                    art = toArt(line[i]);
                    fprintf(writeFile, "%s", art);
                    i++;
                }
                art = toArt(line[i]);

                fprintf(writeFile, "%s\n", art); //use last char in line and call "%s\n" to make a new line.
            }

            //close the file
            fclose(readFile);
            fclose(writeFile);
        }
        //part 2 ，when 3rd command is equal to -i, enter part 1
        else if (strcmp(argv[2], "-i") == 0) {
            readFile = fopen(argv[1], "r");
            writeFile = fopen(argv[3], "w");

            while (fscanf(readFile, "%s", artLine) != EOF)
                //keep it in while loop until fscanf equal to EOF (scanned nothing)
            {
                int i = 0;
                while (artLine[i + 1] != '\0') //while line[i + 1] is not empty, keep do reverse on it. Left the last char in line.
                {
                    artChar = reverse(artLine[i]);
                    fprintf(writeFile, "%c", artChar);
                    i++;
                }
                artChar = reverse(artLine[i]);
                fprintf(writeFile, "%c\n", artChar); //use last char in line and call "%s\n" to make a new line.
            }

            //close the file
            fclose(readFile);
            fclose(writeFile);
        }
        else {
            //then user entered the command have the correct length but the <-a|-i> is not correct. out put the follow tex.
            printf("Command invalid, please use -a or -i to make a binary art or inverse art\n");
        }
    }
    else {
        //when user entered a wrong length command, out put the follow tex.
        printf("Command invalid， please follow the syntax\n");
        printf("|||| <exe> <input file> <-a|-i> <outputfile> ||||\n");
    }
}

//toArt function takes one char which is a hax number and make it to become a binary art.
char* toArt(char num) {
    switch (num) {
        case '0':
            return "----";
        case '1':
            return "---#";
        case '2':
            return "--#-";
        case '3':
            return "--##";
        case '4':
            return "-#--";
        case '5':
            return "-#-#";
        case '6':
            return "-##-";
        case '7':
            return "-###";
        case '8':
            return "#---";
        case '9':
            return "#--#";
            //letter will have upper case and lower case both been checked.
        case 'a':
        case 'A':
            return "#-#-";
        case 'b':
        case 'B':
            return "#-##";
        case 'c':
        case 'C':
            return "##--";
        case 'd':
        case 'D':
            return "##-#";
        case 'e':
        case 'E':
            return "###-";
        case 'f':
        case 'F':
            return "####";
            //return eeee if none of the hax number is correct.
        default:
            return "eeee";
    }
}

//reverse function takes a char from art and reverse it to other one ( # to -, - to #)
char reverse(char art) {
    if (art == '#') {
        return '-';
    } else if (art == '-') {
        return '#';
    }
        //if the char is not # or -, return char E.
    else {
        return 'E';
    }
}