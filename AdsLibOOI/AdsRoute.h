#pragma once
#include "AdsException.h"
#include "AdsHandle.h"
#include "AdsLib/AdsDef.h"

struct AdsRoute {
    AdsRoute(const std::string& ipV4, AmsNetId netId, uint16_t port);

    AdsHandle GetHandle(uint32_t offset) const;
    AdsHandle GetHandle(const std::string& symbolName) const;

    long GetLocalPort() const;
    void SetTimeout(const uint32_t timeout) const;
    uint32_t GetTimeout() const;

    const std::shared_ptr<const AmsNetId> m_NetId;
    const AmsAddr m_Addr;

    long ReadReqEx2(uint32_t group, uint32_t offset, uint32_t length, void* buffer, uint32_t* bytesRead) const;
    long ReadWriteReqEx2(uint32_t    indexGroup,
                         uint32_t    indexOffset,
                         uint32_t    readLength,
                         void*       readData,
                         uint32_t    writeLength,
                         const void* writeData,
                         uint32_t*   bytesRead) const;
    long WriteReqEx(uint32_t group, uint32_t offset, uint32_t length, const void* buffer) const;
private:
    std::shared_ptr<long> m_LocalPort;
};
