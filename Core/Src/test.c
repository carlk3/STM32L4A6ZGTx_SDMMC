/*
 * test.c
 *
 *  Created on: Apr 2, 2022
 *      Author: carlk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
#include "f_util.h"
#include "ff.h"

void test() {
//	FATFS fs;
    /* Format the drive with default parameters */
	// FRESULT f_mkfs (const TCHAR* path, BYTE opt, DWORD au, void* work, UINT len);	/* Create a FAT volume */
	printf("format\n");
	BYTE work[2 * _MAX_SS];
//    FRESULT fr = f_mkfs("", FM_EXFAT, 32768, work, sizeof work);
//    FRESULT fr = f_mkfs("", FM_ANY, 0, work, sizeof work);
	FRESULT fr = f_mkfs("", FM_FAT32, 0, work, sizeof work);
    if (FR_OK != fr) {
    	printf("f_mkfs error: %s (%d)\n", FRESULT_str(fr), fr);
    	return;
    }
	printf("format complete\n");
#if 0
    printf("mount\n");
    FRESULT fr = f_mount(&fs, "0:", 1);
    if (FR_OK != fr) {
    	printf("f_mount error: %s (%d)\n", FRESULT_str(fr), fr);
    	return;
    }
    printf("open\n");
    FIL fil;
    const char* const filename = "filename.txt";
    fr = f_open(&fil, filename, FA_OPEN_APPEND | FA_WRITE);
    if (FR_OK != fr && FR_EXIST != fr) {
        printf("f_open(%s) error: %s (%d)\n", filename, FRESULT_str(fr), fr);
        return;
    }
    printf("f_printf\n");
    if (f_printf(&fil, "Hello, world!\n") < 0) {
        printf("f_printf failed\n");
    }
    printf("close\n");
    fr = f_close(&fil);
    if (FR_OK != fr) {
        printf("f_close error: %s (%d)\n", FRESULT_str(fr), fr);
    }
//    f_unmount("0:");
    f_mount(&fs, "0:", 0);
#endif
}
