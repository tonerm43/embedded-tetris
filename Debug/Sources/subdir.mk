################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/game-engine.c \
../Sources/game-timer.c \
../Sources/main.c \
../Sources/rng.c \
../Sources/tetris-well.c 

OBJS += \
./Sources/game-engine.o \
./Sources/game-timer.o \
./Sources/main.o \
./Sources/rng.o \
./Sources/tetris-well.o 

C_DEPS += \
./Sources/game-engine.d \
./Sources/game-timer.d \
./Sources/main.d \
./Sources/rng.d \
./Sources/tetris-well.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK64FN1M0VMD12" -I"../Sources" -I"C:\Users\bricha11\tetris\include" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK64F12/include" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


