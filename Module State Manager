#include <stdio.h>
#include <stdbool.h>

typedef enum
{
    OFF,
    ENABLING,
    ON,
    DISABLING
    
} e_moduleState;

typedef struct
{
    e_moduleState state;
    bool enableRequest;
    bool initialized;
    
} s_moduleState;


//To enable the module state manager
void moduleEnable(s_moduleState *S)
{
    S -> enableRequest = true;
}

//To disable the module state manager
void moduleDisable (s_moduleState *S)
{
    S -> enableRequest = false;
}

void moduleStateManager(s_moduleState *S)
{
    switch (S -> state)
    {
        case OFF:
            if (S -> enableRequest == true)
            {
                S -> state = ENABLING;
            }
            break;
        
        case ENABLING:
            if (S -> initialized == false)
            {
                S -> initialized = true;
            }
            S -> state = ON;
            break;
        
        case ON:
            if (S -> enableRequest == false)
            {
                S -> state = DISABLING;
            }
            break;
        
        case DISABLING:
             S -> initialized = false;
             S -> state = OFF;
             break;
             
        default:
            break;
    }
}


//To print the state of the state machine
const char *getStateName(e_moduleState state)  //used "const" as it is only returning a string literal and not changing it.
{
    switch (state)
    {
        case OFF:       return "OFF";
        case ENABLING:  return "ENABLING";
        case ON:        return "ON";
        case DISABLING: return "DISABLING";
        default:        return "UNKNOWN";
    }
}

int main(void)
{
    s_moduleState module = {OFF, false, false};

    moduleEnable(&module);

    printf("Enable request: %s\n", module.enableRequest ? "true" : "false");
    
    //To call the state manager function
    moduleStateManager (&module);
    printf("Current State: %s\n", getStateName(module.state));
    
    //To change the state, again calling the state manager function
    moduleStateManager (&module);
    printf("Current State: %s\n", getStateName(module.state));
    
    return 0;
}
