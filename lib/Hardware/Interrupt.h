#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <functional>

class IInterrupt
{
    protected:  
        typedef std::function<void(void)> Callback_t;

    public:
        virtual void SetCallback(Callback_t callback) = 0;
        virtual void Call();
};

class Interrupt : public IInterrupt
{
    public:
        virtual void SetCallback(Callback_t callback);
        virtual void Call();

    private:
        Callback_t callback;
};

#endif