/*
 Copyright (C) 2006 Eric Ehlers
 Copyright (C) 2006 Marco Marchioro--StatPro Italia
 Copyright (C) 2006 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file
    \brief date utility functions defined in date.xml

    The functions implemented in this file are invoked in the Addins from code
    autogenerated by srcgen.py.
*/

#ifndef qla_date_hpp
#define qla_date_hpp

#include <oh/objhandler.hpp>
#include <qla/clientutils.hpp>
#include <ql/calendar.hpp>

namespace QuantLibAddin {

/*! \group date
    date utility functions for QuantLibAddin
*/

    /*! Returns the holidays between two dates
        according to a given holiday calendar */
    std::vector<QuantLib::Date> qlHolidayList(
            const std::string &calendarID,
            const long &lFromDate,
            const long &lToDate,
            bool includeWeekEnds);

    //! return the advanced date over a given calendar
    QuantLib::Date qlAdvanceCalendar(
            const long &lStartDate,
            const long &n,
            const std::string &timeUnitsID,
            const std::string &calendarID,
            const std::string &conventionID);    


    //! whether or not the given date is an IMM date
    inline bool qlIsIMMdate(const long& ld) {
        QuantLib::Date d=createQLDate(ld);
        return QuantLib::Date::isIMMdate(d);
    }

    //! next IMM date following (or equal to) the given date
    /*! returns the 1st delivery date for next contract listed in the
        International Money Market section of the Chicago Mercantile
        Exchange.

        \warning The result date is following or equal to the
                    original date.
    */
    inline QuantLib::Date qlNextIMMdate(const long& ld) {
        QuantLib::Date d=createQLDate(ld);
        return QuantLib::Date::nextIMMdate(d);
    }

    /*! return the year fraction with respect to a given day-counter
        convention */
    double qlYearFraction(
        const std::string &bDayConvID,
        const long &lStartDate,
        const long &lEndDate,
        const long &lRefStartDate,
        const long &lRefEndDate);    

    /*! return the day count with respect to a given day-counter
        convention */
    double qlDayCount(
        const std::string &bDayConvID,
        const long &lStartDate,
        const long &lEndDate);    

    //! return the evaluation date
    QuantLib::Date qlEvaluationDate();

    //! set the evaluation date
    QuantLib::Date qlSetEvaluationDate(const long &evalDate);

}

#endif
