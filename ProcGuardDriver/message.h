#pragma once

#include "mydef.h"

#include <ntifs.h>

#define MSG_STATUS_PENDING 0
#define MSG_STATUS_ABANDONED 1
#define MSG_STATUS_CONFIRMED 2

#define MSG_CONFIRMED(_MsgListEntry) \
	((_MsgListEntry)->Status == MSG_STATUS_CONFIRMED)

#define MSG_PENDING(_MsgListEntry) \
	((_MsgListEntry)->Status == MSG_STATUS_PENDING)

#pragma pack(1)
typedef struct _MY_MSG_LIST_ENTRY {
	LIST_ENTRY Links;
	KEVENT Event;
	ULONG Pid;
	UNICODE_STRING Filename;
	USHORT Status;
} MY_MSG_LIST_ENTRY, *PMY_MSG_LIST_ENTRY;
#pragma pack()

NTSTATUS
initMsgListEntry(
	PMY_MSG_LIST_ENTRY ListEntry,
	PUNICODE_STRING Filename
	);

NTSTATUS
freeMsgListEntry(
	PMY_MSG_LIST_ENTRY ListEntry
	);

NTSTATUS
freeAllMsgs();

PMY_MSG_LIST_ENTRY
findMsgByEvent(
	PKEVENT Event
	);

PKEVENT
getNewMsgEvent();

BOOLEAN
isMsgListEmpty();

PMY_MSG_LIST_ENTRY
queryMsgListFirst();

VOID
setProcessIdOffset(
	ULONG Offset
	);
