#include <12F675.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES INTRC_IO              	//Internal RC Osc, no CLKOUT
#FUSES NOCPD                 	//No EE protection
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES NOMCLR                	//Master Clear pin used for I/O
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES BANDGAP_HIGH          
#use delay(clock=4000000) 

#define IGN PIN_A2         //interrupt
#define RADIOPOWER PIN_A0
#define ONOFF PIN_A1


#int_EXT
void  EXT_isr(void) 
{
   
}



#int_RA
void  RA_isr(void) 
{
//output_high(PIN_A5);
   disable_interrupts(GLOBAL);
   delay_ms(20);
   
   if(!input(ONOFF))
     { 
       if(read_eeprom(0))            //activate deactivate
         {write_eeprom(0,0);}
       else
         {write_eeprom(0,1);}   
     }
     
   delay_ms(100);
   
   if(read_eeprom(0))               //auto turn-on turn-off active
   {
      if(input(IGN) != input(RADIOPOWER) )     //ignition on, radio off         turn on radio
         {
            output_low(ONOFF);
            delay_ms(2200);
            output_float(ONOFF);  
         }
      /*
      else if(!input(IGN) && input(RADIOPOWER) )     // ignition off, radio on      turn off radio
         {
            output_low(ONOFF);
            delay_ms(2500);
            output_float(ONOFF);  
         }
      */
   }
   
//   output_low(PIN_A5);
   input(IGN);
   enable_interrupts(GLOBAL);
}




void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_comparator(NC_NC);
   setup_vref(FALSE);
//   enable_interrupts(INT_EXT);
//   enable_interrupts(INT_RA);
   enable_interrupts(INT_RA2);

   output_float(ONOFF);
   input(IGN);
   input(RADIOPOWER);
   
   enable_interrupts(GLOBAL);
   
   while(true)
   {sleep();}
}
