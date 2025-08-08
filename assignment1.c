// Skyler Kona and Daniel Desforges
// Last modified: 2/3/2023

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    FILE *reader;
    FILE *writer;
    reader = fopen("lyrics.txt", "r");
    writer = fopen("lyricschar.txt", "w");

    int charpos;
    while(1){
        charpos = fgetc(reader);
        if(feof(reader)){
            break;
        }
        fputc(charpos, writer);
    }
    fclose(reader);
    fclose(writer);

    FILE *reader2;
    FILE *writer2;

    reader2 = fopen("lyricschar.txt", "r");
    writer2 = fopen("lyricsline.txt", "w");

    char curline[100];
    while(fscanf(reader2, "%[^\n] ", curline) == 1){
        fprintf(writer2, curline);
        fprintf(writer2, "\n");
    }
    fclose(reader2);
    fclose(writer2);

    return(0);
}