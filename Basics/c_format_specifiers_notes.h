#ifndef C_FORMAT_SPECIFIERS_NOTES_H
#define C_FORMAT_SPECIFIERS_NOTES_H

/*
=====================================================================
C DATENTYPEN, FORMAT SPECIFIER, BYTES UND WERTEBEREICHE
=====================================================================

Diese Datei ist nur als Lern-Notiz gedacht.
Du kannst sie in dein Repository kopieren und bei Bedarf öffnen.

WICHTIG:
- printf() gibt Werte aus.
- scanf() liest Werte ein.

Beispiel:
    int x;
    scanf("%d", &x);     // Eingabe
    printf("%d", x);     // Ausgabe

Bei scanf() braucht man fast immer die Adresse mit &:
    scanf("%d", &x);

Ausnahme:
    char name[20];
    scanf("%19s", name); // kein &, weil Arrayname schon Adresse ist

Die genaue Größe eines Datentyps kann je nach Compiler/System anders sein.
Typisch auf vielen PCs mit GCC:

    char        = 1 Byte
    short       = 2 Bytes
    int         = 4 Bytes
    long        = 4 oder 8 Bytes
    long long   = 8 Bytes
    float       = 4 Bytes
    double      = 8 Bytes
    long double = 8, 12 oder 16 Bytes

Mit sizeof() kannst du die echte Größe auf deinem System prüfen:

    printf("%zu\n", sizeof(int));

1 Byte = 8 Bit

=====================================================================
SIGNED INTEGER TYPES
=====================================================================

signed char
---------------------------------------------------------------------
Größe: meistens 1 Byte
Bits: 8 Bit
Wertebereich meistens: -128 bis 127

scanf:
    signed char x;
    scanf("%hhd", &x);

printf:
    printf("%hhd", x);


unsigned char
---------------------------------------------------------------------
Größe: meistens 1 Byte
Bits: 8 Bit
Wertebereich meistens: 0 bis 255
Hex-Bereich: 0x00 bis 0xFF

scanf dezimal:
    unsigned char x;
    scanf("%hhu", &x);

printf dezimal:
    printf("%hhu", x);

scanf hexadezimal:
    scanf("%hhx", &x);

printf hexadezimal:
    printf("0x%02hhX", x);


short / signed short
---------------------------------------------------------------------
Größe: meistens 2 Bytes
Bits: 16 Bit
Wertebereich meistens: -32768 bis 32767

scanf:
    short x;
    scanf("%hd", &x);

printf:
    printf("%hd", x);


unsigned short
---------------------------------------------------------------------
Größe: meistens 2 Bytes
Bits: 16 Bit
Wertebereich meistens: 0 bis 65535
Hex-Bereich: 0x0000 bis 0xFFFF

scanf dezimal:
    unsigned short x;
    scanf("%hu", &x);

printf dezimal:
    printf("%hu", x);

scanf hexadezimal:
    scanf("%hx", &x);

printf hexadezimal:
    printf("0x%04hX", x);


int / signed int
---------------------------------------------------------------------
Größe: meistens 4 Bytes
Bits: 32 Bit
Wertebereich meistens: -2147483648 bis 2147483647

scanf:
    int x;
    scanf("%d", &x);

printf:
    printf("%d", x);

Alternative:
    scanf("%i", &x);
    printf("%i", x);

Unterschied bei scanf:
    %d liest dezimal.
    %i erkennt automatisch dezimal, oktal und hexadezimal.

Beispiele mit scanf("%i", &x):
    10      -> dezimal 10
    010     -> oktal 8
    0x10    -> hexadezimal 16


unsigned int
---------------------------------------------------------------------
Größe: meistens 4 Bytes
Bits: 32 Bit
Wertebereich meistens: 0 bis 4294967295
Hex-Bereich: 0x00000000 bis 0xFFFFFFFF

scanf dezimal:
    unsigned int x;
    scanf("%u", &x);

printf dezimal:
    printf("%u", x);

scanf hexadezimal:
    scanf("%x", &x);

printf hexadezimal:
    printf("0x%08X", x);


long / signed long
---------------------------------------------------------------------
Größe:
    Windows 64-bit: meistens 4 Bytes
    Linux 64-bit: meistens 8 Bytes

Wertebereich bei 4 Bytes:
    -2147483648 bis 2147483647

Wertebereich bei 8 Bytes:
    -9223372036854775808 bis 9223372036854775807

scanf:
    long x;
    scanf("%ld", &x);

printf:
    printf("%ld", x);


unsigned long
---------------------------------------------------------------------
Größe:
    Windows 64-bit: meistens 4 Bytes
    Linux 64-bit: meistens 8 Bytes

Wertebereich bei 4 Bytes:
    0 bis 4294967295

Wertebereich bei 8 Bytes:
    0 bis 18446744073709551615

scanf dezimal:
    unsigned long x;
    scanf("%lu", &x);

printf dezimal:
    printf("%lu", x);

scanf hexadezimal:
    scanf("%lx", &x);

printf hexadezimal:
    printf("0x%lX", x);


long long / signed long long
---------------------------------------------------------------------
Größe: meistens 8 Bytes
Bits: 64 Bit
Wertebereich meistens:
    -9223372036854775808 bis 9223372036854775807

scanf:
    long long x;
    scanf("%lld", &x);

printf:
    printf("%lld", x);


unsigned long long
---------------------------------------------------------------------
Größe: meistens 8 Bytes
Bits: 64 Bit
Wertebereich meistens:
    0 bis 18446744073709551615

Hex-Bereich:
    0x0000000000000000 bis 0xFFFFFFFFFFFFFFFF

scanf dezimal:
    unsigned long long x;
    scanf("%llu", &x);

printf dezimal:
    printf("%llu", x);

scanf hexadezimal:
    scanf("%llx", &x);

printf hexadezimal:
    printf("0x%016llX", x);

=====================================================================
CHAR UND STRING
=====================================================================

char
---------------------------------------------------------------------
Größe: 1 Byte
Speichert ein Zeichen, z.B. 'A'

scanf:
    char c;
    scanf(" %c", &c);

printf:
    printf("%c", c);

Wichtig:
    Das Leerzeichen vor %c in scanf ist oft sinnvoll:
        scanf(" %c", &c);
    Es ignoriert vorherige Enter-Zeichen.


char array / string
---------------------------------------------------------------------
Beispiel:
    char name[20];

Größe:
    20 Bytes, weil jedes char 1 Byte hat.

scanf:
    scanf("%19s", name);

printf:
    printf("%s", name);

Warum %19s?
    name[20] hat Platz für 19 Zeichen + '\0'.

Wichtig:
    Ein String braucht am Ende '\0'.

Beispiel:
    char text[6] = "omar";

Speicher:
    'o' 'm' 'a' 'r' '\0'

Obwohl "omar" nur 4 Zeichen hat, braucht es 5 Bytes.

Falsch:
    char name[20];
    scanf("%s", name);      // gefährlich, wenn Eingabe zu lang ist

Besser:
    scanf("%19s", name);

=====================================================================
FLOATING POINT TYPES
=====================================================================

float
---------------------------------------------------------------------
Größe: meistens 4 Bytes

scanf:
    float x;
    scanf("%f", &x);

printf:
    printf("%f", x);

Beispiel:
    float x = 3.14f;
    printf("%f", x);


double
---------------------------------------------------------------------
Größe: meistens 8 Bytes

scanf:
    double x;
    scanf("%lf", &x);

printf:
    printf("%f", x);

Wichtig:
    Bei scanf für double: %lf
    Bei printf für double: %f


long double
---------------------------------------------------------------------
Größe: meistens 8, 12 oder 16 Bytes

scanf:
    long double x;
    scanf("%Lf", &x);

printf:
    printf("%Lf", x);


Ausgabe-Formate für floating point:
---------------------------------------------------------------------
%f      normale Kommazahl
%e      wissenschaftliche Schreibweise klein
%E      wissenschaftliche Schreibweise groß
%g      automatisch %f oder %e
%G      automatisch %f oder %E

Beispiele:
    double x = 1234.5678;

    printf("%f", x);      // 1234.567800
    printf("%.2f", x);    // 1234.57
    printf("%e", x);      // 1.234568e+03
    printf("%E", x);      // 1.234568E+03
    printf("%g", x);      // kurze Darstellung

=====================================================================
POINTER
=====================================================================

Pointer, z.B. int *
---------------------------------------------------------------------
Größe:
    32-bit System: 4 Bytes
    64-bit System: 8 Bytes

Beispiel:
    int x = 10;
    int *ptr = &x;

printf:
    printf("%p", (void *)ptr);

Wichtig:
    Für Pointer-Ausgabe benutzt man %p.
    Man castet meistens zu void *:
        printf("%p", (void *)ptr);

=====================================================================
FORMATIERUNG BEI printf
=====================================================================

%d      normale signed int Ausgabe
%5d     mindestens 5 Zeichen breit
%05d    mindestens 5 Zeichen breit, mit Nullen auffüllen
%.2f    2 Nachkommastellen
%8.2f   insgesamt 8 Zeichen breit, 2 Nachkommastellen

Beispiele:
    int x = 42;

    printf("%d", x);      // 42
    printf("%5d", x);     //    42
    printf("%05d", x);    // 00042

    double y = 3.14159;

    printf("%f", y);      // 3.141590
    printf("%.2f", y);    // 3.14
    printf("%8.2f", y);   //     3.14

=====================================================================
HEX-AUSGABE MIT FESTER BREITE
=====================================================================

unsigned char:
    unsigned char x = 0x5A;
    printf("0x%02hhX", x);

Ausgabe:
    0x5A

unsigned short:
    unsigned short x = 0x1234;
    printf("0x%04hX", x);

Ausgabe:
    0x1234

unsigned int:
    unsigned int x = 0x12345678;
    printf("0x%08X", x);

Ausgabe:
    0x12345678

unsigned long long:
    unsigned long long x = 0x123456789ABCDEF0;
    printf("0x%016llX", x);

Ausgabe:
    0x123456789ABCDEF0

=====================================================================
KURZE ÜBERSICHT: SIGNED
=====================================================================

Datentyp              Größe meistens      scanf        printf
---------------------------------------------------------------------
signed char           1 Byte              %hhd         %hhd
signed short          2 Bytes             %hd          %hd
signed int            4 Bytes             %d           %d
signed long           4 oder 8 Bytes       %ld          %ld
signed long long      8 Bytes             %lld         %lld

=====================================================================
KURZE ÜBERSICHT: UNSIGNED
=====================================================================

Datentyp              Größe meistens      scanf        printf
---------------------------------------------------------------------
unsigned char         1 Byte              %hhu         %hhu
unsigned short        2 Bytes             %hu          %hu
unsigned int          4 Bytes             %u           %u
unsigned long         4 oder 8 Bytes       %lu          %lu
unsigned long long    8 Bytes             %llu         %llu

=====================================================================
KURZE ÜBERSICHT: HEXADEZIMAL
=====================================================================

Datentyp              Größe meistens      scanf        printf
---------------------------------------------------------------------
unsigned char         1 Byte              %hhx         0x%02hhX
unsigned short        2 Bytes             %hx          0x%04hX
unsigned int          4 Bytes             %x           0x%08X
unsigned long         4 oder 8 Bytes       %lx          0x%lX
unsigned long long    8 Bytes             %llx         0x%016llX

=====================================================================
KURZE ÜBERSICHT: CHAR, STRING, FLOAT, POINTER
=====================================================================

Datentyp              Größe meistens      scanf        printf
---------------------------------------------------------------------
char                  1 Byte              %c           %c
string char[]         Anzahl chars         %s           %s
float                 4 Bytes             %f           %f
double                8 Bytes             %lf          %f
long double           8/12/16 Bytes        %Lf          %Lf
pointer               4 oder 8 Bytes       -            %p

=====================================================================
HÄUFIGE FEHLER
=====================================================================

Falsch:
    unsigned int x;
    scanf("%d", &x);

Richtig:
    unsigned int x;
    scanf("%u", &x);


Falsch:
    unsigned char x;
    scanf("%u", &x);

Richtig:
    unsigned char x;
    scanf("%hhu", &x);


Falsch:
    unsigned short x;
    scanf("%u", &x);

Richtig:
    unsigned short x;
    scanf("%hu", &x);


Falsch:
    char name[20];
    scanf("%s", &name);

Richtig:
    char name[20];
    scanf("%19s", name);


Falsch:
    int x;
    printf("%u", x);

Richtig:
    int x;
    printf("%d", x);


Falsch:
    unsigned int x;
    printf("%d", x);

Richtig:
    unsigned int x;
    printf("%u", x);


Falsch:
    unsigned int x;
    scanf("%iu", &x);

Richtig:
    unsigned int x;
    scanf("%u", &x);

=====================================================================
WICHTIGE HEADER FÜR EXAKTE GRENZEN
=====================================================================

Für Wertebereiche:
    #include <limits.h>
    #include <float.h>

Beispiele:
    CHAR_MIN
    CHAR_MAX
    UCHAR_MAX
    SHRT_MIN
    SHRT_MAX
    USHRT_MAX
    INT_MIN
    INT_MAX
    UINT_MAX
    LONG_MIN
    LONG_MAX
    ULONG_MAX

Für feste Integer-Größen:
    #include <stdint.h>

Beispiele:
    int8_t      -128 bis 127
    uint8_t     0 bis 255
    int16_t     -32768 bis 32767
    uint16_t    0 bis 65535
    int32_t     -2147483648 bis 2147483647
    uint32_t    0 bis 4294967295
    int64_t     64-Bit signed integer
    uint64_t    64-Bit unsigned integer

=====================================================================
sizeof() TESTPROGRAMM
=====================================================================

#include <stdio.h>

int main(void) {
    printf("char: %zu Byte\n", sizeof(char));
    printf("short: %zu Bytes\n", sizeof(short));
    printf("int: %zu Bytes\n", sizeof(int));
    printf("long: %zu Bytes\n", sizeof(long));
    printf("long long: %zu Bytes\n", sizeof(long long));
    printf("float: %zu Bytes\n", sizeof(float));
    printf("double: %zu Bytes\n", sizeof(double));
    printf("long double: %zu Bytes\n", sizeof(long double));
    printf("pointer: %zu Bytes\n", sizeof(void *));

    return 0;
}

=====================================================================
MERKSATZ
=====================================================================

d  = signed decimal int
u  = unsigned decimal int
x  = hexadecimal klein
X  = hexadecimal groß
o  = octal
c  = character
s  = string
f  = float/double decimal
p  = pointer address

h  = short
hh = char
l  = long oder double bei scanf
ll = long long
L  = long double

Beispiele:
    %d      int
    %u      unsigned int
    %hd     short
    %hu     unsigned short
    %hhd    signed char
    %hhu    unsigned char
    %ld     long
    %lu     unsigned long
    %lld    long long
    %llu    unsigned long long

=====================================================================
MINI-TABELLE FÜR EMBEDDED C
=====================================================================

unsigned char  = 1 Byte  = 8 Bit   -> 0 bis 255
unsigned short = 2 Bytes = 16 Bit  -> 0 bis 65535
unsigned int   = 4 Bytes = 32 Bit  -> 0 bis 4294967295

signed char    = 1 Byte  = 8 Bit   -> -128 bis 127
signed short   = 2 Bytes = 16 Bit  -> -32768 bis 32767
signed int     = 4 Bytes = 32 Bit  -> -2147483648 bis 2147483647

=====================================================================
*/

#endif /* C_FORMAT_SPECIFIERS_NOTES_H */
