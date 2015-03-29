################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Runner/Runner.cpp \
../Runner/RunnerFactory.cpp 

OBJS += \
./Runner/Runner.o \
./Runner/RunnerFactory.o 

CPP_DEPS += \
./Runner/Runner.d \
./Runner/RunnerFactory.d 


# Each subdirectory must supply rules for building sources it contributes
Runner/%.o: ../Runner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


