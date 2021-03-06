#include "stdafx.h"

// Chapter 1. Boost.Log v2
// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/index.html

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

enum severity_level
{
	trace,
	debug,
	info,
	warning,
	error,
	fatal
};

BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(scope, "Scope", attrs::named_scope::value_type)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime)

void init()
{
	// Design overview 
	// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/log/design.html
	//
	// Sink frontends 
	// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/log/detailed/sink_frontends.html
	//
	// Text stream backend 
	// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/log/detailed/sink_backends.html#log.detailed.sink_backends.text_ostream

	auto core = logging::core::get();

	// Wide character logging 
	// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/log/tutorial/wide_char.html
	std::wcout.imbue(std::locale("ja"));
	auto wfout = boost::shared_ptr<std::wostream>(new std::wofstream("sample.log"));
	wfout.get()->imbue(std::locale("ja"));

	// Create a backend and attach a couple of streams to is
	auto backend = boost::make_shared<sinks::wtext_ostream_backend>();
	backend->add_stream(boost::shared_ptr<std::wostream>(&std::wcout, boost::null_deleter()));
	backend->add_stream(wfout);

	// Enable auto-flushing after each log record written
	backend->auto_flush(true);

	// Wrap it into the front end and register in the core
	typedef sinks::synchronous_sink<sinks::wtext_ostream_backend> sink_t;
	boost::shared_ptr<sink_t> sink(new sink_t(backend));

	// Set formatter
	sink->set_formatter(expr::stream
		<< std::hex << std::setw(8) << std::setfill(L'0') << line_id << std::dec << std::setfill(L' ')
		<< L": <" << severity << L">\t"
		<< L"(" << timestamp << L") "
		<< expr::wmessage
	);

	core->add_sink(sink);

	// Add attributes
	logging::add_common_attributes();
	core->add_global_attribute("Scope", attrs::named_scope());
	core->add_global_attribute("TimeStamp", attrs::local_clock());

	//core->set_filter
	//(
	//	logging::trivial::severity >= logging::trivial::info
	//);
}

int main()
{
	init();

	// Wide character logging
	// http://www.boost.org/doc/libs/1_66_0/libs/log/doc/html/log/tutorial/wide_char.html
	src::wseverity_logger<severity_level> lg;

	BOOST_LOG_SEV(lg, trace) << L"トレース・メッセージ";
	BOOST_LOG_SEV(lg, debug) << L"デバッグ・メッセージ";
	BOOST_LOG_SEV(lg, info) << L"情報メッセージ";
	BOOST_LOG_SEV(lg, warning) << L"警告メッセージ";
	BOOST_LOG_SEV(lg, error) << L"エラー・メッセージ";
	BOOST_LOG_SEV(lg, fatal) << L"致命的なエラー・メッセージ";

	return 0;
}
