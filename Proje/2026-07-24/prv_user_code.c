#include <stdint.h>
#include <stdbool.h>
#include "hal_pcu.h"
#include "led.h"
#include "button.h"

typedef enum {
    MODE_CHASE_SLOW,
    MODE_CHASE_FAST,
    MODE_PAUSE
} AppMode_t;

static AppMode_t app_mode = MODE_CHASE_SLOW;


const uint32_t SLOW_CHASE = 1650;
const uint32_t FAST_CHASE = 250;

void PRV_USER_Code(void) {
    Led_Init();
    Button_Init();

    Led_SelfTest();

    bool reverse = false; // ileri - geri?
    uint32_t current_delay = SLOW_CHASE;

    while (1) {
        // Kısa mı uzun mu kontrolü
        ButtonEvent_e event = Button_Check();

        if (event == SHORT_PRESS) {
            reverse = !reverse; // kısa ise yön değiş


            // Kısa basış döngüsü -> SLOW - FAST - PAUSE - SLOW
                    if (app_mode == MODE_CHASE_SLOW) {
                        app_mode = MODE_CHASE_FAST;
                        current_delay = FAST_CHASE;
                    }
                    else if (app_mode == MODE_CHASE_FAST) {
                        app_mode = MODE_PAUSE;
                    }
                    else {
                        app_mode = MODE_CHASE_SLOW;
                        current_delay = SLOW_CHASE;
                    }
				}
        		// Uzun basış drudur veya başlat
                else if (event == LONG_PRESS) {
                    if (app_mode != MODE_PAUSE) {
                        app_mode = MODE_PAUSE;
                    } else {
                        app_mode = MODE_CHASE_SLOW;
                        current_delay = SLOW_CHASE;
                    }
                }

        //enum
        switch(app_mode){
        	case MODE_CHASE_SLOW:
        	case MODE_CHASE_FAST:
        		Led_ChaseStep(reverse);
        for(volatile uint32_t i = 0; i < current_delay; i++);
        break;
        	case MODE_PAUSE:
Led_AllOff();
// bekleme
for(volatile uint32_t i = 0; i < 5000; i++);
	break;

        	default:
        		app_mode = MODE_CHASE_SLOW;
        		break;
}
}
}
