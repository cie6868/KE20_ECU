#include "Interrupt.h"

class Interrupts
{
    public:
        static IInterrupt& GetTimer3();

    private:
        static Interrupt Timer3Interrupt;
};