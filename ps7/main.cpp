// Copyright Jeongjae Han   [UMASS LOWELL] [06/19/2022]
#include <iostream>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_duration;
using boost::gregorian::date_period;
using boost::posix_time::time_duration;
using boost::posix_time::ptime;
using std::string;

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cout << "./ps7 [device#.log. " << std::endl;
        exit(1);
    }

    int success = 0;
    int numBoot = 0;
    int counter1 = 1;

    string input(argv[1]);
    string output = input + ".rpt";
    string bDate = "", eDate = "", cDate = "", report = "", boot = "";

    int h = 0, m = 0, s = 0;

    ptime start, end;

    date f_d, s_d;

    time_duration timeDiff;

    boost::regex startReg("([0-9]+)-([0-9]+)-([0-9]+) ([0-9]+):([0-9]+):([0-9]+): \\(log.c.166\\) server started.*"); //NOLINT

    boost::regex endReg("([0-9]+)-([0-9]+)-([0-9]+) ([0-9]+):([0-9]+):([0-9]+).([0-9]+):INFO:oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*"); //NOLINT

    boost::smatch smat;

    string str;
    std::ifstream file(input.c_str());

    bool fBoot = false;

    if (file.is_open()) {
        while (getline(file, str)) {
            bDate.clear();
            eDate.clear();

            if (boost::regex_search(str, smat, startReg)) {
                cDate = smat[1] + "-" + smat[2] + "-" + smat[3];
                bDate = cDate + " " + smat[4] + ":" + smat[5] + ":" + smat[6];

                f_d = date(from_simple_string(cDate));

                h = std::stoi(smat[4]);
                m = std::stoi(smat[5]);
                s = std::stoi(smat[6]);

                start = ptime(f_d, time_duration(h, m, s));

                if (fBoot == true) {
                    boot += "Booting Failed \n";
                }

                boot += "Booting\n" + std::to_string(counter1) + "(" +\
                    input + "):" + bDate + "Starting...\n";
                numBoot++;
                fBoot = true;
                }
            if (boost::regex_match(str, smat, endReg)) {
                cDate = smat[1] + "-" + smat[2] + "-" + smat[3];
                eDate = cDate + " " + smat[4] + ":" + smat[5] + ":" + smat[6];

                s_d = date(from_simple_string(cDate));

                h = std::stoi(smat[4]);
                m = std::stoi(smat[5]);
                s = std::stoi(smat[6]);

                end = ptime(s_d, time_duration(h, m, s));

                boot += std::to_string(counter1) + "(" +\
                    input + "):" + eDate + "Boot complete\n";

                auto bootEqu = [&] () {return (end-start);};
                timeDiff = bootEqu();

                boot += "Booting time: ";
                boot += std::to_string(timeDiff.total_milliseconds()) + "ms \n";

                success++;
                fBoot = false;
            }
            counter1++;
        }
        file.close();
    }

    report += "Boot Report\n Intouch logfile: " + input + "\n" +\
         "Lines scanned: " + std::to_string(counter1) + "\n\n";

    report += "Device boot count: initiated = " + std::to_string(numBoot) +\
        ", completed: " + std::to_string(success) + "\n\n";

    report += boot;

    std::ofstream out(output.c_str());
    out << report;
    out.close();

    return 0;
}
