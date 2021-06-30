################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/MemMang/%.o: ../FreeRTOS/portable/MemMang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc-7.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C1294NCPDT -Dgcc -DTARGET_IS_TM4C129_RA1 -I"C:/ti/workspace/03 - UART_Driver_freeRTOS+CLI_on_TIVA" -I"C:/ti/workspace/03 - UART_Driver_freeRTOS+CLI_on_TIVA/FreeRTOS-Plus-CLI" -I"C:/ti/TivaWare_C_Series-2.2.0.295" -I"C:/ti/workspace/03 - UART_Driver_freeRTOS+CLI_on_TIVA/config" -I"C:/ti/workspace/03 - UART_Driver_freeRTOS+CLI_on_TIVA/FreeRTOS/include" -I"C:/ti/workspace/03 - UART_Driver_freeRTOS+CLI_on_TIVA/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/ti/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


