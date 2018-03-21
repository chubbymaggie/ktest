#include "stdafx.h"

#define DBG_BREAK()  __asm int 3

#ifdef TEST_SUCCESS_BREAK_ON_DBG
#define TEST_SUCCESS_DBG_BREAK() DBG_BREAK()
#else 
#define TEST_SUCCESS_DBG_BREAK()
#endif

#define PROBE_JMP_ALLOC()        \
    __asm nop                    \
    __asm nop                    \
    __asm nop                    \
    __asm nop                    \
    __asm nop                    

#define EXEC_MEASURE_DEFINE()    \
    volatile __int32 h1, l1;     \
    volatile __int32 h2, l2;

#define EXEC_MEASURE_START()     \
    __asm cpuid                  \
    __asm rdtsc                  \
    __asm mov l1, edx            \
    __asm mov h1, eax

#define EXEC_MEASURE_END()       \
    __asm rdtscp                 \
    __asm mov l2, edx            \
    __asm mov h2, eax

#define EXEC_MEASURE_DIFF()      ((((__int64)h2) | (((__int64)l2) << 32)) - (((__int64)h1) | (((__int64)l1) << 32)))

#define BENCHMARK_LOOP           100000

typedef NTSTATUS(*_TestFunction)(IN PUCHAR Buffer, IN ULONG BufferLen);

typedef struct _TEST_ENTRY{
   _TestFunction TestFunction;
   CHAR TestName[64];
   CHAR TestDescription[256];
} TEST_ENTRY, *PTEST_ENTRY;


#define DRILLER_TEST_MAGIC  0x9e3779b9
typedef struct _DRILLER_TEST_CONFIG {
    ULONG Magic;
    CHAR Directive[64];
} DRILLER_TEST_CONFIG, *PDRILLER_TEST_CONFIG;


ULONG
GetTestEntriesCount(
    VOID
    );

PTEST_ENTRY
GetTestEntry(
    IN ULONG Index
    );

ULONG
GetTestEntrySize(
    VOID
    );

NTSTATUS
CounterTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
CleanseTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
CxxTokensTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
FourIndependentBranchesTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
FullCoverageSetTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
MemcmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
NullDerefTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
CmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleCmpTest(
    IN PUCHAR Buffer,
    IN ULONG BufferLen
    );

NTSTATUS
StrcmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
StrncmpTest(
    IN PUCHAR Buffer,
    IN ULONG BufferLen
    );

NTSTATUS
SimpleStrncmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SwitchTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
ShortSwitchTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
LongSwitchTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
FourDependentBranchesTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
AbsNegAndConstantTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
AbsNegAndConstantTest64(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleStrcmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleStrncmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleStricmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleStrnicmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleWcscmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleWcsicmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleWcsncmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleWcsnicmpTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleRtlCompareMemoryTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleRtlCompareStringTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleRtlEqualStringTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleRtlCompareUnicodeStringTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
SimpleRtlEqualUnicodeStringTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
DrillerTest(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
BenchmarkPrimeCalc(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );


NTSTATUS
BenchmarkSha1Calulation(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );


NTSTATUS
BenchmarkAesCalulation(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );


NTSTATUS
BenchmarkMipsEmulation(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );


NTSTATUS
BenchmarkBfCalulation(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );


NTSTATUS
BenchmarkMpeg2Decode(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );

NTSTATUS
RdtscBenchmark(
    IN PUCHAR Buffer,
    IN ULONG  BufferLen
    );


