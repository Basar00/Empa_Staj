//B

#include "led.h"
#include "button.h"


const uint32_t Yavas_Chase = 1650;
const uint32_t Hizli_Chase = 250;

void PRV_USER_Code(void) {
    //Modüller
    Led_Init();
    Button_Init();

    Led_SelfTest();

    bool reverse = false; //ileri - geri?
    uint32_t current_delay = Yavas_Chase;


    while (1) {
        // kısa mı uzun mu kontrolü
        ButtonEvent_e event = Button_Check();

        if (event == SHORT_PRESS) {
            reverse = !reverse; // kısa ise yön değiş
        }
        else if (event == LONG_PRESS) {
                    // uzun ise hız de-ğiş
                    if (current_delay == Yavas_Chase) {
                        current_delay = Hizli_Chase;
                    } else {
                        current_delay = Yavas_Chase;
                    }
                }
                Led_ChaseStep(reverse);

                // delay
                for(volatile uint32_t i = 0; i < current_delay; i++);
            }
        }
