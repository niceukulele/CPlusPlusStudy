#include "stdafx.h"

CDisplay::CDisplay()
{
    m_data = 10;
}
#if 1
void CDisplay::OnRecvFinished()
{
    m_data++;
    printf("%d\n", m_data);
}
#endif