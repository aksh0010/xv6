#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "x86.h"

#define BUFF_SIZE 5

struct FILE
{
    int fd;
    char mode;
    char buffer[BUFF_SIZE];
    int index;
};

struct FILE *myfopen(const char *path, char mode)
{

    int fd;
    if (mode == 'r')
    {
        fd = open(path, O_RDONLY);
    }
    else if (mode == 'w')
    {
        fd = open(path, O_WRONLY | O_CREATE);
    }
    else
    {
        return 0;
    }

    if (fd < 0)
    {
        printf(1, "\nError in myFopen\n");
        return 0;
    }
    struct FILE *fp = (struct FILE *)malloc(sizeof(struct FILE) + 1);
    fp->fd = fd;
    fp->mode = mode;
    fp->index = 0;
    printf(1, "\nThis is from myfopen-->Opened the file succesfully ^_^...\n");
    return fp;
}
void myfclose(struct FILE *fp)
{
    printf(1, "\nThis is from myfclose-->Closing the file now bye ^_^...\n");
    if (fp->mode == 'w')
    {
        write(fp->fd, fp->buffer, fp->index);
    }
    close(fp->fd);
    free(fp);
}

// !!___________________________________________

static void putc(struct FILE *fp, char c)
{
    if ((fp->index) == BUFF_SIZE)
    {
        write(fp->fd, fp->buffer, sizeof(fp->buffer));
        fp->index = 0;
        fp->buffer[fp->index] = c;
        fp->index += 1;
    }
    else
    {

        fp->buffer[fp->index] = c;
        fp->index += 1;
    }
}

static void printint(struct FILE *fp, int xx, int base, int sgn)
{
    static char digits[] = "0123456789ABCDEF";
    char buf[16];
    int i, neg;
    uint x;

    neg = 0;
    if (sgn && xx < 0)
    {
        neg = 1;
        x = -xx;
    }
    else
    {
        x = xx;
    }

    i = 0;
    do
    {
        buf[i++] = digits[x % base];
    } while ((x /= base) != 0);
    if (neg)
        buf[i++] = '-';

    while (--i >= 0)
        putc(fp, buf[i]);
}

// Print to the given fd. Only understands %d, %x, %p, %s.
void myfprintf(struct FILE *fp, const char *fmt, ...)
{
    char *temp;
    int c, i, state;
    uint *ap;

    state = 0;
    ap = (uint *)(void *)&fmt + 1;
    for (i = 0; fmt[i]; i++)
    {
        c = fmt[i] & 0xff;
        if (state == 0)
        {
            if (c == '%')
            {
                state = '%';
            }
            else
            {
                putc(fp, c);
            }
        }
        else if (state == '%')
        {
            if (c == 'd')
            {
                printint(fp, *ap, 10, 1);
                ap++;
            }
            else if (c == 'x' || c == 'p')
            {
                printint(fp, *ap, 16, 0);
                ap++;
            }
            else if (c == 's')
            {
                temp = (char *)*ap;
                ap++;
                if (temp == 0)
                    temp = "(null)";
                while (*temp != 0)
                {
                    putc(fp, *temp);
                    temp++;
                }
            }
            else if (c == 'c')
            {
                putc(fp, *ap);
                ap++;
            }
            else if (c == '%')
            {
                putc(fp, c);
            }
            else
            {
                putc(fp, '%');
                putc(fp, c);
            }
            state = 0;
        }
    }
}
// !! ______________________________________________
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf(1, "\nToo few arguments.It should be like --->> mystdiotest filename.txt \n");
        exit();
    }

    char string[] = "Code has been Developed by : Aksh Patel\n";
    printf(1, "\n\n************************************************************************************************************\n\n");
    printf(1, "\nPlease note that BUFF_SIZE is %d \n", BUFF_SIZE);
    printf(1, "\nDetails Regarding the String are as below : \n--->String :%s--->SIZE of above string = %d", string, strlen(string));

    printf(1, "\n\n-------------------------------Opening (%s) for writing only---------------------------------------------\n\n", argv[1]);
    printf(1, "\nOpening (%s) using myfopen for WRITING only.\nNote, if file is not present it will create the file for you ^_* \n\n", argv[1]);
    struct FILE *fp = myfopen(argv[1], 'w');
    printf(1, "\nUsing myfprintf to write to the  file (%s) which has Write only mode  .. \n", argv[1]);
    myfprintf(fp, "%s", string);
    myfclose(fp);
    printf(1, "\n\n-------------------------------Closing (%s) which was opened for writing only-------------------------------\n\n", argv[1]);

    printf(1, "\n\n-------------------------------Opening (%s) for reading only---------------------------------------------\n\n", argv[1]);
    printf(1, "\nOpening the newly created (%s) using myfopen for READING only.\n\n", argv[1]);
    struct FILE *fp2 = myfopen(argv[1], 'r');

    int n;
    printf(1, "\nPrinting to terminal using write and read combination to prove that it uses BUFFER to store string then calls single write for that buffer.\n\n\n");
    while ((n = read(fp2->fd, fp2->buffer, sizeof(fp2->buffer))) > 0)
    {
        if (write(1, fp2->buffer, n) != n)
        {
            printf(1, "Write error\n");
            exit();
        }
        sleep(100);
    }

    printf(1,"\nThe above line was printed using sleep(), If you missed the effect reading other stuff from top kindly run the program again.\nYou can cat %s to see the output in file \n",argv[1]);
   
    myfclose(fp2);
    printf(1, "\n\n-------------------------------Closing (%s) which was opened for reading only-------------------------------\n\n", argv[1]);
    printf(1, "\n\n************************************************************************************************************\n\n");
    exit();
}