#pragma once
class IRecvHandler
{
public:
    virtual void OnRecvFinished() = 0;
};

class CDisplay : public IRecvHandler
{
public:
    CDisplay();
    ~CDisplay();
    void OnRecvFinished();
private:
    int m_data;
};