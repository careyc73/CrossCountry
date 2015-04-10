################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Team/Conference.cpp \
../Team/Team.cpp 

OBJS += \
./Team/Conference.o \
./Team/Team.o 

CPP_DEPS += \
./Team/Conference.d \
./Team/Team.d 


# Each subdirectory must supply rules for building sources it contributes
Team/%.o: ../Team/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


