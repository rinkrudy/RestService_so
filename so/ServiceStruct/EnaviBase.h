#pragma once

#include "EnaviDBStruct.h"
#include<string>
#include "EnaviDBService.h"

using namespace web;
using namespace std;

#define STRING(s)	#s
#define FIELD_S(fld)	strcpy(p->fld, root->at(U(STRING(fld))).as_string().c_str()) 
#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
#define FIELD_D(fld)	p->fld = root->at(U(STRING(fld))).as_double() //double

//�߰�
#define SETJSON_I(fld)	root[STRING(fld)] = json::value::number(p->fld) //int
#define SETJSON_S(fld)	root[STRING(fld)] = json::value::string(p->fld) //string
#define SETJSON_B(fld)  root[STRING(fld)] = json::value::boolean(p->fld) // boolean
#define SETJSON_C(fld) 	root[STRING(fld)] = json::value::string(&(p->fld));
#define AFIELD_S(fld)	array[i].at(U(STRING(fld))).is_null() ? strcpy(pArray->fld, " ") : strcpy(pArray->fld,array[i].at(U(STRING(fld))).as_string().c_str()) //string
#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
#define AFIELD_D(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_double() //double
#define AFIELD_L(fld)	pArray->fld = (long)array[i].at(U(STRING(fld))).as_integer() //Long
#define AFIELD_C(fld)	((array[i].at(U(STRING(fld))).as_string()).empty() == true) ? pArray->fld = ' ' :  pArray->fld = (array[i].at(U(STRING(fld))).as_string()).at(0)
#define TEMPFIELD_S(fld)  	strcpy(pArray->fld,array[i].at(U(STRING(fld))).as_string().c_str())

#define AFIELD_B(fld)	(array[i].at(U(STRING(fld))).as_bool() == false) ?  pArray->fld = false : pArray->fld=true //int
//
#define VSETJSON_S(fld)		(dstArray[i])[STRING(fld)] = json::value::string(info.fld)
#define VSETJSON_I(fld)		(dstArray[i])[STRING(fld)] = json::value::number(info.fld)
#define VSETJSON_B(fld)		(dstArray[i])[STRING(fld)] = json::value::boolean(info.fld)
#define VSETJSON_C(fld)		(dstArray[i])[STRING(fld)] = json::value::string(&(info.fld))


#define VFIELD_S(fld)	(srcArray[i]).at(U(STRING(fld))).is_null() ? strcpy(info.fld, " ") : strcpy(info.fld, (srcArray[i]).at(U(STRING(fld))).as_string().c_str()) //string
#define VFIELD_I(fld)	info.fld = (srcArray[i]).at(U(STRING(fld))).as_integer();
#define VFIELD_D(fld)	info.fld = (srcArray[i]).at(U(STRING(fld))).as_double();
#define VFIELD_L(fld)	info.fld = (long)(srcArray[i]).at(U(STRING(fld))).as_integer();
#define VFIELD_C(fld)	((srcArray[i].at(U(STRING(fld))).as_string()).empty() == true) ? info.fld = ' ' :  info.fld = (srcArray[i].at(U(STRING(fld))).as_string()).at(0)
#define VFIELD_B(fld)	(srcArray[i].at(U(STRING(fld))).as_bool() == false) ?  info.fld = false : info.fld = true



class EnaviBase
{
protected:
	string m_arrRestUrl[(int)Service::E_RestType::eRest_Max];

public:
	EnaviBase();
	virtual ~EnaviBase();

	virtual void Init() = 0;

	virtual void * GetStruct(json::value* root);

	virtual string SetStructToJson(void* struct_Param);

	const char *GetDataAsString(json::value *root);

	void * SetStructInfo(json::value* root);

	string GetSerivceUrl(Service::E_RestType eRestType);

};

