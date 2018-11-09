#include "../../stdafx.h"
#include "Catalogue.h"


Catalogue::Catalogue()
{
}


Catalogue::~Catalogue()
{
}

void Catalogue::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/catalogue/Catalogue;get";
	m_arrRestUrl[(int)Service::E_RestType::eInsert] = "sv40/catalogue/Catalogue;post";
	m_arrRestUrl[(int)Service::E_RestType::eUpdate] = "sv40/catalogue/Catalogue;put";
	m_arrRestUrl[(int)Service::E_RestType::eDelete] = "sv40/catalogue/Catalogue;delete";
}

string Catalogue::SetStructToJson(void* struct_Param)
{
	DB_Catalogue *p = (DB_Catalogue *)struct_Param;

	web::json::value root;

	SETJSON_I(catalogid);
	SETJSON_S(idIdentifier);
	SETJSON_I(idEditionnumber);
	SETJSON_S(idDate);
	SETJSON_S(exchangecatalogname);
	SETJSON_S(category);
	SETJSON_S(cataloguepath);
	SETJSON_S(fileuri);
	SETJSON_S(filedmzuri);
	SETJSON_S(filename);
	SETJSON_S(zone);
	SETJSON_S(productversion);
	SETJSON_S(enctype);
	SETJSON_S(productdate);
	SETJSON_I(filesize);
	SETJSON_S(encrypt);
	SETJSON_S(hash);	


	return root.serialize();
}
//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * Catalogue::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_Catalogue *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_Catalogue *)malloc(sizeof(DB_Catalogue)*iArrayCount);
		memset(p, 0, sizeof(DB_Catalogue));
		DB_Catalogue *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_I(catalogid);
			AFIELD_S(idIdentifier);
			AFIELD_I(idEditionnumber);
			AFIELD_S(idDate);
			AFIELD_S(exchangecatalogname);
			AFIELD_S(category);
			AFIELD_S(cataloguepath);
			AFIELD_S(fileuri);
			AFIELD_S(filedmzuri);
			AFIELD_S(filename);
			AFIELD_S(zone);
			AFIELD_S(productversion);
			AFIELD_S(encrypt);
			AFIELD_S(enctype);
			AFIELD_S(productdate);
			AFIELD_I(filesize);
			AFIELD_S(hash);

			pArray++;
		}
	}
	
	return p;
}
