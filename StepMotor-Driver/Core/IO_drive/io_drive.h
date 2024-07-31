#ifndef __IO_DRIVE_H
#define __IO_DRIVE_H
#ifdef __cplusplus
 extern "C" {
#endif 
#include "main.h"


#define Limit_Inputs 4
#define Fault_Inputs 3
#define Reset_Outputs 3
#define Enable_Outputs 1

void IO_Update(void);
void Enable_Output(uint8_t ctrl);
void Reset_Output(uint8_t ctrl);

#ifdef __cplusplus
}
#endif

#endif
