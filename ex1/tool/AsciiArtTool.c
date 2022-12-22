#include "AsciiArtTool.h"

#define BUFFER_SIZE 2

//Must DESTROY list after use
RLEList asciiArtRead(FILE *in_stream)
{
	if (!in_stream)
	{
		return NULL;
	}

	RLEList list = RLEListCreate();
	if (!list)
	{
		return NULL;
	}

	char buffer[BUFFER_SIZE];
	while (fgets(buffer, BUFFER_SIZE, in_stream) != NULL)
	{
		RLEListAppend(list, buffer[0]);
	}

	return list;
}


RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
	if (!out_stream || !list)
	{
		return RLE_LIST_NULL_ARGUMENT;
	}

	RLEListResult status;
	char buffer[BUFFER_SIZE] = {0}; 
	for (int i = 0; i < RLEListSize(list); i++)
	{
		buffer[0] = RLEListGet(list, i, &status);
		if (status != RLE_LIST_SUCCESS)
		{
			return status;
		}
		fputs(buffer, out_stream);
	}

	return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
	if (!out_stream || !list)
	{
		return RLE_LIST_NULL_ARGUMENT;
	}

	RLEListResult status;
    char *reducedStr = RLEListExportToString(list, &status);
    if (status != RLE_LIST_SUCCESS)
    {
        free(reducedStr);
        return status;
    }
	fputs(reducedStr, out_stream);
    free(reducedStr);
	return RLE_LIST_SUCCESS;
}
