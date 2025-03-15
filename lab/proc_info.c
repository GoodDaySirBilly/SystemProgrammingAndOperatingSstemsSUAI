#include <stdio.h>

int main() {
    unsigned int eax, ebx, ecx, edx, al;
    char vendor[13];

    __asm__ volatile (
        "cpuid"
        : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
        : "a"(0)
    );

    printf("Number of functions: %u\n",eax);

    __asm__ volatile (
        "cpuid"
        : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
        : "a"(1)
    );



    // Извлекаем семейство, модель и степпинг процессора из регистра EAX
    unsigned int family = (eax >> 8) & 0xF;
    unsigned int model = (eax >> 4) & 0xF;  

    printf("Семейство: %u, Модель: %u\n", family, model);

    printf("Поддерживаемые технологии: \n");
    
    // Проверяем биты в регистрах EDX и ECX, указывающие на поддержку технологий
    if (edx & (1 << 0)) printf("- FPU\n");
    if (edx & (1 << 1)) printf("- VME\n");
    if (edx & (1 << 2)) printf("- DE\n");
    if (edx & (1 << 3)) printf("- PSE\n");
    if (edx & (1 << 4)) printf("- TSC\n");
    if (edx & (1 << 5)) printf("- MSR\n");
    if (edx & (1 << 6)) printf("- PAE\n");
    if (edx & (1 << 7)) printf("- MCE\n");
    if (edx & (1 << 8)) printf("- CXB\n");
    if (edx & (1 << 9)) printf("- APIC\n");
    if (edx & (1 << 11)) printf("- SEP\n");
    if (edx & (1 << 12)) printf("- MTRR\n");
    if (edx & (1 << 13)) printf("- PGE\n");
    if (edx & (1 << 14)) printf("- MCA\n");
    if (edx & (1 << 15)) printf("- CMOV\n");
    if (edx & (1 << 16)) printf("- PAT\n");
    if (edx & (1 << 17)) printf("- PSE-36\n");
    if (edx & (1 << 18)) printf("- PSN\n");
    if (edx & (1 << 19)) printf("- CLESH\n");
    if (edx & (1 << 21)) printf("- DS\n");
    if (edx & (1 << 22)) printf("- ACPI\n");
    if (edx & (1 << 23)) printf("- MMX\n");
    if (edx & (1 << 24)) printf("- FXRSTOR EXRSAVE\n");
    if (edx & (1 << 25)) printf("- SSE\n");
    if (edx & (1 << 26)) printf("- SSE2\n");
    if (edx & (1 << 27)) printf("- SS\n");
    if (edx & (1 << 29)) printf("- TM\n");
    if (ecx & (1 << 0)) printf("- SSE3\n");            
    if (ecx & (1 << 9)) printf("- SSSE3\n");          
    if (ecx & (1 << 19)) printf("- SSE4.1\n");         
    if (ecx & (1 << 20)) printf("- SSE4.2\n");         
    if (ecx & (1 << 28)) printf("- AVX\n");            
    return 0;
}

