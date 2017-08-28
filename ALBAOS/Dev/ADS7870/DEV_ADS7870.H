#ifndef __DEV_ADS7870_H
#define __DEV_ADS7870_H


#ifdef ADS7870_DEBUG
#define _ADS7870_NODEBUG
#else
#define _ADS7870_NODEBUG nodebug
#endif

#define ADC_SCLKBRATE 115200ul
#ifndef ADC_ONBOARD
   #error "This core module does not have ADC support.  ADC programs will not "
   #fatal "   compile on boards without ADC support.  Exiting compilation."
#endif

#endif