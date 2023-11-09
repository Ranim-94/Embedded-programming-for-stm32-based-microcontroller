################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main_signal_plotting.c \
../Src/signals.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main_signal_plotting.o \
./Src/signals.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main_signal_plotting.d \
./Src/signals.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"E:/1_Simulations_Programming/Embedded Programming/DSP_target_stm32F411/b_signal_plotting/Chip_Header/CMSIS/Device/ST/STM32F4xx/Include" -I"E:/1_Simulations_Programming/Embedded Programming/DSP_target_stm32F411/b_signal_plotting/Chip_Header/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main_signal_plotting.d ./Src/main_signal_plotting.o ./Src/signals.d ./Src/signals.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o

.PHONY: clean-Src

