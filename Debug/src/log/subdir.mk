################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/log/AssistorLog.cpp \
../src/log/log.cpp 

OBJS += \
./src/log/AssistorLog.o \
./src/log/log.o 

CPP_DEPS += \
./src/log/AssistorLog.d \
./src/log/log.d 


# Each subdirectory must supply rules for building sources it contributes
src/log/%.o: ../src/log/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/gtk-2.0 -I/usr/lib64/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/root/project/eclipse/assistor/inc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"  `pkg-config --cflags gtk+-2.0`
	@echo 'Finished building: $<'
	@echo ' '


