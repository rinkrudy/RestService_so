#include "../../stdafx.h"
#include "ZoneAllDel.h"

ZoneAllDel::ZoneAllDel()
{
}


ZoneAllDel::~ZoneAllDel()
{
}

void ZoneAllDel::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/zone/ZoneAllDel;get";
}

string ZoneAllDel::SetStructToJson(void* struct_Param)
{
    string null;
    return null;
}