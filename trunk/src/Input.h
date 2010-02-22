#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <Allegro.h>

#define KEY0 0
#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4
#define KEY5 5
#define KEY6 6
#define KEY7 7
#define KEY8 8
#define KEY9 9
#define KEYD 10
#define KEYESC 11
#define KEYTAB 12
#define KEYP 13
#define NKEYS 14

extern bool keys[NKEYS];
extern bool mouse[2];
extern bool mouseLockOn;

void inputInit(void);
void updateInput(void);

void setMouseLock(bool hasLock);
void setKeyLock(int k, bool hasLock);
void toggleMouseLock(void);

class Key
{
public:
    Key(){}
    Key(volatile char *end);
    bool isPressed(void);
    bool isLocked, hasLock;
    volatile char *end;
};

class Mouse
{
public:
    Mouse(){}
    Mouse(volatile int b);
    bool isPressed(void);
    bool isLocked, hasLock;
    volatile int *end, b;
};

#endif // INPUT_H_INCLUDED
