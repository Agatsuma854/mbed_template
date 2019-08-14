// mbed main.cpp template

#include "mbed.h"

//-----------------------------------
// Enable feature
#define ENABLE_SERIAL
#define ENABLE_CAN
#define ENABLE_DEBUG_LED

//-----------------------------------
// macro

#ifdef ENABLE_SERIAL
// Serial setting
#define SERIAL_NAME serial
#define SERIAL_BAUDRATE 38400
#define SERIALTX p9
#define SERIALRX p10
#define SERIAL_HEAD 0xAA // Check carefully
#define SERIAL_TAIL 0xBB // Check carefully
#endif

#ifdef ENABLE_CAN
// CAN setting
#define CAN_NAME can
#define CANRD p30
#define CANTD p29
#define CAN_FRQUENCY 8000 // Limit 12Kbps

#define CANMESSAGE_NAME msg
#define CANMESSAGE_ID 0x11 // Check carefully
#endif

// Debug setting
#ifdef ENABLE_DEBUG_LED
#define NUMBER_OF_LED 3
#define DEBUG_LED_NAME debugled
#define LEDR p5
#define LEDG p6
#define LEDB p7
enum{
    RED,
    GREEN,
    BLUE,
};
#endif

//-----------------------------------
// declaration

#ifdef ENABLE_SERIAL
Serial SERIAL_NAME(SERIALTX, SERIALRX, SERIAL_BAUDRATE);
#endif

#ifdef ENABLE_CAN
CAN CAN_NAME(CANRD, CANTD, CAN_FRQUENCY);
CANMessage CANMESSAGE_NAME;
#endif

#ifdef ENABLE_DEBUG_LED
DigitalOut DEBUG_LED_NAME[NUMBER_OF_LED]{
    DigitalOut(LEDR),
    DigitalOut(LEDG),
    DigitalOut(LEDB),
};
#endif

//-----------------------------------
// callback function

#ifdef ENABLE_SERIAL
void serialCallback(){
    ;
}
#endif

#ifdef ENABLE_CAN
void canCallback(){
    ;
}
#endif

//-----------------------------------
// user function

//-----------------------------------
// main function

int main(){
    // Initialize
    #ifdef ENABLE_DEBUG_LED
    for(int i=0;i < NUMBER_OF_LED;++i){
        DEBUG_LED_NAME[i].write(0);
    }
    #endif

    // main loop
    while (1)
    {
        ;
    }
}