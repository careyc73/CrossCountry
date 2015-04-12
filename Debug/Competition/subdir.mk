################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Competition/ConferenceFinal.cpp \
../Competition/ConferenceMeet.cpp \
../Competition/ConferenceSeason.cpp \
../Competition/DualMeet.cpp \
../Competition/Meet.cpp \
../Competition/Performance.cpp \
../Competition/TeamPerformance.cpp 

OBJS += \
./Competition/ConferenceFinal.o \
./Competition/ConferenceMeet.o \
./Competition/ConferenceSeason.o \
./Competition/DualMeet.o \
./Competition/Meet.o \
./Competition/Performance.o \
./Competition/TeamPerformance.o 

CPP_DEPS += \
./Competition/ConferenceFinal.d \
./Competition/ConferenceMeet.d \
./Competition/ConferenceSeason.d \
./Competition/DualMeet.d \
./Competition/Meet.d \
./Competition/Performance.d \
./Competition/TeamPerformance.d 


# Each subdirectory must supply rules for building sources it contributes
Competition/%.o: ../Competition/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


