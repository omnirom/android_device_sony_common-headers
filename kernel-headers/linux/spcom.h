/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_SPCOM_H_
#define _UAPI_SPCOM_H_
#include <linux/types.h>
#ifndef BIT
#define BIT(x) (1 << x)
#endif
#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif
#define SPCOM_MAX_CHANNELS 0x20
#define SPCOM_CHANNEL_NAME_SIZE 32
#define SPCOM_GET_NEXT_REQUEST_SIZE (PAGE_SIZE - 1)
enum spcom_cmd_id {
  SPCOM_CMD_LOAD_APP = 0x4C4F4144,
  SPCOM_CMD_RESET_SP = 0x52455354,
  SPCOM_CMD_SEND = 0x53454E44,
  SPCOM_CMD_SEND_MODIFIED = 0x534E444D,
  SPCOM_CMD_LOCK_ION_BUF = 0x4C4F434B,
  SPCOM_CMD_UNLOCK_ION_BUF = 0x554C434B,
  SPCOM_CMD_FSSR = 0x46535352,
  SPCOM_CMD_CREATE_CHANNEL = 0x43524554,
};
enum spcom_poll_events {
  SPCOM_POLL_LINK_STATE = BIT(1),
  SPCOM_POLL_CH_CONNECT = BIT(2),
  SPCOM_POLL_READY_FLAG = BIT(14),
  SPCOM_POLL_WAIT_FLAG = BIT(15),
};
struct spcom_user_command {
  enum spcom_cmd_id cmd_id;
  uint32_t arg;
} __packed;
struct spcom_send_command {
  enum spcom_cmd_id cmd_id;
  uint32_t timeout_msec;
  uint32_t buf_size;
  char buf[0];
} __packed;
struct spcom_user_create_channel_command {
  enum spcom_cmd_id cmd_id;
  char ch_name[SPCOM_CHANNEL_NAME_SIZE];
} __packed;
#define SPCOM_MAX_ION_BUF 4
struct spcom_ion_info {
  int32_t fd;
  uint32_t buf_offset;
};
#define SPCOM_ION_FD_UNLOCK_ALL 0xFFFF
struct spcom_ion_handle {
  int32_t fd;
};
struct spcom_user_send_modified_command {
  enum spcom_cmd_id cmd_id;
  struct spcom_ion_info ion_info[SPCOM_MAX_ION_BUF];
  uint32_t timeout_msec;
  uint32_t buf_size;
  char buf[0];
} __packed;
#endif
