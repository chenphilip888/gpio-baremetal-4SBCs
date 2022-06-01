CROSS_COMPILE = aarch64-linux-gnu-
STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main
INCLUDE = -I.
CFLAGS  = -g -march=armv8-a -O1 -Wl,--build-id=none -nostdlib -fno-builtin $(INCLUDE)
LDSCRIPTS=-L. -T u-boot-spl.lds -lgcc
LFLAGS= $(LDSCRIPTS)

test: test.img

test.img: test.bin
	./rkbin1/tools/loaderimage --pack --uboot $< $@ 0x200000
	mkimage -n rk3328 -T rksd -d ./rkbin/rk33/rk3328_ddr_786MHz_v1.13.bin idbloader.img
	cat ./rkbin/rk33/rk3328_miniloader_v2.46.bin >> idbloader.img
	./rkbin1/tools/trust_merger trust.ini

test.bin: test.elf
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -S $< > test.list

test.elf: start.S exceptions.S crt0_64.S test.c uart.c printf.c timer.c clock.c gpio.c pwm.c i2c.c spi.c mmc.c
	$(CROSS_COMPILE)gcc $(CFLAGS) $^ $(LFLAGS) -o $@

.PHONY: burn_sdcard clean test

burn_sdcard: test.img
	./mksdcardimg.sh
	sudo dd if=./sdcard.img of=/dev/mmcblk0 bs=4096 conv=notrunc,fsync

clean:
	rm -f *.img test.bin *.elf test.list
