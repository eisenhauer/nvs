#include <nvs/log.h>
#include "log.h"

namespace nvs{

    Log::Log(std::string logPath, PoolId pool_id)
            :logPath(logPath),pool_id_(pool_id)
    {
    }

    Log::~Log()
    {
        assert(false);
    }

    ErrorCode Log::Open() {
        lp = pmemlog_open(this->logPath.c_str());
        if(lp == NULL){ return OPEN_FAILED;}

        return NO_ERROR;
    }


    ErrorCode Log::Create(size_t log_size) {
           lp = pmemlog_create(this->logPath.c_str(), log_size, 0666);
           if (lp == NULL){
               // log already exist
               LOG(error) << "log already exist";
               return LOG_EXIST;
           }
        return NO_ERROR;
    }


    ErrorCode Log::Close() {
        pmemlog_close(lp);
        return NO_ERROR;
    }

    ErrorCode Log::append(char *data, size_t size) {

        int ret = pmemlog_append(lp, data, size);
        if(ret<0){
            return PMEM_ERROR;
        }
        return NO_ERROR;
    }

    ErrorCode Log::appendv(struct iovec *iovp, int iovcnt) {

        int ret = pmemlog_appendv(lp,iovp, iovcnt);
        if(ret < 0){
            return PMEM_ERROR;
        }
        return NO_ERROR;
    }

    ErrorCode Log::metaWalk() {

    }



}

