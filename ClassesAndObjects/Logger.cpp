#include "stdafx.h"
#include "Logger.h"

Logger Logger::singleton;

Logger::Logger() : logger()
{
	auto core = boost::log::core::get();

	// Wide character logging 
	std::wcout.imbue(std::locale("ja"));

	// Create a backend and attach a couple of streams to is
	auto backend = boost::make_shared<boost::log::sinks::wtext_ostream_backend>();
	backend->add_stream(boost::shared_ptr<std::wostream>(&std::wcout, boost::null_deleter()));

	// Enable auto-flushing after each log record written
	backend->auto_flush(true);

	// Wrap it into the front end
	typedef boost::log::sinks::synchronous_sink<boost::log::sinks::wtext_ostream_backend> sink_t;
	boost::shared_ptr<sink_t> sink(new sink_t(backend));

	// Register in the core
	core->add_sink(sink);
}

Logger::~Logger()
{
}

boost::log::sources::wseverity_logger<severity_level> &Logger::getLogger()
{
	return Logger::singleton.logger;
}
