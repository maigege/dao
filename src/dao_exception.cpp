/*
 * dao_exception.cpp
 *
 *  Created on: May 28, 2012
 *      Author: Administrator
 */
#include "../include/dao_exception.hpp"

DaoDiagnostic::DaoDiagnostic(int err_code, const string& message)
{
	err_msg = message;

	err_msg += ": ";

	switch (err_code) {
	case DaoError::VALUE_NOT_INITIALISED :
		err_msg += "Value isn't initialised yet.";
		break;

	case DaoError::VALUE_NOT_BOUND :
		err_msg += "Value isn't bound yet.";
		break;

	case DaoError::VALUE_BOUND_ERROR :
		err_msg += "Value was bound error.";
		break;

	case DaoError::ODBC_ERROR :
		err_msg += "odbc error occured, check odbcpp exception.";
		break;

	default:
		break;
	}
}
