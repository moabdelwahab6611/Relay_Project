/* 
 * File     : application.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on May 21, 2023, 5:38 PM
 */

/**************************Includes-Section*****************************/
#include "application.h"
/***********************************************************************/

/***********************************************************************/
relay_t relay_1 =
{
    .relay_port = PORTC_INDEX,
    .relay_pin = GPIO_PIN0,
    .relay_status = RELAY_STATUS_OFF
};

relay_t relay_2 =
{
    .relay_port = PORTC_INDEX,
    .relay_pin = GPIO_PIN1,
    .relay_status = RELAY_STATUS_OFF
};
/***********************************************************************/

/***********************Main Function-Section***************************/
int main() 
{ 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    
    while(1)
    {
        ret = relay_turn_on(&relay_1);
        ret = relay_turn_off(&relay_2);
        __delay_ms(5000);
        ret = relay_turn_off(&relay_1);
        ret = relay_turn_on(&relay_2);
        __delay_ms(5000);
        
        
    }
    return (EXIT_SUCCESS);
}
/***********************************************************************/

/*************************Functions-Section*****************************/
void application_intialize(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = relay_initialize(&relay_1);
    ret = relay_initialize(&relay_2);
}
/***********************************************************************/