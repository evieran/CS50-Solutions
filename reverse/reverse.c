#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3) {
        fprintf(stderr, "Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // TODO #2: Open input file for reading
    FILE *input == fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    // TODO #3: Read header
    WAVEHEADER header;
    if (fread(&header, sizeof(WAVEHEADER), 1, input) != 1) {
        fprintf(stderr, "Could not read header from %s. \n", argv[1]);
        fclose(input);
        return 1;
    }

    // TODO #4: Check if the file is in WAV format
    if (!check_format(header)) {
        fprintf(stderr, "Invalid WAV file.\n");
        fclose(input);
        return 1;
    }

    // TODO #5: Open output file for writing
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "Could not open file %s for writing.\n", argv[2]);
        fclose(input);
        return 1;
    }

    // TODO #6: Write header to output file
    if (fwrite(&header, sizeof(WAVHEADER), 1, output) != 1) {
        fprintf(stderr, "Could not write header to %s. \n", argv[2]);
        fclose(input);
        fclose(output);
        return 1;
    }

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (memcmp(header.format, "WAVE", 4) == 0) {
        return 1; //true
    }
    return 0; // false
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}