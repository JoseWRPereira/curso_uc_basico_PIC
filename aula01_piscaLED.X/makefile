PROJECT=aula01_blinkLED
CC=/opt/microchip/xc8/v2.32/bin/xc8-cc
DEVICE=16F887
DFP="/opt/microchip/mplabx/v5.45/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8"

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%.p1)
BUILDS := $(SRCS:%.c=build/%.p1)

all: build $(BINS) 
	$(CC)  -mcpu=16F887 -Wl,-Map=build/$(PROJECT).map  -DXPRJ_default=default  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp=$(DFP)  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto      -Wl,--memorysummary,build/memoryfile.xml -o build/$(PROJECT).elf  $(BUILDS)

%.p1: %.c
	$(CC) -mcpu=$(DEVICE) -c   -mdfp=$(DFP)  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=default  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall   -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o build/$@ $< 

build:
	mkdir build

clear: 
	rm build/*