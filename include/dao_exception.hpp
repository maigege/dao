/*
 * dao_exception.hpp
 *
 *  Created on: May 28, 2012
 *      Author: Administrator
 */

#ifndef __DAO_EXCEPTION_HPP__
#define __DAO_EXCEPTION_HPP__

#include <string>
#include <stdexcept>

using namespace std;

#define GEN_EXCEPTION(err_code, user_msg) \
{\
	string msg(__FILE__);\
	msg += ": ";\
	msg += __FUNCTION__;\
	msg += ": ";\
	msg += user_msg;\
	DaoDiagnostic diag(err_code, msg);\
	throw DaoError(diag);\
}

#define GEN_ODBC_EXCEPTION(odbc_error, err_code) \
{\
	string odbc_msg("odbcpp error-");\
	odbc_msg += odbc_error.what();\
	GEN_EXCEPTION(DaoError::ODBC_ERROR, odbc_msg);\
}

class DaoDiagnostic {
public:
	DaoDiagnostic(int err_code, const string& message);

	string getMsg(void) { return err_msg; }

public:
	string err_msg;
};

class DaoError: public runtime_error {
public:
	enum DaoErrCode { VALUE_NOT_INITIALISED, VALUE_NOT_BOUND, VALUE_BOUND_ERROR, ODBC_ERROR, DAO_ERROR_MAX};

	DaoError(DaoDiagnostic& diag): runtime_error(diag.getMsg() ), dao_diag(diag){}

private:
	DaoDiagnostic dao_diag;
};

#endif /* __DAO_EXCEPTION_HPP__ */
