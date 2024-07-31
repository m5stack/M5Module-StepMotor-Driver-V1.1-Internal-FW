#include "io_drive.h"
#include "i2c_ex.h"

__IO uint8_t Limit_State;
__IO uint8_t Fault_State;
__IO uint8_t Enable_State;
__IO uint8_t Reset_State;

typedef struct {
  GPIO_TypeDef* GPIOx;
  uint16_t GPIO_Pin;
} IO_GPIO;

IO_GPIO Read_Limit[Limit_Inputs]={
	{Input_GPIO_PortA,ExInput_1_Pin},	
	{Input_GPIO_PortA,ExInput_2_Pin},
	{Input_GPIO_PortA,ExInput_3_Pin},
	{Input_GPIO_PortA,ExInput_4_Pin},
};

IO_GPIO Read_Fault[Fault_Inputs]={
	{Input_GPIO_PortF,FaultInput_X_Pin},
	{Input_GPIO_PortA,FaultInput_Y_Pin},
	{Input_GPIO_PortA,FaultInput_Z_Pin},
};

IO_GPIO Write_Reset[Reset_Outputs]={
	{Output_GPIO_PortF,ResetOutput_X_Pin},
	{Output_GPIO_PortB,ResetOutput_Y_Pin},
	{Output_GPIO_PortA,ResetOutput_Z_Pin},
};

IO_GPIO Write_Enable[Enable_Outputs]={
	{Output_GPIO_PortA,DriveOutput_En_Pin},
};

	

void IO_Update(void)
{
	uint8_t i = 0;
	Limit_State = 0;
	Fault_State = 0;
	for (i = 0; i < Limit_Inputs;i++)
		Limit_State |= (HAL_GPIO_ReadPin(Read_Limit[i].GPIOx,Read_Limit[i].GPIO_Pin) & 0x01) << i;
	for (i = 0; i < Fault_Inputs;i++)
		Fault_State |= (HAL_GPIO_ReadPin(Read_Fault[i].GPIOx,Read_Fault[i].GPIO_Pin) & 0x01) << i;
}

void Enable_Output(uint8_t ctrl)
{
	Enable_State = ctrl & 0x10;
	ctrl >>= 4;
	if(ctrl & 0x01)
	{
		HAL_GPIO_WritePin(Write_Enable[0].GPIOx,Write_Enable[0].GPIO_Pin,GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(Write_Enable[0].GPIOx,Write_Enable[0].GPIO_Pin,GPIO_PIN_RESET);
	}
}

void Reset_Output(uint8_t ctrl)
{
	uint8_t i = 0;
	Reset_State = ctrl & 0x07;
	for (i = 0; i < Reset_Outputs;i++)
	{
		if(ctrl & 0x01)
		{
			HAL_GPIO_WritePin(Write_Reset[i].GPIOx,Write_Reset[i].GPIO_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(Write_Reset[i].GPIOx,Write_Reset[i].GPIO_Pin,GPIO_PIN_RESET);
		}
		ctrl >>= 1;
	}
}
