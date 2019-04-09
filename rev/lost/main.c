#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char* data, char* result, int len)
{
    int total = 0;
    unsigned int k = 0, c = 1;

    for (int i = 0; i < len; i++) {
        total *= data[i];
        total %= 127;
        total /= 3;
        total += data[i % (k+1)];
        c -= ((1 << 2) | 1) & ~4;
        if (!(c | ((1<<2)&0))) {
            total = (total & 0) + data[i];
            result[k++] = total;
            c = (unsigned int)data[i]+1;
        }
    }
    result[k-1] = '\n';
}

int main()
{
    char flag[64];
    char target[64];
    char encrypted[] = {
        0x46, 0xa3, 0x97, 0xa2, 0x55, 0x53, 0xbe, 0xf1, 0xfc, 0xf9, 0x79, 0x6b, 0x52, 0x14, 0x13, 0xe9, 0xe2, 0x2d, 0x51, 0x8e, 0x1f, 0x56, 0x8, 0x57, 0x27, 0xa7, 0x5, 0xd4, 0xd0, 0x52, 0x82, 0x77, 0x75, 0x1b, 0x99, 0x4a, 0xed, 0x58, 0x3d, 0x6a, 0x52, 0x36, 0xd5, 0x24, 0x4a, 0x68, 0x8e, 0xad, 0x95, 0x5f, 0x3c, 0x35, 0xb5, 0xc4, 0x8c, 0xdd, 0x6c, 0x11, 0x32, 0x3d, 0xe2, 0xb4, 0xb4, 0x59, 0xcf, 0xce, 0x23, 0x3d, 0x27, 0xdf, 0xa7, 0x4c, 0xf9, 0x96, 0xfc, 0x1e, 0xe0, 0x66, 0x2c, 0xe, 0x7b, 0x8c, 0xca, 0x30, 0x42, 0x8f, 0xbc, 0x9f, 0x7b, 0xce, 0xd1, 0xb8, 0xb1, 0x87, 0xec, 0x8a, 0xd6, 0xbb, 0x2e, 0x15, 0x63, 0xe, 0x3c, 0xdc, 0xa4, 0x3a, 0x7a, 0x6, 0x20, 0xa7,
        0x93, 0x1b, 0x34, 0xdd, 0x4c, 0xf5, 0xec, 0x88, 0x96, 0x68, 0xd6, 0x68, 0xa0, 0x9, 0x6f, 0x8e, 0x93, 0x47, 0xc9, 0x41, 0xdb, 0xac, 0xcf, 0x97, 0x89, 0xf3, 0x51, 0x5, 0x79, 0x71, 0x2c, 0xe, 0xd, 0x60, 0x6b, 0x59, 0xd5, 0x59, 0x41, 0xe1, 0x6c, 0xc1, 0xb9, 0x55, 0x63, 0x42, 0x44, 0x71, 0x55, 0xb, 0xba, 0x97, 0xe6, 0x68, 0x67, 0xfe, 0x71, 0x5b, 0x50, 0x76, 0x55, 0xc2, 0x22, 0x63, 0x4f, 0x2, 0xce, 0xa8, 0xd8, 0xa7, 0xa, 0x45, 0x6a, 0x43, 0x1a, 0x4d, 0x85, 0x5f, 0x3e, 0xdb, 0x6a, 0xf8, 0x73, 0xd1, 0x61, 0x5a, 0xd0, 0x53, 0x35, 0x21, 0xc9, 0x8a, 0x63, 0xec, 0x6d, 0xb2, 0xee, 0xbc, 0xda, 0x47, 0x64, 0xe5, 0xd, 0x4e, 0x47, 0xa8, 0x27, 0x1b, 0x2f, 0x6, 0x59, 0x8a, 0xf0, 0x53, 0x7d, 0xc2, 0x34, 0xd7, 0x13, 0x87, 0x8c, 0xb3, 0xd1, 0x97, 0x18, 0x3e, 0x84, 0x4a, 0xac, 0xc0, 0xa5, 0xf4, 0x26, 0xb, 0x2, 0xf3, 0xb3, 0xa8, 0x10, 0x62, 0xaf, 0xe8, 0xec, 0xa0, 0x3c, 0x6a, 0xe2, 0xf0, 0xc1, 0xf5, 0x78, 0xce, 0xa9, 0xc9, 0x66, 0x41, 0x8, 0x6a, 0xc, 0x35, 0x2c, 0xb1, 0x2a, 0xd1, 0x3c, 0xab, 0xc5, 0xef, 0x54, 0x55, 0x53, 0x83, 0x3f, 0xbf, 0x24, 0xfa, 0x7b, 0x2b, 0x86, 0xeb, 0x6c, 0x7c, 0x65, 0x3b, 0xa6, 0xae, 0x21, 0x67, 0xb7, 0x8c, 0x73, 0xec, 0x38, 0xa4, 0x96, 0xa, 0xe0, 0x42, 0xcf, 0x51, 0x16, 0xa5, 0x24, 0x9a, 0xe4, 0xe3, 0x3e, 0xdf, 0x8e, 0x45, 0xcc, 0xfb, 0x41, 0xb1, 0xb6, 0xe7, 0x60, 0x58, 0xcf, 0x97, 0x64, 0xc2, 0x4, 0x9c, 0x68, 0x9a, 0xa6, 0xc8, 0x5c, 0xf5, 0x99, 0xf2, 0x9b, 0xbd, 0xd, 0x0, 0x22, 0xca, 0xe0, 0xb0, 0x10, 0x2d, 0x2c, 0x52, 0xde, 0xe3, 0xb9, 0xbe, 0x3c, 0x89, 0xd6, 0xa0, 0x4d, 0xda, 0xbc, 0x35, 0xf5, 0x63, 0x7d, 0xd1, 0xd8, 0x18, 0xc4, 0x75, 0x55, 0xd1, 0xf4, 0x77, 0x1d, 0xd5, 0x29, 0x2d, 0x82, 0x55, 0x7f, 0xe0, 0xb8, 0x3a, 0xa0, 0x74, 0x43, 0x77, 0x94, 0x10, 0xd1, 0x51, 0x45, 0xc7, 0x34, 0x43, 0x1a, 0xe, 0x5b, 0xde, 0x3, 0x30, 0x31, 0xf7, 0xa8, 0x4e, 0x64, 0x4e, 0x51, 0x7b, 0xd0, 0x26, 0x7b, 0xb2, 0xdf, 0x35, 0xd2, 0x54, 0xf7, 0xc9, 0xe9, 0x9, 0x9b, 0xba, 0x4e, 0xe3, 0xef, 0x91, 0xfd, 0xfd, 0x6c, 0x5c, 0x80, 0x9d, 0x8d, 0x78, 0xc5, 0x5b, 0x46, 0x17, 0x57, 0x18, 0x3d, 0xd2, 0x4a, 0x9c, 0x87, 0x1d, 0x71, 0x7f, 0xe6, 0xda, 0x88, 0x2, 0x95, 0x57, 0xe5, 0x85, 0x68, 0xe3, 0x3, 0xd5, 0x41, 0x83, 0xf2, 0x4e, 0x7c, 0x38, 0xaa, 0xc2, 0x4f, 0x2, 0x5a, 0xc, 0x54, 0xa4, 0xa9, 0xdb, 0x41, 0x9a, 0xda, 0x28, 0x75, 0x64, 0x2b, 0xb, 0x3b, 0x90, 0x11, 0xa3, 0x75, 0x14, 0xf8, 0x36, 0x18, 0xeb, 0x84, 0x14, 0x24, 0xae, 0x56, 0xf2, 0xb0, 0xb1, 0x0, 0x84, 0xd5, 0x33, 0x29, 0x60, 0x18, 0xc3, 0x3c, 0xbf, 0x39, 0x20, 0xea, 0xc3, 0x5b, 0x7c, 0xd4, 0xfe, 0x71, 0x69, 0xf8, 0xa7, 0x1, 0x64, 0xab, 0x15, 0x9, 0x5b, 0x6b, 0x7b, 0x8b, 0x9c, 0xfa, 0x11, 0x73, 0x24, 0xf0, 0xb, 0x67, 0xac, 0xca, 0x20, 0x4c, 0x36, 0x64, 0xa7, 0x32, 0x39, 0x27, 0x23, 0x22, 0x9f, 0x4a, 0x23, 0x83, 0x33, 0xf5, 0xb7, 0xc, 0xd0, 0xa3, 0x88, 0xdc, 0x40, 0x83, 0xed, 0x33, 0x28, 0x5e, 0x3e, 0xf, 0x8b, 0x89, 0x30, 0xd7, 0x3f, 0x94, 0x80, 0x71, 0x4d, 0x27, 0x94, 0x70, 0xc6, 0xde, 0x13, 0xc9, 0x54, 0x4b, 0xd6, 0x26, 0xee, 0x5f, 0x3, 0xae, 0x62, 0x70, 0xe2, 0x8a, 0x4e, 0xa0, 0x9a, 0xd9, 0xa9, 0x4a, 0xb2, 0xe8, 0x33, 0x5e, 0xb2, 0xd9, 0xab, 0xd9, 0xed, 0x9b, 0x20, 0x4c, 0x2f, 0x69, 0xa1, 0x7a, 0x40, 0x47, 0xe8, 0x1f, 0xc9, 0x97, 0x2, 0xb9, 0xf9, 0x8c, 0x8, 0x9b, 0xa6, 0xe2, 0xc4, 0x70, 0x15, 0xae, 0xce, 0xc7, 0x8, 0xfa, 0x21, 0xf6, 0x96, 0xc0, 0x43, 0x45, 0x2a, 0x64, 0xbf, 0xea, 0xab, 0xa8, 0x89, 0xf4, 0xc0, 0x8b, 0x35, 0xae, 0xba, 0x98, 0x37, 0x56, 0xbe, 0x99, 0x9b, 0x30, 0xae, 0x4a, 0x7e, 0xf5, 0xd1, 0x79, 0x96, 0xc8, 0x90, 0xd6, 0xd, 0xd5, 0x80, 0xf0, 0x16, 0x6b, 0x9d, 0x3e, 0xf5, 0x12, 0xfe, 0x1, 0xc1, 0xba, 0x99, 0xf8, 0x90, 0x59, 0x12, 0x2c, 0x89, 0xc0, 0xf5, 0x8, 0x36, 0xc8, 0x2, 0xcc, 0x11, 0x92, 0x23, 0x9d, 0xe7, 0xa3, 0x34, 0x8f, 0xfd, 0x8f, 0x2d, 0x3d, 0x5, 0x3f, 0xbb, 0x6, 0x80, 0xf5, 0xa0, 0xf8, 0x87, 0xf9, 0xb, 0x33, 0x3, 0x4b, 0xa9, 0x8a, 0x81, 0xf1, 0x8c, 0xcd, 0x3, 0x9e, 0xf0, 0xa1, 0x87, 0x95, 0x31, 0x5, 0x25, 0xdd, 0xc1, 0x2a, 0x9c, 0x7e, 0xaf, 0x1e, 0x74, 0x50, 0x96, 0x7b, 0xc9, 0xa2, 0x2f, 0x4c, 0x6d, 0xd8, 0xd7, 0x62, 0xef, 0xca, 0xe3, 0xbd, 0xcd, 0x3, 0x2f, 0xee, 0xa, 0x44, 0x20, 0xf, 0x69, 0xfd, 0xd1, 0x13, 0x1b, 0xcf, 0xc2, 0x39, 0xc3, 0x93, 0x4f, 0x40, 0x5d, 0x71, 0x6f, 0xaa, 0xdf, 0xc7, 0x2, 0xcf, 0x12, 0x65, 0xd, 0xdf, 0x68, 0xbb, 0xcf, 0x72, 0x0, 0x6f, 0x2, 0x69, 0xed, 0xd3, 0xfb, 0x9, 0xa3, 0xbf, 0xc1, 0x67, 0x53, 0x11, 0x27, 0x30, 0x83, 0x16, 0x5a, 0x63, 0x5d, 0xdb, 0xb2, 0x6f, 0x42, 0x3f, 0x50, 0x2a, 0xfb, 0x9f, 0x1d, 0xfb, 0xf, 0x1f, 0xe5, 0x7c, 0x72, 0xe1, 0x85, 0x95, 0x21, 0x47, 0x7c, 0xf3, 0x59, 0x24, 0x25, 0x5c, 0x3a, 0x7f, 0xbf, 0x98, 0x5c, 0xf1, 0x87, 0x1e, 0x31, 0xd7, 0x38, 0xc7, 0x2d, 0xf6, 0xe4, 0x2a, 0x86, 0x83, 0x10, 0x3, 0xf5, 0x71, 0x89, 0xb, 0x93, 0x50, 0x88, 0x87, 0xa9, 0xac, 0xac, 0x6, 0x66, 0xac, 0x45, 0x7e, 0x88, 0x37, 0x7, 0x26, 0x69, 0x5e, 0xed, 0x16, 0xd5, 0xd3, 0x40, 0x5c, 0xd6, 0xcf, 0xde, 0x4d, 0x42, 0xe7, 0x58, 0x55, 0x39, 0x60, 0xdc, 0xe2, 0x8c, 0xa, 0x69, 0xf3, 0x36, 0x2e, 0xf1, 0x32, 0xbe, 0x66, 0x78, 0xe4, 0x4f, 0xd7, 0xd2, 0x65, 0x2d, 0x26, 0x26, 0x89, 0xfd, 0x75, 0xe7, 0x4b, 0x37, 0xd0, 0x23, 0x8c, 0xa, 0x84, 0xe9, 0x6c, 0x11, 0xf3, 0x55, 0x84, 0x2a, 0x84, 0xf6, 0x68, 0x6a, 0x6f, 0xcc, 0xb9, 0xc6, 0x9f, 0x9e, 0xf3, 0x46, 0x44, 0xfc, 0xc3, 0xba, 0xe5, 0x8e, 0xf1, 0xb6, 0xb1, 0x37, 0xfe, 0xc0, 0xb5, 0xe8, 0xac, 0x47, 0xdc, 0x3, 0xcb, 0x86, 0x87, 0x42, 0x6e, 0xf1, 0xb2, 0x3b, 0x2b, 0xf8, 0xda, 0x49, 0xed, 0xa0, 0x8e, 0xea, 0x64, 0xc8, 0x50, 0xf2, 0x3a, 0x7, 0x25, 0x39, 0x47, 0xda, 0x22, 0xf4, 0x22, 0x7e, 0x77, 0x6e, 0x84, 0xfe, 0xb0, 0xf2, 0x70, 0xe2, 0x2e, 0x1b, 0xdc, 0x89, 0xe3, 0x4a, 0x2a, 0x72, 0x35, 0x36, 0xf, 0xba, 0x6, 0x81, 0xf5, 0xd, 0xa6, 0x2f, 0xd4, 0x2, 0xd1, 0x49, 0x24, 0x50, 0xc0, 0x92, 0x55, 0xbf, 0xc3, 0x48, 0xaf, 0xa6, 0x77, 0xca, 0x83, 0x80, 0x2e, 0x4d, 0xaa, 0xa1, 0x3, 0x39, 0xdb, 0x9, 0xbb, 0xd1, 0x95, 0xe1, 0x81, 0x6a, 0xe3, 0x53, 0xb3, 0x88, 0x23, 0x74, 0x9a, 0x78, 0xb3, 0x5e, 0x41, 0x63, 0x6, 0x38, 0x37, 0xad, 0x9, 0xb8, 0xdc, 0x57, 0xe2, 0xfd, 0x5a, 0x1d, 0x59, 0xe2, 0x58, 0x2c, 0x78, 0x3a, 0x2d, 0xe3, 0x9e, 0x80, 0x17, 0x27, 0x23, 0x8c, 0xc1, 0x1c, 0xbf, 0xa0, 0x5d, 0xa3, 0xa6, 0x15, 0xd0, 0x2f, 0xcd, 0x2d, 0x6, 0xb0, 0xaa, 0xdf, 0xcd, 0x5, 0xc2, 0xa5, 0x31, 0xbb, 0xe0, 0x5e, 0x9f, 0xfe, 0x5e, 0x36, 0x26, 0x1, 0x42, 0x67, 0x61, 0x1d, 0x3, 0x8, 0xf9, 0xa6, 0x2e, 0xf, 0xf6, 0xdd, 0x5c, 0x25, 0xe3, 0xe, 0xcf, 0x44, 0x5b, 0xd4, 0x86, 0x2, 0x85, 0x42, 0x62, 0xe3,
        0x61, 0x61, 0xc1, 0x98, 0x7, 0xc3, 0xda, 0xed, 0x60, 0x5d, 0xf6, 0xda, 0x83, 0xa4, 0x69, 0x7b, 0x82, 0xc6, 0xa0, 0xe6, 0x54, 0xef, 0x2b, 0xaf, 0xc5, 0x31, 0x31, 0x4b, 0x74, 0x93, 0xaf, 0x55, 0x74, 0x71, 0x6d, 0xfa, 0x35, 0x49, 0xe9, 0x16, 0x26, 0x60, 0xf0, 0xaa, 0x5, 0x5a, 0x26, 0x88, 0x21, 0x46, 0x6f, 0x75, 0x36, 0x1a, 0xa5, 0x7b, 0x4b, 0xd6, 0xc7, 0x3f, 0xea, 0xf6, 0x95, 0xde, 0x68, 0x82, 0xda, 0x1e, 0xcb, 0x44, 0x34, 0x72, 0xa4, 0xa4, 0x61, 0x1d, 0x29, 0xfe, 0xc2, 0xb1, 0xa0, 0x88, 0xa0, 0x95, 0xbe, 0xba, 0xba, 0xba, 0x86, 0x12, 0x2, 0xc5, 0xfc, 0xf8, 0xda, 0xdb, 0x61, 0x5e, 0x36, 0xfe, 0xa9, 0xf9, 0xb2, 0x1c, 0x9e, 0x57, 0xb8, 0xc8, 0xd6, 0x7b, 0xf9, 0x77, 0x4, 0x9b, 0x8c, 0x43, 0xd5, 0xc7, 0x7d, 0x5c, 0xd9, 0x7f, 0xa2, 0xd6, 0x78, 0x7d, 0x32, 0x59, 0x5b, 0xe8, 0x59, 0x85, 0xe2, 0xc, 0xa1, 0x2, 0x64, 0xda, 0x4a, 0xba, 0xd5, 0x44, 0xb1, 0x5a, 0x5f, 0x3e, 0x9d, 0x36, 0x6, 0x9a, 0x92, 0xdf, 0x1a, 0x35, 0x36, 0x92, 0x33, 0xe8, 0x6b, 0x8e, 0xd1, 0xc4, 0x14, 0xb4, 0x51, 0x36, 0x36, 0x35, 0x11, 0x80, 0xef, 0x66, 0x66, 0xc5, 0xa1, 0xc0, 0xa4, 0x5f, 0xdd, 0xda, 0xe5, 0x78, 0x6e, 0xc5, 0x92, 0x23, 0x7c, 0xa4, 0x56, 0x65, 0x11, 0x65, 0x37, 0x55, 0xf8, 0x6b, 0xa6, 0xae, 0xa2, 0x5b, 0x3f, 0xa2, 0x4b, 0xa6, 0x68, 0x6c, 0x67, 0x8d, 0xcc, 0x46, 0x68, 0xb2, 0xbe, 0x56, 0xf7, 0xd1, 0x7a, 0xf3, 0x76, 0x50, 0x59, 0x7, 0x35, 0x10, 0x5d, 0x2f, 0x7c, 0x83, 0xdd, 0x9e, 0xdf, 0x1e, 0x41, 0xaa, 0xc4, 0x2a, 0x97, 0x2c, 0xb7, 0x64, 0xf1, 0x20, 0x96, 0xb1, 0xf6, 0xe, 0x83, 0x71, 0x3, 0x79, 0x41, 0x5c, 0x1, 0x77, 0x6d, 0x5e, 0xa6, 0x69, 0x61, 0x4, 0x8, 0xc0, 0x22, 0xc8, 0xeb, 0x66, 0xf2, 0x83, 0x13, 0xaa, 0x67, 0x5, 0x4b, 0xfd, 0xb6, 0x35, 0x42, 0xc, 0xb9, 0x33, 0xf, 0xb3, 0x74, 0x6c, 0xb4, 0x6b, 0x59, 0x92, 0x91, 0xc2, 0xf3, 0x96, 0x4a, 0x35, 0x38, 0x13, 0x21, 0x1f, 0x86, 0x24, 0x32, 0x31, 0x8b, 0x37, 0xfb, 0x89, 0x6e, 0xbd, 0x15, 0xa7, 0x70, 0xa4, 0x5b, 0x65, 0x90, 0x10, 0xd0, 0xe9, 0xa2, 0x63, 0x2c, 0x17, 0x79, 0x76, 0xcb, 0xb1, 0x9, 0x6c, 0xd0, 0x62, 0x8f, 0x90, 0x82, 0x41, 0x1c, 0xba, 0xbc, 0x25, 0xa8, 0x7b, 0xb9, 0x50, 0xeb, 0x5e, 0xac, 0x51, 0xee, 0x3c, 0xa2, 0x58, 0xdf, 0x6, 0x84, 0x76, 0x7f, 0x7a, 0x42, 0xb0, 0x84, 0xae, 0x2, 0x14, 0x3f, 0x84, 0xd4, 0xda, 0xbe, 0x92, 0x7f, 0x67, 0xe, 0xb8, 0x38, 0x79, 0x18, 0xe4, 0x4b, 0x86, 0x21, 0xed, 0xdf, 0x80, 0x73, 0x64, 0xf6, 0x72, 0x5f, 0x39, 0x23, 0xe3, 0x67, 0xa4, 0x77, 0x26, 0xa9, 0xcc, 0x1, 0x68, 0x5f, 0x0, 0x50, 0xec, 0xb9, 0x88, 0x66, 0x51, 0x6d, 0x31, 0x57, 0xe, 0x1f, 0x37, 0xf, 0x12, 0x1c, 0x6, 0x84, 0x7b, 0xbf, 0x28, 0xde, 0xa6, 0xcc, 0xd5, 0xcd, 0x76, 0xa2, 0xce, 0x38, 0x5f, 0x2, 0x4f, 0xaf, 0x6e, 0x88, 0xb7, 0x55, 0x59, 0xa4, 0x86, 0xb0, 0xb2, 0x26, 0xe8, 0xc1, 0x38, 0x84, 0x48, 0xbd, 0x7f, 0x87, 0xe5, 0x5e, 0x2e, 0x32, 0xb3, 0xfb, 0xa9, 0x57, 0x4b, 0x88, 0xd8, 0x1a, 0xb7, 0x48, 0xa2, 0x6f, 0x9d, 0xfb, 0x14, 0xa3, 0x2c, 0x46, 0xc9, 0x94, 0x9, 0x3, 0x19, 0xd0, 0xc0, 0x98, 0xd7, 0xa6, 0x76, 0x6, 0x37, 0xd8, 0xaa, 0x82, 0x2, 0x81, 0x4d, 0xa, 0x5a, 0x67, 0xc1, 0x22, 0xa, 0x31, 0x3f, 0x85, 0x45, 0xe3, 0x31, 0x8c, 0xad, 0xc6, 0x15, 0xb0, 0xdf, 0x65, 0xf0, 0xf8, 0x3d, 0x17, 0xee, 0xc2, 0x70, 0x19, 0x45, 0x72, 0x9a, 0x92, 0xfc, 0x75, 0x79, 0xbe, 0x97, 0x3, 0x70, 0x57, 0x88, 0x35, 0x3b, 0xba, 0x41, 0x68, 0x1, 0x56, 0x99, 0x60, 0x61, 0x3b, 0x8a, 0x59, 0xf7, 0xa2, 0xc8, 0xbb, 0x13, 0xe1, 0x80, 0x5, 0xfc, 0x93, 0x81, 0x72, 0xd, 0x41, 0x89, 0x11, 0x31, 0xe0, 0x19, 0x66, 0x9b, 0x53, 0xa8, 0x5, 0x54, 0x7e, 0x1e, 0xb5, 0x3a, 0x28, 0x8e, 0x32, 0xca, 0xd6, 0xed, 0x5d, 0xb9, 0x6f, 0xe2, 0xb6, 0x82, 0xe3, 0xa8, 0x8f, 0xa4, 0x32, 0x20, 0xd5, 0x14, 0x3a, 0x3d, 0xaf, 0xd, 0x65, 0x34, 0x62, 0xe3, 0x52, 0x97, 0x1e, 0x7b, 0x26, 0xd0, 0xc5, 0xfd, 0xbe, 0xa3, 0x37, 0xad, 0x6, 0x6d, 0x30,
        0xe9, 0x16, 0x40, 0x8f, 0x48, 0x60, 0xe4, 0xdb, 0x1a, 0x22, 0xc, 0x28, 0x7, 0x40, 0xa, 0x6b, 0x13, 0xa1, 0x9, 0xe, 0x47, 0xd9, 0x65, 0x53, 0xc4, 0x99, 0xf6, 0x7b, 0xc6, 0x7c, 0xe8, 0x77, 0xe6, 0x7e, 0x37, 0xf5, 0x47, 0x17, 0xda, 0x23, 0x32, 0x7d, 0x2f, 0xd9, 0x84, 0xef, 0xe3, 0xef, 0x3, 0x5, 0xf9, 0x11, 0xcb, 0xd3, 0x64, 0x91, 0xec, 0xdb, 0xd, 0x34, 0xd7, 0x76, 0xab, 0xbe, 0xf4, 0x62, 0xb4, 0xbb, 0x79, 0x90, 0xdf, 0x2b, 0x8d, 0x8e, 0x5, 0x12, 0x7e, 0x68, 0x3, 0x1, 0xec, 0x7c, 0x12, 0xb9, 0x50, 0xf6, 0x4b, 0xbd, 0x52, 0xd7, 0xf1, 0x2a, 0x4e, 0x1d, 0x69, 0xc3, 0x7f, 0x9d, 0x7f, 0xf8, 0x2e, 0xde, 0x25, 0x3b, 0xed, 0xa9, 0x4e, 0x6c, 0x13, 0xd0, 0x6e, 0x0, 0x4d, 0x0, 0x39, 0x1d, 0x76, 0x84, 0xda, 0xc8, 0xdc, 0x4c, 0x73, 0x2b, 0x34, 0x69, 0xdc, 0x6e, 0x68, 0x7a, 0x6e, 0x62, 0x29, 0xcc, 0x7, 0x64, 0xba, 0x30, 0x32, 0x28, 0xc2, 0x3, 0x16, 0x43, 0x50, 0x16, 0x7c, 0x6e, 0xd, 0x81, 0xc8, 0xd5, 0x5e, 0x16, 0xc8, 0x9, 0x7f, 0x25, 0x78, 0xe8, 0xa0, 0x66, 0xca, 0x49, 0x33, 0x51, 0x2d, 0x6e, 0x81, 0x60, 0x16, 0xc4, 0x63, 0x2c, 0x8, 0x34, 0xc1, 0x38, 0x84, 0xa2, 0x4e, 0x6, 0x6b, 0x25, 0x64, 0x81, 0x6d, 0x6e, 0x81, 0x93, 0x66, 0xe9, 0xb3, 0x4c, 0xb4, 0xfc, 0xfe, 0x85, 0xa9, 0x6d, 0x86, 0xa, 0x83, 0x4b, 0xed, 0x2f, 0x53, 0x22, 0x71, 0xd8, 0xc4, 0xbf, 0x5e, 0xaf, 0x64, 0xc3, 0xb1, 0xd2, 0xb1, 0x33, 0xe5, 0x97, 0x1d, 0x99, 0xe3, 0x51, 0x96, 0xe2, 0x56, 0x40, 0xd0, 0xdc, 0xca, 0xd3, 0x66, 0x29, 0xb8, 0x83, 0x7c, 0xda, 0x74, 0xd4, 0x1f, 0xb3, 0x34, 0xce, 0x19, 0x77, 0x0, 0x6b, 0x29, 0x33, 0xd0, 0xc0, 0xcf, 0x6a, 0x24, 0xa0, 0x80, 0x7, 0xf6, 0x40, 0x57, 0xd4, 0xb, 0x2c, 0x7d, 0x43, 0xaf, 0xf9, 0x1e, 0x24, 0xcf, 0xbc, 0xd7, 0x83, 0x8c, 0x70, 0xfa, 0xc, 0x5b, 0x24, 0x40, 0x2c, 0x64, 0x8f, 0x96, 0x88, 0xb0, 0x96, 0xf, 0xa7, 0xd7, 0x67, 0xfb, 0xe2, 0x13, 0x79, 0x27, 0xc2, 0xf3, 0xc4, 0x66, 0x43, 0x82, 0x3e, 0xc6, 0x8e, 0x2f, 0xc1, 0x9a, 0xa, 0x65, 0x5a, 0x37, 0xc9, 0xea, 0x4d, 0xd1, 0x1b, 0xe4, 0xe0, 0xc2, 0xbc, 0xc7, 0x3f, 0x1f, 0xda, 0x38, 0x46, 0x1d, 0x2c, 0x8b, 0x83, 0x6f, 0xe, 0x42, 0x37, 0x36, 0x1c, 0xf0, 0x77, 0x36, 0xfa, 0xdc, 0x91, 0x32, 0xa6, 0xfb, 0x0, 0xf7, 0x17, 0xe4, 0x59, 0x59, 0x21, 0x21, 0x18, 0x40, 0x7c, 0x51, 0x7, 0x19, 0xfc, 0x92, 0x9d, 0x6d, 0x20, 0x5f, 0x23, 0x3c, 0x50, 0x1b, 0x72, 0xca, 0xf7, 0x83, 0xfd, 0x1f, 0x7f, 0x7d, 0x17, 0x16, 0x62, 0x70, 0xef, 0x83, 0x12, 0x8, 0xc3, 0xe, 0x59, 0xca, 0x32, 0x27, 0x57, 0xdc, 0xc4, 0x44, 0xfc, 0xa3, 0xe6, 0xb8, 0x73, 0x2, 0xab, 0x3f, 0x7a, 0x2f, 0xbc, 0x99, 0x2f, 0x3a, 0x30, 0xc4, 0x9c, 0xa1, 0xb4, 0x9f, 0x33, 0xbd, 0xe2, 0x41, 0x96, 0xae, 0x68, 0x6d, 0xb, 0xad, 0xb1, 0x9, 0x51, 0x19, 0xc1, 0x45, 0x1b, 0x6d, 0x84, 0x15, 0x1d, 0x41, 0xae, 0xcb, 0x7b, 0x34, 0xdf, 0x90, 0x97, 0x1, 0x46, 0x37, 0xb3, 0x83, 0x1a, 0xf4, 0x1a, 0x48, 0xdc, 0x88, 0x54, 0x8a, 0xb9, 0xdc, 0x5c, 0xd2, 0x9e, 0x21, 0x6e, 0x8c, 0xa5, 0x83, 0x29, 0x66, 0xb2, 0xf4, 0xe1, 0x12, 0x5, 0xf8, 0x92, 0x4b, 0x30, 0x46, 0xce, 0xc9, 0x3b, 0x69, 0x92, 0x97, 0x71, 0xe6, 0xa2, 0x2b, 0xc3, 0x7e, 0x7e, 0xe1, 0x30, 0x9f, 0xec, 0xed, 0x45, 0xef, 0x96, 0xab, 0x22, 0x8b, 0xd, 0x34, 0x91, 0x6, 0xc6, 0x5c, 0xb5, 0x8c, 0xab, 0xfe, 0x47, 0x94, 0x91, 0xdf, 0x6, 0xf7, 0x82, 0x31, 0x3b, 0x1, 0xaf, 0x1e, 0xa0, 0x1c, 0x8b, 0x65, 0x8c, 0x23, 0x90, 0xae, 0x2e, 0x9d, 0x63, 0x3f, 0x23, 0xa9, 0x9c, 0xd8, 0x37, 0x34, 0xc7, 0xd7, 0xfd, 0x5c, 0xe9, 0xdd, 0x62, 0xe1, 0xdf, 0x13, 0x1e, 0x60, 0x43, 0xbb, 0x80, 0x5f, 0xc6, 0xe5, 0x6b, 0xe9, 0x76, 0x9a, 0x98, 0x93, 0x7d, 0xd7, 0xb6, 0x27, 0xf3, 0xf, 0xdd, 0xbb, 0xe7, 0xdc, 0x97, 0x51, 0x3a, 0xf9, 0x33, 0x1b, 0x8d, 0xd0, 0xfa, 0xd0, 0xc, 0x7c, 0xaf, 0xd3, 0xe1, 0x1c, 0x3d, 0xd8, 0x39, 0xb6, 0xd5, 0x6c, 0x34, 0x2e, 0xa3, 0xda, 0x22, 0xb2, 0xb9, 0x5e, 0x1a, 0x16, 0x75, 0x6b, 0xcf, 0xef, 0x1f, 0xea, 0x7d, 0xef, 0x66, 0x4e, 0xfc, 0xe2, 0xfd, 0x50, 0x44, 0x1a, 0x8d, 0x1d, 0x50, 0xe3, 0xa, 0x4, 0x12, 0xad, 0xdf, 0xb3, 0xdf, 0x19, 0x91, 0xfa, 0xae, 0x8, 0xe5, 0x7e, 0xf7, 0x5, 0xe9, 0x75, 0xf5, 0x50, 0xc3, 0x72, 0xb2, 0x41, 0x63, 0xc2, 0xf6, 0x5c, 0xcf, 0x15, 0x2c, 0xb3, 0x9e, 0x31, 0x45, 0xcb, 0x90, 0xf9, 0xab, 0xa9, 0xb, 0x26, 0xd7, 0x13, 0xd, 0x56, 0x8a, 0x12, 0x40, 0x0, 0x87, 0x10, 0x43, 0x79, 0xc2, 0x85, 0xbb, 0xba, 0x61, 0x8c, 0x4f, 0xd, 0x40, 0x6d, 0x3e, 0x86, 0x39, 0x4e, 0x0, 0x64, 0x77, 0xb, 0x8b, 0x4f, 0x1f, 0x18, 0x26, 0x29, 0xa9, 0x66, 0x2a, 0xb1, 0xf6, 0xec, 0x2b, 0xb9, 0xf1, 0xe7, 0xf3, 0xd2, 0x74, 0xc2, 0xe0, 0x34, 0xaf, 0x9e, 0x3a, 0xe8, 0xed, 0x3a, 0xcd, 0xe4, 0xc5, 0x59, 0x35, 0x64, 0xf0, 0x5b, 0x8d, 0x9a, 0x41, 0xb7, 0xcb, 0x38, 0x25, 0xf7, 0x72, 0x96, 0x5f, 0xe5, 0x6a, 0x53, 0x29, 0xca, 0x66, 0x87, 0xd8, 0x69, 0x42, 0xc2, 0xd6, 0x7c, 0x10, 0xbc, 0x42, 0x69, 0x71, 0xa6, 0xd9, 0xcc, 0x35, 0xf3, 0x8d, 0x6c, 0xc0, 0x46, 0x11, 0xb8, 0xb8, 0xa8, 0x97, 0x1e, 0x92, 0xea, 0x47, 0x5d, 0xf1, 0x21, 0x46, 0x34, 0x63, 0x9d, 0x31, 0x73, 0xd9, 0xf2, 0x5c, 0x4b, 0x1a, 0xb5, 0x97, 0x4f, 0xa9, 0xa4, 0x3b, 0x6a, 0xea, 0xcc, 0xa2, 0x23, 0x75, 0x3a, 0x42, 0x8, 0xa4, 0x89, 0xe4, 0x97, 0x2a, 0x2b, 0x4b, 0xd, 0xc8, 0x7c, 0x0, 0x22, 0x70, 0xdb, 0x6d, 0xa, 0x91, 0x84, 0xd8, 0x3c, 0x2a, 0x14, 0xa6, 0x94, 0x60, 0x4a, 0xb8, 0xd5, 0x4, 0xfa, 0x5d, 0xa9, 0x4, 0xc1, 0xc0, 0xae, 0xed, 0xc, 0xbb, 0x36, 0x9, 0xbc, 0x59, 0x7d, 0xf8, 0x18, 0x46, 0x3, 0xaa, 0x4b, 0xdb, 0xe6, 0xf4, 0x6f, 0xd, 0x89, 0xd0, 0x57, 0x42, 0x26, 0xdb, 0xbc, 0x4, 0x85, 0xc1, 0xc5, 0x46, 0x70, 0x33, 0xd1, 0xab, 0xe9, 0x5a, 0xe7, 0xc2, 0x53, 0x1, 0x88, 0x56, 0xab, 0xd3, 0xb1, 0x12, 0x48, 0x22, 0x1f, 0xd2, 0x72, 0x77, 0x94, 0x98, 0x53, 0x52, 0x1c, 0x58, 0x93, 0xe2, 0x1e, 0x4, 0x95, 0x6f, 0x2f, 0x7f, 0xca, 0x18, 0x42, 0x1e, 0x98, 0xcb, 0xf4, 0x44, 0x1f, 0x26, 0x56, 0x68, 0x48, 0x75, 0xba, 0x3a, 0x6c, 0x4f, 0x53, 0x3f, 0xa1, 0x6f, 0x17, 0xb4, 0xd1, 0x35, 0xb8, 0x68, 0x25, 0x68, 0xe7, 0xef, 0x0, 0xaa, 0xe, 0x98, 0xf5, 0x82, 0x5c, 0x15, 0xa9, 0xb2, 0x7d, 0x71, 0xa7, 0xb7, 0xac, 0x94, 0x8, 0x0, 0x53, 0x29, 0x6f, 0xea, 0xde, 0x42, 0x9f, 0x17, 0x2a, 0xc4, 0x7f, 0x12, 0xb4, 0x7f, 0x3c, 0x43, 0x0
    };

    printf("What is the flag?\n");
    fgets(flag, sizeof(flag), stdin);
    decrypt(encrypted, target, sizeof(encrypted));

    if (strncmp(flag, target, strlen(flag)) == 0) {
        printf("Correct!\n");
    } else {
        printf("Wrong.\n");
    }

    return EXIT_SUCCESS;
}