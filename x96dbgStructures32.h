/***********************************************************************
* FILENAME : x64dbgStructures32.h
*
* DESCRIPTION :
*       Loading in x64dbg for windows structure parsing
*
* NOTES :
*       x64dbg was didn't perfectly support 'typedef'.
*       In this code, representatives are only BYTE, WORD, DWORD.
*
*       (c) Copyright by A.N.Other Co. 1990, 1995.  All rights reserved.
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

