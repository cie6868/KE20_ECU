#include "Interrupts.h"

IInterrupt& Interrupts::GetTimer3()
{
    return Interrupts::Timer3Interrupt;
}