/***********************************************************************
* FILENAME : x64dbgStructures32.h
*
* DESCRIPTION :
*       Loading in x64dbg for windows structure parsing
*
* NOTES :
*       x96dbg was didn't perfectly support 'typedef'.
*       In this code, representatives are only BYTE, WORD, DWORD.
*
* AUTHOR : @FullStackRCE        START DATE : 23 Feb 2022
*
**/
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

//#include <sysinfoapi.h>
struct _DUMMYSTRUCTNAME
{
    WORD wProcessorArchitecture;
    WORD wReserved;
};
//https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
struct SYSTEM_INFO {
  _DUMMYSTRUCTNAME dummystrctname;
  DWORD     dwPageSize;
  DWORD     lpMinimumApplicationAddress;
  DWORD     lpMaximumApplicationAddress;
  DWORD     dwActiveProcessorMask;
  DWORD     dwNumberOfProcessors;
  DWORD     dwProcessorType;
  DWORD     dwAllocationGranularity;
  WORD      wProcessorLevel;
  WORD      wProcessorRevision;
};
//#include <wincrypt.h>
//https://docs.microsoft.com/en-us/windows/win32/api/wincrypt/ns-wincrypt-publickeystruc
struct _PUBLICKEYSTRUC {
  BYTE   bType;         // #define PUBLICKEYBLOB           0x6
  BYTE   bVersion;
  WORD   reserved;      // #define CALG_RSA_KEYX           0x0000a400(ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
  DWORD  aiKeyAlg;
};
//https://docs.microsoft.com/en-us/windows/win32/api/wincrypt/ns-wincrypt-rsapubkey
struct _RSAPUBKEY {
  DWORD magic;
  DWORD bitlen;
  DWORD pubexp;
};
//https://docs.microsoft.com/en-us/windows/win32/seccrypto/base-provider-key-blobs
struct PUBLICKEYBLOB {
  _PUBLICKEYSTRUC  publickeystruc;
  _RSAPUBKEY rsapubkey;
  BYTE key[200];  //BYTE[_RSAPUBKEY.bitlen/8]; Oringinally, it's a relative value, but x64dbg not support.
};

//to be validation, it's not test on x96dbg
/*
struct TEB {
	int32  seh;
	int  member0x04;
	int  member0x08;
	int  member0x0c;
	int  member0x10;
	int  member0x14;
	TEB*  TEB;
	int  member0x1c;
	DWORD  PID;
	DWORD  TID;
	int  member0x28;
	int  member0x2c;
	PEB*  PEB;
	DWORD  LastErrorValue;
};
struct PEB {
	int16  member0x00;
	BYTE  BeingDebugged;
	int8  member0x03;
	int32  member0x04;;
	void*  ImageBaseAddress;
	PEB_LDR_DATA*  Ldr;
	int  member0x10;
	int  member0x14;
	void*  ProcessHeap;
	int  member0x1c;
	int  member0x20;
	int  member0x24;
	int  member0x28;
	int  member0x2c;
	int  member0x30;
	int  member0x34;
	int  member0x38;
	int  member0x3c;
	int  member0x40;
	int  member0x44;
	int  member0x48;
	int  member0x4c;
	int  member0x50;
	int  member0x54;
	int  member0x58;
	int  member0x5c;
	int  member0x60;
	DWORD  NumberOfProcessors;
	DWORD  NtGlobalFlag;
};
struct PEB_LDR_DATA {
	int  member0x00;
	int  member0x04;
	int  member0x08;
	Load_Module*  InLoadOrderModuleList;
	int  member0x10;
	Memory_Module*  InMemoryOrderModuleList;
	int  member0x18;
	Init_Module*  InInitializationOrderModuleList;
};
struct Load_Module {
	Load_Module*  NextModule;
	Load_Module*  PreviousModule;
	int  member0x08;
	int  member0x0c;
	int  member0x10;
	int  member0x14;
	int32  ImgBase;
	int32  EntryPoint;
	int32  SizeOfImg;
	int  member0x24;
	int  member0x28;
	int  member0x2c;
	wchar_t*  name;
};
struct Memory_Module {
	Memory_Module*  NextModule;
	Memory_Module*  PreviousModule;
	int  member0x08;
	int  member0x0c;
	int32  ImgBase;
	int32  EntryPoint;
	int32  SizeOfImg;
	int  member0x1c;
	wchar_t*  Path;
};


struct Init_Module {
	Init_Module*  NextModule;
	Init_Module*  PreviousModule;
	int32  ImgBase;
	int32  EntryPoint;
	int32  SizeOfImg;
	int  member0x14;
	int  member0x18;
	int  member0x1c;
	wchar_t*  name;
};
truct FLOATING_SAVE_AREA
{
    DWORD   ControlWord;
    DWORD   StatusWord;
    DWORD   TagWord;
    DWORD   ErrorOffset;
    DWORD   ErrorSelector;
    DWORD   DataOffset;
    DWORD   DataSelector;
    BYTE    RegisterArea[80]; //[SIZE_OF_80387_REGISTERS];
    DWORD   Spare0;
};
struct CONTEXT
{

    DWORD ContextFlags;

    DWORD   Dr0;
    DWORD   Dr1;
    DWORD   Dr2;
    DWORD   Dr3;
    DWORD   Dr6;
    DWORD   Dr7;

    FLOATING_SAVE_AREA FloatSave;

    DWORD   SegGs;
    DWORD   SegFs;
    DWORD   SegEs;
    DWORD   SegDs;

    DWORD   Edi;
    DWORD   Esi;
    DWORD   Ebx;
    DWORD   Edx;
    DWORD   Ecx;
    DWORD   Eax;

    DWORD   Ebp;
    DWORD   Eip;
    DWORD   SegCs;              // MUST BE SANITIZED
    DWORD   EFlags;             // MUST BE SANITIZED
    DWORD   Esp;
    DWORD   SegSs;

    BYTE    ExtendedRegisters[512]; //[MAXIMUM_SUPPORTED_EXTENSION];

};
*/