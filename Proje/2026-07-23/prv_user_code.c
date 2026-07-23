//B

#include "led.h"
#include "button.h"


const uint32_t CHASE_SLOW_MS = 1650;
const uint32_t CHASE_FAST_MS = 250;

void PRV_USER_Code(void) {
    //Modüller
    Led_Init();
    Button_Init();

    Led_SelfTest();

    bool reverse = false; //ileri - geri?
    uint32_t current_delay = CHASE_SLOW_MS;


    while (1) {
        // kısa mı uzun mu kontrolü
        ButtonEvent_e event = Button_Check();

        if (event == SHORT_PRESS) {
            reverse = !reverse; // kısa ise yön değiş
        }
        else if (event == LONG_PRESS) {
                    // uzun ise hız de-ğiş
                    if (current_delay == CHASE_SLOW_MS) {
                        current_delay = CHASE_FAST_MS;
                    } else {
                        current_delay = CHASE_SLOW_MS;
                    }
                }
                Led_ChaseStep(reverse);

                // delay
                for(volatile uint32_t i = 0; i < current_delay; i++);
            }
        }
