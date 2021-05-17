/*

    pHash, the open source perceptual hash library
    Copyright (C) 2009 Aetilius, Inc.
    All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Evan Klinger - eklinger@phash.org
    David Starkweather - dstarkweather@phash.org

*/

#include <stdint.h>
#include <stdio.h>

#include "math.h"
#include "pHash.h"

using namespace cimg_library;

int main(int argc, char **argv) {
    if (argc < 3) {
        printf(" not enough input args\n");
        exit(1);
    }

    const char *img1 = argv[1];
    const char *img2 = argv[2];

    ulong64 hash1, hash2;
    unsigned char *phash;
    int i;

    printf("file1: %s\n", img1);
    if (ph_dct_imagehash(img1, hash1) < 0) {  // calculate the hash
        printf("Failed to generate hash for %s\n", img1);
        return 1;
    }

    phash = (unsigned char *)&hash1;
    printf("phash1: ");
    for (i = 0; i < 8; i++) {
        printf("%02x", phash[i]);
    }
    printf("\n ");

    return 0;
}
