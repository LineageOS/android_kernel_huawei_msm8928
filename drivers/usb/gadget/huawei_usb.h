
#ifndef __HUAWEI_USB_H__
#define __HUAWEI_USB_H__

/* support 3 luns at most, 1 lun for cdrom and 2 luns for udisk */
#define USB_MAX_LUNS       3

#define SC_REWIND          0x01
#define SC_REWIND_11       0x11

#define ORI_INDEX         0

/* READ_TOC command structure */
typedef struct _usbsdms_read_toc_cmd_type
{
   u8  op_code;  
   u8  msf;             /* bit1 is MSF, 0: address format is LBA form
                                        1: address format is MSF form */
   u8  format;          /* bit3~bit0,   MSF Field   Track/Session Number
                           0000b:       Valid       Valid as a Track Number
                           0001b:       Valid       Ignored by Drive
                           0010b:       Ignored     Valid as a Session Number
                           0011b~0101b: Ignored     Ignored by Drive
                           0110b~1111b: Reserved
                        */
   u8  reserved1;  
   u8  reserved2;  
   u8  reserved3;  
   u8  session_num;     /* a specific session or a track */
   u8  allocation_length_msb;
   u8  allocation_length_lsb;
   u8  control;
} usbsdms_read_toc_cmd_type;
