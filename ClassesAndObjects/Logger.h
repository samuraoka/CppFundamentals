#pragma once
#include <boost/log/sources/severity_logger.hpp>

namespace kasumi
{
	enum severity_level
	{
		trace,
		debug,
		info,
		warning,
		error,
		fatal
	};

	class Logger
	{
	public:
		static boost::log::sources::wseverity_logger<severity_level> &getLogger();

	private:
		Logger();
		~Logger();
		static Logger singleton;
		boost::log::sources::wseverity_logger<severity_level> logger;
	};
}
