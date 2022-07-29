/* Select non-standard functionality using GCC on UNIX/ELKS platforms */

#ifndef __UNIX_H
#define __UNIX_H

/* video output options */
#define VIDEO_FB    1   /* output to internal framebuffer, then translate */
#define VIDEO_EGA   0   /* direct output to hardware EGA */

#define near

#if VIDEO_EGA
#define far             __far
#define FP_OFF(fp)      ((unsigned)(unsigned long)(void __far *)(fp))
#define FP_SEG(fp)      ((unsigned)((unsigned long)(void __far *)(fp) >> 16))
#define MK_FP(seg,off)  ((void __far *)((((unsigned long)(seg)) << 16) | (off)))
#define poke(s,o,w)     (*((unsigned short __far*)MK_FP((s),(o))) = (w))
#define peek(s,o)       (*((unsigned short __far*)MK_FP((s),(o))))

void fmemcpyb(unsigned dst_off, unsigned dst_seg, unsigned src_off,
    unsigned src_seg, unsigned count);
/*void movedata(unsigned srcseg, unsigned srcoff, unsigned dstseg, unsigned dstoff,
                unsigned n);*/
#define movedata(ss,so,ds,do,n) fmemcpyb(do,ds,so,ss,n)
#endif /* VIDEO_EGA */

#if VIDEO_FB
#define far
#define poke(a,o,w)     (*((unsigned short *)((char *)(a)+(o))) = (w))
#define peek(a,o)       (*((unsigned short *)((char *)(a)+(o))))
extern unsigned short kCp437[256];
void convert_screen_to_ansi(void);
#endif

/* max() and min() may come from <stdlib.h> */
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define min(a,b)        (((a) < (b)) ? (a) : (b))

#if 0
#define WILDCARDS 0x01
#define EXTENSION 0x02
#define FILENAME  0x04
#define DIRECTORY 0x08
#define DRIVE     0x10
#endif

#if ELKS //FIXME
#define mktime(t)
#define strftime(f,...)
#endif

#endif
