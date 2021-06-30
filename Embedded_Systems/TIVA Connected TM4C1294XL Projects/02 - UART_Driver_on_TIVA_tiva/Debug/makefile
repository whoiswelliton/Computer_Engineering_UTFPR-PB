################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.o" \
"./tm4c1294ncpdt_startup_ccs_gcc.o" \
"./FreeRTOS/croutine.o" \
"./FreeRTOS/event_groups.o" \
"./FreeRTOS/list.o" \
"./FreeRTOS/queue.o" \
"./FreeRTOS/stream_buffer.o" \
"./FreeRTOS/tasks.o" \
"./FreeRTOS/timers.o" \
"./FreeRTOS/portable/GCC/ARM_CM4F/port.o" \
"./FreeRTOS/portable/MemMang/heap_4.o" \
-Wl,-T"../tm4c1294ncpdt.lds" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
"C:/ti/TivaWare_C_Series-2.2.0.295/driverlib/gcc/libdriver.a" \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include FreeRTOS/subdir_vars.mk
-include FreeRTOS/portable/GCC/ARM_CM4F/subdir_vars.mk
-include FreeRTOS/portable/MemMang/subdir_vars.mk
-include subdir_rules.mk
-include FreeRTOS/subdir_rules.mk
-include FreeRTOS/portable/GCC/ARM_CM4F/subdir_rules.mk
-include FreeRTOS/portable/MemMang/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
02\ -\ UART_Driver_on_TIVA_tiva.out \

EXE_OUTPUTS__QUOTED += \
"02 - UART_Driver_on_TIVA_tiva.out" \

BIN_OUTPUTS += \
02\ -\ UART_Driver_on_TIVA_tiva.hex \

BIN_OUTPUTS__QUOTED += \
"02 - UART_Driver_on_TIVA_tiva.hex" \


# All Target
all: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "02 - UART_Driver_on_TIVA_tiva.out"

# Tool invocations
02\ -\ UART_Driver_on_TIVA_tiva.out: $(OBJS) $(LDS_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/ti/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc-7.2.1.exe" -DPART_TM4C1294NCPDT -Dgcc -DTARGET_IS_TM4C129_RA1 -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map,"02 - UART_Driver_on_TIVA_tiva.map" -o"02 - UART_Driver_on_TIVA_tiva.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

02\ -\ UART_Driver_on_TIVA_tiva.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/ti/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-objcopy.exe"  $(EXE_OUTPUTS__QUOTED) "02 - UART_Driver_on_TIVA_tiva.hex"
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.o" "tm4c1294ncpdt_startup_ccs_gcc.o" "FreeRTOS\croutine.o" "FreeRTOS\event_groups.o" "FreeRTOS\list.o" "FreeRTOS\queue.o" "FreeRTOS\stream_buffer.o" "FreeRTOS\tasks.o" "FreeRTOS\timers.o" "FreeRTOS\portable\GCC\ARM_CM4F\port.o" "FreeRTOS\portable\MemMang\heap_4.o" 
	-$(RM) "main.d" "tm4c1294ncpdt_startup_ccs_gcc.d" "FreeRTOS\croutine.d" "FreeRTOS\event_groups.d" "FreeRTOS\list.d" "FreeRTOS\queue.d" "FreeRTOS\stream_buffer.d" "FreeRTOS\tasks.d" "FreeRTOS\timers.d" "FreeRTOS\portable\GCC\ARM_CM4F\port.d" "FreeRTOS\portable\MemMang\heap_4.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

