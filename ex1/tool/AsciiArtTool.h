#ifndef HW1_ASCII_ART_H
#define HW1_ASCII_ART_H

#include "RLEList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* asciiArtRead: encodes the contents of the file in RLE.
*
* The function compresses the file's contents into an RLEList.
* Note that the user must free the returned list using RLEListDestroy() once it is no longer needed.
*
* @return
* 	NULL if allocations failed.
* 	A RLEList in case of success.
*/
RLEList asciiArtRead(FILE *in_stream);

/**
* asciiArtPrint: write the contents of the uncompressed RLE in a file.
*
* The function opens a file and writes to it the (uncompressed) contents in the RLEList.
*
*  @param list - RLEList containing the reduced ascii art.
*  @param out_stream - The file to witch the Ascii art is writen.
*
*
* @return
* 	RLE_LIST_NULL_ARGUMENT if a NULL was sent as one of the parameters.
*	RLE_LIST_INDEX_OUT_OF_BOUNDS if an error occurred and the RLEListGet function was indexed incorrectly.
* 	RLE_LIST_SUCCESS if the output was successful.
 */
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

/**
* asciiArtPrintEncoded: write the contents of the compressed RLE in a file.
*
* The function opens a file and writes to it the (compressed) contents in the RLEList.
*
* @return
* 	RLE_LIST_NULL_ARGUMENT if a NULL was sent as one of the parameters
*   RLE_LIST_ERROR if an error occurred in the RLEListExportToString function.
* 	RLE_LIST_SUCCESS if the output was successful.
*/
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);


#endif // HW1_ASCII_ART_H