#include "Interrupt.h"

void Interrupt::SetCallback(std::function<void(void)> callback)
{
    this->callback = callback;
}

void Interrupt::Call()
{
    if (this->callback)
    {
        this->callback();
    }
}