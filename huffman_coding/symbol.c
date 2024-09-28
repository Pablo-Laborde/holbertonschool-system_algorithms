#include "huffman.h"


/**
 * symbol_create- func
 * @data: char
 * @freq: size_t
 * Return: symbol_t
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *sym = NULL;

	sym = malloc(sizeof(symbol_t));
	if (!sym)
		return (NULL);
	sym->data = data;
	sym->freq = freq;
	return (sym);
}
