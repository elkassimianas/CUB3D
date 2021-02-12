#include <stdio.h>
#include <stdlib.h>
int main() {

    // Make an array containing the B and M characters that
    // identify the file as a BMP.
    char tag[] = { 'B', 'M' };
	  // Create an integer array for the header   
    int header[] = {
        0x3a, // File Size
        0x00, // Unused
        0x36  // Byte offset of pixel data
    };
    
	FILE *fp = fopen("test.bmp", "w+"); // Open a file for writing
    fwrite(&tag, sizeof(tag), 1, fp);   // Write the tag to the file
        fwrite(&header, sizeof(header), 1, fp); // Write the header to disk
	fclose(fp);                         // Close the file
}
