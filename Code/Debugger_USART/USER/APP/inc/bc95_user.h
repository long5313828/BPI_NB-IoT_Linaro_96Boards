#ifndef _BC95_USER_H
#define _BC95_USER_H

#include "stm32f10x.h"


#define REQUEST_MANUFACTURER_IDENTIFICATION     "AT+CGMI\r\n"       //���������̱�ʶ
#define REQUEST_MANUFACTURER_MODLE              "AT+CGMM\r\n"       //�����������ͺ�
#define REQUEST_MANUFACTURER_REVISION           "AT+CGMR\r\n"       //�����������޶�
#define REQUEST_PRODUCT_SERIAL_NUMBER           "AT+CGSN"           //�����Ʒ���к� Ps:"AT+CGSN=1"����IMEI "AT+CGSN=2"����IMEISV "AT+CGSN=3"����SVN����汾��



#endif // !_BC95_USER_H
