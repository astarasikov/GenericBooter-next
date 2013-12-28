//
// Thank you @zhuowei! <3
//

#include <string.h>

#define FONT_WIDTH 8

/* Don't change that */
#define MSM_SMI_BASE                0x00000000
#define MSM_SMI_SIZE                0x04000000

/* Begin SMI region */
/* First part of SMI is used for OEMSBL & AMSS */
#define MSM_PMEM_SMI_BASE        (MSM_SMI_BASE + 0x02500000)
#define MSM_PMEM_SMI_SIZE        0x01B00000

#define MSM_FB_BASE                0x02500000
#define MSM_FB_SIZE                0x00600000

#define VIDEOBASE MSM_FB_BASE
#define WIDTH 800
#define HEIGHT 480

//Font taken from Minecraft.

#include "consolefont.c"

int Tegra_console_row = 0;
int Tegra_console_col = 0;

void Tegra_framebuffer_drawRect(int beginX, int beginY, int width, int height, int color) {
	for (int y = beginY; y < beginY + height; y++) {
		for (int x = beginX; x < beginX + width; x++) {
			int loc = VIDEOBASE + (((y * WIDTH) + x) * 4);
			*((int*) loc) = color;
		}
	}
}

void Tegra_framebuffer_setPixel(int x, int y, int color) {
	int loc = VIDEOBASE + (((y * WIDTH) + x) * 4);
	*((int*) loc) = color;
}

int Tegra_framebuffer_drawCharacter(char mychar, int screenr, int screenc) {
	int index = ((int) mychar) * FONT_WIDTH;
	int rr, cc;
	for (rr = 0; rr < FONT_WIDTH; rr++) {
		int myrow = console_font[index + rr];
		for (cc = 0; cc < FONT_WIDTH; cc++) {
			int thisPixel = (myrow >> (FONT_WIDTH - 1 - cc)) & 0x1;
			if (thisPixel) {
				Tegra_framebuffer_setPixel(screenc + cc, screenr + rr, 0xffffff);
			}
		}
	}
	return console_font_widths[(int) mychar] + 1;
}

void Tegra_console_init(void) {
	memset((void*)0x02B00000, 0xcc, 800 * 480 * 2);
	Tegra_console_col = 0;
	Tegra_console_row = 0;
	Tegra_framebuffer_drawRect(0, 0, WIDTH, HEIGHT, 0);
}

void Tegra_console_putchar(char c) {
	if (c == '\n') {
		Tegra_console_row += (FONT_WIDTH + 1);
		Tegra_console_col = 0;
		return;
	}
	Tegra_console_col += Tegra_framebuffer_drawCharacter(c, Tegra_console_row, Tegra_console_col);
	if (Tegra_console_col + FONT_WIDTH > WIDTH) {
		Tegra_console_row += (FONT_WIDTH + 1);
		Tegra_console_col = 0;
	}
}