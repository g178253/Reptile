// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件(这将使得性能优势无效)。

#ifndef PCH_H
#define PCH_H

#include <string>
#include <memory>
#include <iostream>

//************* 以下为 win socket 必须 *************//
// The declarations in the Winsock.h header file will conflict with the declarations
// in the Winsock2.h header file required by Windows Sockets 2.0.
// The WIN32_LEAN_AND_MEAN macro prevents the Winsock.h from being included by the Windows.h header.
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>  // including the Winsock.h header file for Windows Sockets 1.1.
#include <winsock2.h> // includes core elements from the Windows.h header file
#include <ws2tcpip.h> // should be placed before the Iphlpapi.h header file
#include <iphlpapi.h> // IP Helper APIs

#pragma comment(lib, "Ws2_32.lib")

#endif //PCH_H
