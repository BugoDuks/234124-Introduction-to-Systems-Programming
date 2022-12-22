#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <stdexcept>
#include <string>


class DeckFileNotFound : public std::logic_error
{
public:
    /*
	* C'tor of DeckFileNotFound class
	*
	* @return
	*      A new instance of DeckFileNotFound.
	*/
	DeckFileNotFound() : logic_error("Deck File Error: File not found") {}
};

class DeckFileFormatError : public std::logic_error
{
public:
	/*
	* C'tor of DeckFileFormatError class
	*
	* @return
	*      A new instance of DeckFileFormatError.
	*/
	DeckFileFormatError(int line) : logic_error("Deck File Error: File format error in line " + std::to_string(line)) {}
};

class DeckFileInvalidSize : public std::logic_error
{
public:
	/*
	* C'tor of DeckFileInvalidSize class
	*
	* @return
	*      A new instance of DeckFileInvalidSize.
	*/
	DeckFileInvalidSize() : logic_error("Deck File Error: Deck size is invalid") {}
};



#endif /* EX4_EXCEPTION_H */