#include "STD_MACRO.h"
#include "STD_TYPE.h"




void ADC_vinit(void)
{
    /* Configure VREF to the internal voltage (2.56 V) */
    SET_BIT(ADMUX, REFS0);
    SET_BIT(ADMUX, REFS1);
    /*************************************/
    SET_BIT(ADCSRA, ADEN); // Enable ADC
    
    /* Adjust ADC clock by selecting the division factor -----> 64 */
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    /***********************************/
}

uint16 ADC_Read(void)
{
    uint16 read_val; // Variable to store the converted value
    SET_BIT(ADCSRA, ADSC); // Start the ADC conversion
    while (IS_BIT_CLR(ADCSRA, ADIF)); // Wait until ADIF becomes 1 when conversion is complete
    SET_BIT(ADCSRA, ADIF); // Clear ADIF
    read_val = (ADCL); // Read the ADCL register
    read_val |= (ADCH << 8); // Read the full register (combine ADCH and ADCL)
    return read_val; // Return the converted value
}
