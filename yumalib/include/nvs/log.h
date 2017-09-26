//
// Created by pradeep on 9/14/17.
//

#ifndef YUMA_LOG_H
#define YUMA_LOG_H


#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace nvs {

// severity levels
    enum SeverityLevel {
        all, // turn on all logging
        trace,
        debug,
        info,
        warning,
        error,
        fatal,
        off // turn off any logging
    };

// the global logger
    extern boost::log::sources::severity_logger_mt<SeverityLevel> logger;

    extern bool log_initialized;

// initialize the logger
    void init_log(SeverityLevel level);

    void init_log(SeverityLevel level, std::string file_name);

#ifdef DEBUG
#define LOG(severity) \
    BOOST_LOG_SEV(logger, severity) << "(" << __FILE__ << ":" << __LINE__ << ") "

#define TRACE() \
    BOOST_LOG_SEV(logger, trace) << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
#else
#define LOG(severity) if(0)std::cerr
#define TRACE() {}
#endif
}
#endif //YUMA_LOG_H
