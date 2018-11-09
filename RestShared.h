#include"stdafx.h"
#include "RestCallClient.h"

extern "C" void * RestClient() {
    RestCallClient * restClient = new RestCallClient();
    return (void *)restClient;
}

