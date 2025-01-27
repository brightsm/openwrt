

#define	ZTE_VENDOR_ID			0x19D2
#define ZTE_PRODUCT_MF626		0x0001
#define ZTE_PCIE_M6             0x0016
#define ZTE_PCIE_M6RUN          0x0031
#define ZTE_PRODUCT_AMSS6290    0x0043
#define ZTE_PRODUCT_P650        0x0003  //added by zhengxin 090216 for TD Modem PID

#define ZTE_EVB_OSE_DOWNLOAD_MODE // add by lirui  for EVB_OSE_DOWNLOAD_MODE_SUPPORT 20120405

/*the sequence of interface modified by renbin because ralink usb host driver 09-03-14*/
typedef enum modem_Interface{
    DIAGE_INF = 0,       /*ttyUSB0*/
    AT_INF,              /*ttyUSB1*/
    VOUSB_INF,           /*PCM_USB*/
    MODEM_INF,           /*ttyUSB3*/
    #ifdef ZTE_EVB_OSE_DOWNLOAD_MODE
    DOWNLOAD_INF,   /*ttyUSB4*/
    #endif
    MAX_USEFUL_INF_NUM,  /* follow interface not support */
    NDIS_INF,
    SMART_CARD_INF,
    NMEAEXT_INF,
    MMC_INF,
    CDROM_INF,
    DVBH_INF,
    DVBH_TV_INF,
    MS_INF,
	ADB_INF,
}MODEM_INTERFACE;

typedef struct modem_data {
    struct usb_device_id    modem_id;
    unsigned char    Interface[16];
    unsigned char    name[64];
}MODEM_DATA;

//add by maxl 
typedef struct  stModem_type {
	unsigned short 		idVendor;
	unsigned short 		idProduct;
	char                             mode[32];
	char                             company[32];
	char                             info[64];
}MODEM_TYPE;


