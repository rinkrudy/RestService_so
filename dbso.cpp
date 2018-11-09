#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include "./so/ServiceStruct/EnaviDBStruct.h"

typedef void (*CreateRestService)();
typedef void (*ReleaseRestService)();
typedef void *(*SelectData)(int,const char *);
typedef void *(*UpdateData)(int,void *);
typedef void *(*DeleteData)(int,void *);

int main(void)
{
	char *pname = "/usr/lib64/librestService.so";

	void *hLib = dlopen(pname, RTLD_LAZY | RTLD_GLOBAL);
	if (hLib == NULL) {
		printf("dlopen error %d\n", errno);
		return -1;
	}

	printf("dlopen success %p\n", hLib);

	CreateRestService funcCreate = (CreateRestService)dlsym(hLib, "CreateRestService");
	if (funcCreate == NULL) {
		printf("CreateRestService function pointer null\n");
		dlclose(hLib);
		return -1;
	}

	funcCreate();	
	printf("CreateRestService done\n");

	DB_Catalogue *data = (DB_Catalogue *)malloc(sizeof(DB_Catalogue));
	memset(data, 0, sizeof(DB_Catalogue));
	
	// select function
	SelectData funcSelect = (SelectData)dlsym(hLib, "SelectData");
	if (funcSelect == NULL) 
	{
		printf("SelectData function pointer null\n");
	} 
	else 
	{
		printf("SelectData function pointer %p\n", funcSelect);

		// select
		void *pResult = funcSelect(0, "zone=A1&productversion=KR/2017-NTM-001&enctype=S-101&encrypt=false&same=true");
		if (pResult == NULL) 
		{
			printf("SelectData return null\n");
		} 
		else 
		{
			printf("SelectData return %p\n", pResult);


			DB_Catalogue *s = (DB_Catalogue *)pResult;
			int rows = malloc_usable_size(pResult)/sizeof(DB_Catalogue);
			printf("rows: %d\n", rows);
			puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			puts("  catalogid idIdentifier idDate exchangecatalogname category cataloguepath fileuri filedmzuri filename zone  productversion enctype productdate filesize encrypt hash");
			puts("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			for (int i=0; i<rows; i++) {
				printf("%d) %d, %s, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %s, %s\n", 
					i, s->catalogid, s->idIdentifier, s->idEditionnumber, s->idDate, s->exchangecatalogname, 
					s->category, s->cataloguepath, s->fileuri, s->filedmzuri, s->filename, s->zone, 
					s->productversion, s->enctype, s->productversion, s->filesize, s->encrypt, s->hash);
				if (s->catalogid == 98)
					memcpy(data, s, sizeof(DB_Catalogue));
				s++;
			}
		}
	}

	// update
	UpdateData funcUpdate = (UpdateData)dlsym(hLib, "UpdateData");
	if (funcUpdate == NULL) {
		printf("UpdateData function pointer null\n");
	}
	else 
	{
		printf("UpdateData function pointer %p\n", funcUpdate);

		snprintf(data->fileuri, sizeof(data->fileuri)-1, "up-%ld", time(0));
		void *pResult = funcUpdate(0, (void *)data);
		if (pResult == NULL) 
		{
			printf("UpdateData return null\n");
		}
		else
		{
			printf("UpdateData return %p\n", pResult);

			RestApiInfo *s = (RestApiInfo *)pResult;
			printf("update result: %d, %s, %d\n", s->success, s->msg, s->data);
		}
	}

	// delete
	DeleteData funcDelete = (DeleteData)dlsym(hLib, "DeleteData");
	if (funcDelete == NULL) {
		printf("DeleteData function pointer null\n");
	}
	else 
	{
		printf("DeleteData function pointer %p\n", funcDelete);

		memset(data, 0, sizeof(DB_Catalogue));

		data->catalogid=109;
		void *pResult = funcDelete(0, (void *)data);
		if (pResult == NULL) 
		{
			printf("DeleteData return null\n");
		}
		else
		{
			printf("DeleteData return %p\n", pResult);
			RestApiInfo *s = (RestApiInfo *)pResult;
			printf("delete result: %d, %s, %d\n", s->success, s->msg, s->data);
		}
	}

	ReleaseRestService funcRelease = (ReleaseRestService)dlsym(hLib, "ReleaseRestService");
	if (funcRelease == NULL) 
	{
		printf("ReleaseRestService function pointer null\n");
	} 
	else 
	{
		funcRelease();
		printf("ReleaseRestService done\n");
	}

	if (hLib)
		dlclose(hLib);
	
	printf("dlclose success\n");
	return 0;
}

