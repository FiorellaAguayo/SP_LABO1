################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Contoller.c \
../src/Jugador.c \
../src/LinkedList.c \
../src/inputs.c \
../src/main.c \
../src/parser.c 

C_DEPS += \
./src/Contoller.d \
./src/Jugador.d \
./src/LinkedList.d \
./src/inputs.d \
./src/main.d \
./src/parser.d 

OBJS += \
./src/Contoller.o \
./src/Jugador.o \
./src/LinkedList.o \
./src/inputs.o \
./src/main.o \
./src/parser.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Contoller.d ./src/Contoller.o ./src/Jugador.d ./src/Jugador.o ./src/LinkedList.d ./src/LinkedList.o ./src/inputs.d ./src/inputs.o ./src/main.d ./src/main.o ./src/parser.d ./src/parser.o

.PHONY: clean-src

