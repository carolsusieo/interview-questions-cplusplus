################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DoubleLinkedList.cpp \
../SingleLinkedList.cpp \
../StringExamples.cpp \
../StringExamples_test.cpp 

OBJS += \
./DoubleLinkedList.o \
./SingleLinkedList.o \
./StringExamples.o \
./StringExamples_test.o 

CPP_DEPS += \
./DoubleLinkedList.d \
./SingleLinkedList.d \
./StringExamples.d \
./StringExamples_test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


