#ifndef BRUGLESCO_MEMORY_EXPRESSIONS_H
#define BRUGLESCO_MEMORY_EXPRESSIONS_H

#include <fstream>
#include <random>

static std::random_device rd;
static std::mt19937 generator(rd());
static std::uniform_int_distribution<int> distribution(1, 6);
static std::ofstream debuggStream("DebugLog.txt");



#endif // !BRUGLESCO_MEMORY_EXPRESSIONS_H
