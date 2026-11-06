#pragma once 
#include <iostream>
#include <cstddef>

template <typename T, typename F> 
void iter(T *array, const size_t arrayLen, F f)
{
	if (!array || !f)
		return;
	for ( size_t i = 0; i < arrayLen; i++)
		f(array[i]);
}
