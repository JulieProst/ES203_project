#include"readbmp.h"
#include<iostream>
#include<stdio.h>
#include<stdexcept>

Matrice readBMP(const std::string& filename)
{
    unsigned char head[54];
    FILE *f = fopen(filename.c_str(),"rb");
    if(f==NULL)
	throw std::runtime_error( "Impossible d'ouvrir le fichier." );

    // BMP header is 54 bytes
    fread(head, 1, 54, f);

    int w = head[18] + ( ((int)head[19]) << 8) + ( ((int)head[20]) << 16) + ( ((int)head[21]) << 24);
    int h = head[22] + ( ((int)head[23]) << 8) + ( ((int)head[24]) << 16) + ( ((int)head[25]) << 24);

    // lines are aligned on 4-byte boundary
    int lineSize = (w / 8 + (w / 8) % 4);
    int fileSize = lineSize * h;

    unsigned char *img = new unsigned char[w * h];
    unsigned char *data = new unsigned char[fileSize];

    // skip the header
    fseek(f,54,SEEK_SET);

    // skip palette - two rgb quads, 8 bytes
    fseek(f, 8, SEEK_CUR);

    // read data
    fread(data,1,fileSize,f);

    int i, j, k, rev_j;
    for(j = 0, rev_j = h - 1; j < h ; j++, rev_j--) {
        for(i = 0 ; i < w / 8; i++) {
            int fpos = j * lineSize + i, pos = rev_j * w + i * 8;
            for(k = 0 ; k < 8 ; k++)
                img[pos + (7 - k)] = (data[fpos] >> k ) & 1;
        }
    }

    Matrice mat(h,w);
    for(int i=0;i<h*w;i++)
	    mat(i)=img[i];

    delete data;
    delete img;
    fclose(f);

    return mat;
}

