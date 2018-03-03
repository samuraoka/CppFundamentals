#include "stdafx.h"

// Chapter 1. Boost.Log v2
// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/index.html

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

void init()
{
	boost::shared_ptr< logging::core > core = logging::core::get();
	core->add_global_attribute("TimeStamp", attrs::local_clock());

	logging::add_file_log(
		keywords::file_name = "sample_%N.log",
		keywords::rotation_size = 10 * 1024 * 1024,
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
		keywords::format = "[%TimeStamp%]: %Message%"
	);
	logging::add_console_log(
		std::cout,
		keywords::format = "[%TimeStamp%]: %Message%"
	);

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::info
	);
}

int main()
{
	init();

	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

	return 0;
}
