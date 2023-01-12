// compile with 
// g++ stdin_boost.cpp -lboost_regex

// regex_match example
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

#include <boost/regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

//using namespace boost;
// date get_date
int main(int argc, char** argv)
{
	std::string s;
	std::regex start, end;
	std::string starttime;
	std::string endtime;
	std::smatch smStart;
	std::smatch smEnd;
	start = "[\\d][\\d][\\d][\\d]-[\\d][\\d]-[\\d][\\d][\\s][\\d][\\d]:[\\d][\\d]:[\\d][\\d]:[\\s][(]log.c.[1 - 6][1 - 6][1 - 6][)][\\s]server[\\s]started[\\s]";
	end = "[\\d][\\d][\\d][\\d]-[\\d][\\d]-[\\d][\\d][\\s][\\d][\\d]:[\\d][\\d]:[\\d][\\d].[\\d][\\d][\\d]:INFO:oejs.AbstractConnector:Started[\\s]SelectChannelConnector@[\\d].[\\d].[\\d].[\\d]:[\\d][\\d][\\d][\\d]";
	std::ifstream input;
	std::string inFile = argv[1];
	input.open(inFile);
	std::ofstream output;
	std::string outFile = inFile + ".rpt";
	output.open(outFile);
	bool key = 0;
	boost::posix_time::ptime startTime, endTime;
	boost::posix_time::time_duration runTime;

//	boost::posix_time::ptime ptime startTime, endTime;
//	boost::posix_time::time_duration date durationrunTime;
	//keep picking up until you get the server started
		for (int i = 1; getline(input, s); i++) {
			//this will search for when s and start are the same, and then increment sm (int) by 1.
			std::regex_search(s, smStart, start);

			//if the start gets found..
			if (smStart.size() > 0) {

				if (key == 1) {
				output << i << " (log.c.166) server started: " << starttime << " FAILED" << std::endl;
				}
				key = 1;

				//std::cout << "Picked up server start!" << std::endl;
				//datetime is now the date-time!
				starttime = s.substr(0, 19);
				startTime = boost::posix_time::time_from_string(starttime);
				//std::cout << datetime << std::endl;
				//advance to the next line
			}

			std::regex_search(s, smEnd, end);
			if (smEnd.size() > 0)
			{
				if (key == 0) {
				output << i << " (log.c.166) server started: " << starttime << " FAILED" << std::endl;
				continue;
				}
				key = 0;
				//std::cout << "Picked up server end!" << std::endl;
				endtime = s.substr(0, 19);
				endTime = boost::posix_time::time_from_string(endtime);
				//get the time difference
				runTime = endTime - startTime;
			output << i  << " (log.c.166) server started: " << starttime << " Succeeded and ran for " << runTime.total_milliseconds() << "ms" << std::endl;
			}
			if (s.back() == EOF) {
				output << "failed!" << std::endl;
				continue;
			}
		}

	input.close();
	output.close();
	return 0;
}
