#include "PrintAnyFormat.h"

// Explicit template instantiation for common types
template void Print(String message);
template void Print(double message);
template void Print(int message);
template void Print(int32_t message);
template void Print(float message);
template void Print(size_t message);
template void Print(uint16_t message);
template void Print(uint32_t message);


template void Println(String message);
template void Println(double message);
template void Println(int message);
template void Println(int32_t message);
template void Println(float message);
template void Println(size_t message);
template void Println(uint16_t message);
template void Println(uint32_t message);
