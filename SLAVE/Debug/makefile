################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/PWM1/subdir.mk
-include MCAL/PWM0/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TempSensor/subdir.mk
-include HAL/ServoMotor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/DcMotor/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
myprojects.lss \

FLASH_IMAGE += \
myprojects.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: myprojects.elf secondary-outputs

# Tool invocations
myprojects.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,myprojects.map -mmcu=atmega32 -o "myprojects.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

myprojects.lss: myprojects.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S myprojects.elf  >"myprojects.lss"
	@echo 'Finished building: $@'
	@echo ' '

myprojects.hex: myprojects.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex myprojects.elf  "myprojects.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: myprojects.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 myprojects.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) myprojects.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
