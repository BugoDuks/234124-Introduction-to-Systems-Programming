#define FLAG 1
#define INPUT 2
#define OUTPUT 3
#define ARG_AMOUNT 4

#include "RLEList.h"
#include "AsciiArtTool.h"
#include <stdio.h>
#include <string.h>

char swapSpaceToAt(char letter);

int main(int argc, char **argv)
{
	if (argc != ARG_AMOUNT)
	{
		return 0;
	}

	char *flag = argv[FLAG];
	FILE *input = fopen(argv[INPUT], "r");
	if (input == NULL)
	{
		return 0;
	}
	FILE *output = fopen(argv[OUTPUT], "w");
	if (output == NULL)
	{
		fclose(input);
		return 0;
	}

	RLEListResult status;
	RLEList asciiList = asciiArtRead(input);

	if (!strcmp(flag,"-e"))
	{
		status = asciiArtPrintEncoded(asciiList, output);
	}
	else if (!strcmp(flag,"-i"))
	{
		status = RLEListMap(asciiList, swapSpaceToAt );
		if (status != RLE_LIST_SUCCESS)
		{
			fclose(input);
			fclose(output);
			RLEListDestroy(asciiList);
			return 0;
		}
		
		status = asciiArtPrint(asciiList, output);
	}

	fclose(input);
	fclose(output);
	RLEListDestroy(asciiList);
	return 0;
}

char swapSpaceToAt(char letter)
{
	if (letter == ' ')
	{
		return '@';
	}
	if (letter == '@')
	{
		return ' ';
	}
	return letter;
}
